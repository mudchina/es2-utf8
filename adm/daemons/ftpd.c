#pragma save_binary

/*
 * ftpd.c:
 *
 *   This is an implementation of an ftpd daemon written in LPC using the
 *   MudOS socket efunctions.  This version of ftpd will communicate with
 *   standard ftp clients such as the 'ftp' program found on most all UNIX
 *   systems.  This version supports _both_ ASCII _and_ BINARY transfers.
 *
 *   Edit /include/net/ftpdconf.h and /include/net/ftpdsupp.h to configure
 *   ftpd for your particular mudlib.
 *
 *   Note: This object runs with ROOT_UID and depends on the correctness
 *		 of the valid_read() and valid_write() functions in the master
 *		 mudlib object.
 *		 If these two functions aren't accurate, then this object (ftpd.c)
 *		 will allow anyone to harm your mudlib.
 *
 *	 valid_read is called as follows:
 *
 *		 MASTER_OB->valid_read(filename, user, "read_file" )
 *
 *	   It should return '1' only if user 'user' has permission to
 *	   read the file 'filename'.
 *
 *	 valid_write is called as follows:
 *
 *		 MASTER_OB->valid_write(filename, user, "write_file")
 *
 *	  It should return 1 only if user 'user' has permission to write
 *	  (or remove) the file 'filename'.
 */

/*
 * Originaly written by Pinkfish@Discworld
 *
 * 93-08-22  Bannor@newmoon
 *		   - Added DEBUG and LOGGING flags and #ifdef's
 *		   - Fixed a problem with sending files larger then 1k.
 *		   - Added support for events.
 *		   - Added support for finger ftp.
 *		   - Fixed security problems that allowed anyone to read/write
 *			 to any directory.
 *		   - Improved readability (well, I think so anyway)
 *		   - Removed all those silly "bing", "bits" and "blue"
 *			 variables.
 *
 * 93-11-21 Truilkan@Gestalt
 *  - modified to work on tmi-2 (interface with tmi-2 security etc)
 *	the motivation behind this port was to hopefully lessen the
 *	number of people asking me how to make the ftpd.c written in C
 *	work (seemingly only C/UNIX gurus and otherwise persistent
 *	people could make it work).  This LPC version of ftpd is also
 *	easier for LPC coders to customize to fix a particular mudlib's
 *	security code (directory access permissions etc).  For use with
 *	MudOS version 0.9.18.20 or later.
 *
 *  TODO: the return code from each socket_write() should be checked and
 *		appropriately handled.  Presently only the data xfer socket_write()
 *		calls are checking the return type.  This is probably enough
 *		to ensure that ftpd.c works correctly most of the time but in
 *		order to be robust, the additional checking should be done.
 *		In addition, the socket_write() return code should be checked
 *		for EECALLBACK as well as EEWOULDBLOCK.  See the socket_write
 *		function in the MudOS driver file socket_efuns.c for more
 *		information on the possible return codes of the socket_write() efun.
 *
 * 93-11-22 Truilkan@Gestalt
 * o Bumped version number to 2.0
 * o Fixed check_connections() so that it actually does timeout idle ftp users.
 * o Added code to restrict number of users.  See FTPD_MAX_USERS in ftpdconf.h.
 *
 * 93-11-28 Inspiral@Tabor
 * o Bumped version number to 3.0
 * o Added another field to the mapping, which will hold the ftp user's
 *   connection object.  This allows master.c to work properly even if
 *   the wizard is not currently logged into the mud.
 * o Above change meant altering check_password() in ftpd.h
 * o Above change also meant adding disable_status_check() in connection.c
 *   This needs to be added: void disable_status_check() {
 *								remove_call_out( "check_status" );
 *						   }
 * o Added code for support of multi-worded passwords (Thanks, Domini@Ultimate)
 * o Removed fix in Version 2 which used reload_object() in check_password()
 * o Cleaned up some redundant code.
 * o Added socket_address() calls in login/logout logs
 * o Altered LOG_FILE define to specify log destination.
 * o Appended output of "ls" and "dir" commands with a "/" on directories.
 * o Added LOG_TIME define for those who like to see what time things occur.
 *
 * 93-12-15 Inspiral@Tabor
 * o Generalized and macro'd the socket_address() calls,
 *	 and added ip site resolve()
 *
 * 93-12-17 Inspiral@Tabor
 * o Added support for anonymous ftp logins ... Read the file
 *	 "/include/net/anon_ftp.doc" for instructions on installing it.
 * o Found/fixed a bug with "cd", which allowed you to cd into a file.
 *
 * 94-01-11 Inspiral@Tabor
 * o Bumped version number to 4.0
 * o Incorporated fixes for valid_read/write when user not also
 *	 logged into the mud (Beek@DistortionII)
 * o Above fix allowed removal of LINK field from connection mapping,
 *	 as well as the disable_status_check() function in connection.c
 * o Added support for BINARY mode file transfers (0.9.18.20+)
 * o Re-installed reload_object() support in check_password()
 * o Added LOGIN_MSG support at login time.
 *
 * 94.04.08 - Robocoder@TMI-2
 * o Bumprev'd to 4.1
 * o Added 'DELE' command.
 * o Added file locking protection for 'APPE', 'STOR' and 'DELE'.
 * o Corrected some typos (and NorthAm'd the spelling of "unrecognised")
 * o Some minor formatting changes.
 *
 * 94.04.09 - Robocoder@TMI-2
 * o Added #define check for FLOCK_D for muds that don't support file locking
 * o Added flock_wrapper() to give flock daemon better logging info
 *
 * 94.04.10 - Robocoder@TMI-2
 * o Fixed logout() to not close the connection when it receives another
 *   'USER' command and is already logged in
 *
 * 94.04.25 - Robocoder@TMI-2
 * o Added logout() calls in various places to solve problem of a ftp
 *   session closing immediately after connecting (for a new user, reusing
 *   a socket mapping not properly cleaned up)
 * o Slight change to resolve_callback(), cause I don't like seeing
 *   "... connected from 0" or "... logged out from 0"
 *
 * 94.05.11 - Robocoder@TMI-2
 * o Fixed query_connections() to only return the non-zero subset of the
 *   "list" array (pre-allocat()'d) (see usage by TMI's "/cmds/std/_who.c")
 * o Fixed file unlocking when download aborted.
 *
 * 94.05.19 - Robocoder@TMI-2
 * o Bumprev'd to 4.2
 * o Added sitecheck support (TMI specific); configurable
 * o Made FLOCK support explicit in ftpdconf.h
 * o Fixed check_password() to not set uid of connection object to "Root"
 * o Added config option for varying read & write level access
 * o Added LOG_NO_CONNECT config option (for more evil admin logging)
 * o Moved "code" in header files to ftpdsupp.h...one more file to modify
 *   for configuring lpc_ftpd to your mudlib *sigh*
 *
 * 94.05.21 - Robocoder@TMI-2
 * o Bumprev'd to 5.0 (Warning: possible compat busters)
 * o Finished code for RESTRICTED_READ/RESTRICTED_WRITE; necessitated adding
 *   a strncmp function (which may or may not already be a simul_efun with
 *   a given mudlib)
 * o Cleaned up get_path() a bit...since HOME_DIR()--macro for TMI's
 *   user_path()--returns leading and trailing slashes--should fix logs
 *   and file locking quirks; also should now handle "./.." correctly
 * o "stor" checks destination is not a directory
 * o "appe" checks destination already exists (and is not a directory)
 * o Added LONG_LS to ftpdconf.h, to change non-columnar ls() to a long
 *   "ls" (timestamp & filesize)
 * o Added catch()'s around rm(), read_buffer(), and write_buffer calls where
 *   account level file permissons may not permit
 * o Added "stou" command (store unique)
 * o Added config option to ftpdconf.h for FTP_USERS
 * o Changed some of the error messages slightly.
 * o Added lose_connection() since lose_user() decrements counter of logged
 *   in users (which is inappropriate for data connections)
 * o Now closes sockets before removing it from mapping
 * o For the sake of completeness, added a few commands which are recognized
 *   but not implemented.
 * o Added "site", "mkd", and "rmd" commands
 * o Implemented missing part of "mdtm" command
 * o Moved some #includes after variable definitions in order to compile
 *
 * 94.05.21 - Robocoder@TMI-2
 * o Bumprev'd to 5.1
 * o Featuritus attack continues...coded "rnfr", "rnto", and "help" commands
 * o cmdtab for above "help" derived from Berkeley source (ftpcmd.y  5.23)
 * o Added CHECK_NARGS() to ftpdsupp.h, and used together with command[1]
 *   (as opposed to tmp) to get a more consistent reply format
 * o If user entered "ls -l" and client translated this to "nlist -l",
 *   it's translated to "list ." as user intended; idea from Berkeley
 *   source (ftpd.c  5.60)
 * o Removed trailing text from #endif's because it was getting cluttered
 *   in some sections; removing all instances at least keeps it uniform
 * o Removed the event() support (non-MudOS)...which was #if 0'd out anyways
 * o "nlst" also returns subdirs (1 level deeper) rather than appending
 *   '/' on dir names
 * o "list" further expanded (hopefully, it doesn't max eval too often);
 *   here the trailing '/' is retained; also LONG_LS config option removed
 * o Cleaning up most of the string addition (of 3 or more strings) to use
 *   sprintf() (eg in socket_write() calls)
 * o Macro'd a couple of recurring socket_write() calls
 * o Now logs email address entered by "anonymous" ftp logins
 *
 * 94.05.23 - Robocoder@TMI-2
 * o Following 4BSD, server restricts anonymous FTP to FTP_DIR; to remove
 *   restriction, set FTP_DIR to "/"
 * o Code wasn't updating LAST_DATA on data connections (only on parent
 *   control connection)--I believe it was possible for check_connections()
 *   to abort transfers in progress...I don't recall if it was broken to begin
 *   with or if I broke it in the midst of heavy hacking
 *
 * 94.06.17 - Robocoder@Delta.City
 * o Bumprev'd to 5.2
 * o Finally tested the "new" stuff...fixing typos, etc
 * o Rewrote check_connections() to check control connections first (for
 *   idle users) and then to check data connections for orphaned links
 * o Went back to "original" nlist behaviour (shorter) because it was
 *   max eval'ing, and driver appeared to close the connection long before
 *   the columnar ls() finished
 * o Return values from socket_write() are checked in in_write_callback()
 * o Removed CHECK_NARGS...we'll rely on client to check the number of
 *   of parameters
 *
 * 94.06.29 - Robocoder@Delta.City
 * Bumprev'd to 5.3
 * o in_write_callback() - lose_user() is called if !EECALLBACK, since it's
 *   the only case we're concerned with
 * o in_close_callback() - removed logging here since this function is
 *   apparently only called if connection is closed before it gets to
 *   the login prompt
 *
 * 94.07.04 Rust@TMI-2
 * o added a remove() to check to make sure there are no users before
 *   destructing
 *
 * 94.07.25 Robocoder
 * o added admin check to remove() to permit it  =)
 * o fixed Index out of bounds error when using "cdup"
 * o added code to in_close_callback() to handle socket closing
 *   unexpectedly
 *
 * 94.08.15 Robocoder@TMI-2
 * o Bumprev'd to 5.4
 * o Added Chuck's patches for .message file support, see MESSAGE_FILES
 *   define in ftpdconf.h; so when people cd, cwd, cdup...the .message file
 *   is output.
 * o Changed login message for "anonymous" users slightly.
 *
 * 94.11.27 Robocoder@TMI-2
 * o Bumprev'd to 5.5
 * o Incorporated ideas from Marius@Garden's "ftpd 5.0", such as
 *   SITE IDLE, making ASCII "get" transfers more portable with ftp clients,
 *   and various peephole optimizations
 * o "nlst" output now also more portable with ftp clients to avoid the
 *   dreaded "<n> bare linefeeds received" message
 * o Added support for "site help" and "site time"
 *
 * 94.11.28 Robocoder@TMI-2
 * o Bumprev'd to 5.6
 * o For added robustness, added sizeof(command) checks in parse_com, as
 *   some ftp clients provide a "quote" command which doesn't validate
 *   syntax...in which case, someone can cause the daemon to die
 *
 * 94.11.28 Robocoder
 * o Bumprev'd to 5.7
 * o For added robustness, checks return value of get_dir()...there are
 *   cases where it returns 0 when account level permissions are messed up.
 *
 * 94.11.28 Leto@TMI-2
 * o Fixed a type error in query_connections() that caused the v20.x driver
 *   to barf on this file.
 *
 * 94.11.29 Robocoder
 * o Changed error message if ftp user attempts to get/retr or delete a
 *   non-existent file -- suggested by Leto
 *
 * 94.12.01 Robocoder
 * o Bumprev'd to 5.8
 * o data_write_callback() now more robust -- handles EECALLBACK from
 *   socket_write()
 * o Removed a useless check from resolve_callback() added sometime
 *   around 4.1
 *
 * 94.12.07 Robocoder
 * o fixed typos in ftpd.c and ftpdsupp.h...so #define'ing ANONYMOUS_FTP
 *   loads properly
 * o Ack...removed "\r\n" processing to nlst output...back to 
 *   some ftp clients complaining about bare linefeeds in ls output, to
 *   satisfy broken ftp clients that demand only "\n".
 *
 * 94.12.09 - Robocoder
 * o small optimization in ls() -- changed s1 = s1 + s2 -> s1 += s2
* o added some code for more robustness in in_read_callback()
 */

// #include <config.h> /* from tmi-2 */

#define FTPD_VERSION "5.8"

/*
-----------------------------------------------
	Variables
-----------------------------------------------
*/

mapping socket_info;
int our_socket;
mapping temp_map;
int number_of_users;

/*
 * edit ftpdconf.h & ftpdsupp.h to configure ftpd for your mudlib
 */
#include <net/ftpd.h>
#include <net/ftpdconf.h>
#include <net/ftpdsupp.h>

// #include <daemons.h>
#ifdef FILE_LOCKING
#include <flock.h>
#endif

/*
-----------------------------------------------
	Prototypes
-----------------------------------------------
*/
void setup_ftp( int port );
void finish_lookup( string host, string number );
void resolve_callback( string address, string resolved, int key );
string get_path( int fd, string str );
int strncmp(string str, string sub, int i);

int query_prevent_shadow() {
	return 1;
}

void lose_connection( int fd ) {
	socket_close( fd );
	map_delete( socket_info, fd );
}

void lose_user( int fd ) {
	socket_close( fd );
	map_delete( socket_info, fd );
	number_of_users--;
}

#ifdef FILE_LOCKING
static int flock_wrapper( string fname, int flag, int fd ) {
	int res;

	seteuid( socket_info[ fd ][ USER_NAME ] );
	res = file_lock( fname, flag );
	seteuid( getuid() );

	return res;
}
#endif

int strncmp(string str, string sub, int i) {
	int j;

	j = strlen(str);
	return (i > j ? strcmp(str, sub) : strcmp(str[0..i-1], sub));
}

int check_valid_read( string fname, int fd ) {
	int res;

	seteuid( socket_info[ fd ][ USER_NAME ] );
	res = (int) MASTER_OB -> valid_read(fname, this_object(), "read_file");
	seteuid( getuid() );

	/*
	 * This rather complicated looking section of code handles the
	 * various read levels available.  See ftpdconf.h for READ_LEVEL
	 * definitions of these flags.
	 */
#ifdef READ_LEVEL
#if READ_LEVEL == VALID_READ
	return res;
#elif READ_LEVEL == RESTRICTED_READ
	if (strncmp(fname, HOME_DIR( UNAME ), strlen(HOME_DIR( UNAME ))) == 0
#ifdef PUB_DIR
		  || strncmp(fname, PUB_DIR, strlen(PUB_DIR)) == 0
#endif
#ifdef FTP_DIR
		  || strncmp(fname, FTP_DIR, strlen(FTP_DIR)) == 0
#endif
#ifdef TMP_DIR
		  || strncmp(fname, TMP_DIR, strlen(TMP_DIR)) == 0
#endif
		  )
		return res;
	else
		return 0;
#elif READ_LEVEL == WRITE_LIMIT_READ
	return check_valid_write( fname, fd );
#else
	// default
	return res;
#endif
#else
	// default
	return res;
#endif
}

int check_valid_write( string fname, int fd ) {
	int res, l;

	seteuid( socket_info[ fd ][ USER_NAME ] );

	/*
	 * prevent non-admin users from removing .message files
	 */
#ifdef MESSAGE_FILES
//	if (!member_group(geteuid(), "admin") &&
//		Just disable removing .message via ftp. By Annihilator (01-19-95)
		if( (l = strlen(fname)) >= 9 && fname[l-9..l-1] == "/.message")
		return 0;
#endif

	res = (int) MASTER_OB -> valid_write(fname, this_object(), "write_file");
	seteuid( getuid() );

	/*
	 * This rather complicated looking section of code handles the
	 * various write levels available.  See ftpdconf.h for WRITE_LEVEL
	 * definitions of these flags.
	 */
#ifdef WRITE_LEVEL
#if WRITE_LEVEL == VALID_WRITE
	return res;
#elif WRITE_LEVEL == RESTRICTED_WRITE
	if (strncmp(fname, HOME_DIR( UNAME ), strlen(HOME_DIR( UNAME ))) == 0
#ifdef PUB_DIR
		  || strncmp(fname, PUB_DIR, strlen(PUB_DIR)) == 0
#endif
#ifdef FTP_DIR
		  || strncmp(fname, FTP_DIR, strlen(FTP_DIR)) == 0
#endif
#ifdef TMP_DIR
		  || strncmp(fname, TMP_DIR, strlen(TMP_DIR)) == 0
#endif
		  )
		return res;
	else
		return 0;
#elif WRITE_LEVEL == READ_ONLY
	return 0;
#else
	// default
	return res;
#endif
#else
	// default
	return res;
#endif
}

/* query_connections returns an array of users connected to ftpd */
mapping *query_connections() {
	mixed *vals;
	mapping *list;
	int count, i;

	vals = values( socket_info );
	list = allocate( sizeof( vals ) );
	count = sizeof( vals );

	while ( count-- )
		if (!undefinedp( (vals[count])[USER_NAME] ))
			list[i++] = ([
						   USER_NAME :
							 capitalize(( string )((vals[count])[USER_NAME])),
						   USER_SITE :
							 (string)((vals[count])[USER_SITE])
						]);

	return i ? list[0..i-1] : ({ });
}

void create()
{
	if ( !socket_info ) {
		socket_info = ([  ]);
		temp_map = ([ ]);
		number_of_users = 0;
		seteuid( ROOT_UID );
		call_out( "setup_ftp", 2, FTPD_PORT );
		call_out( "check_connections", 3 * 60 );
	}
}

static void setup_ftp( int port )
{
	our_socket = socket_create( STREAM, "in_read_callback",
								"in_close_callback" );
	if ( our_socket < 0 ) {
		TP( "Failed to create socket.\n" );
		return;
	}
	if ( socket_bind( our_socket, port ) <  0 ) {
		TP( "Failed to bind socket.\n" );
		socket_close( our_socket );
		return;
	}
	if ( socket_listen( our_socket, "in_listen_callback" ) <  0 ) {
		TP( "Failed to listen to socket.\n" );
		return;
	}
} /* setup_ftp() */

void in_write_callback( int fd ) {
	string address;
	int res;

	if ( undefinedp( socket_info[fd][CONNECTED] ) ) {
		if ( number_of_users > FTPD_MAX_USERS ) {
			res = socket_write( fd,
				  "530 Too many ftp connections active.  Try again later.\n");
			/*
			 * In these cases there isn't much more that can be done
			 */
			if (res != EECALLBACK)
				lose_user( fd );

			/*
			 * The following blocks the code in_read_callback &
			 * in_write_callback on this connection; we let the driver
			 * complete the send and let the daemon timeout the connection
			 */
			if (res == EECALLBACK) {
				socket_info[fd][CONNECTED] = 0;
			}
			return;
		}

		res = socket_write( fd,
			  sprintf( "220- %s FTP server (Version %s (MudOS/LPC)) ready.\n"
#ifdef ANONYMOUS_FTP
					   "220  Please login as yourself or 'anonymous'.\n",
#else
					   "220  Please login as yourself.\n",
#endif
					   THE_MUD_NAME, FTPD_VERSION ) );

		/*
		 * In these cases, assume user will receive above message
		 */
		if (res == EESUCCESS || res == EECALLBACK) {
			socket_info[fd][CONNECTED] = 1;
			if ((address = socket_address(fd)) &&
				  sscanf( address, "%s %*s", address )) {
				socket_info[fd][USER_SITE] = address;
				socket_info[fd][IDLE_SETTING] = FTPD_TIMEOUT;
				temp_map += ([ resolve( address, "resolve_callback" ) : fd ]);
			} else {
				socket_write( fd,
						"451 Error in server: socket_address() failed.\n"
						"221 Closing connection due to server error.\n");
				lose_user( fd );
			}
		} else if (res == EEWOULDBLOCK) {
			call_out( "in_write_callback", 2, fd );
		} else {
			lose_user( fd );
		}
	}
}

/*
 * called for each new ftp login connection
 */
void in_listen_callback( int fd )
{
	int new_fd;

	if ( ( new_fd =
		socket_accept( fd, "in_read_callback", "in_write_callback" ) ) < 0 )
		return;

	number_of_users++;
	socket_info[new_fd] = ([  ]);
	socket_info[new_fd][LAST_DATA] = time();
	in_write_callback( new_fd );
}

string ls( string path, int column, int fd ) {
	string *files;
	int i, j, s;
	mixed *xfiles;
	mixed *stats;
	string tmp, tmp2, creator, domain;

	/* if path is a directory get contents */
	if ( directory_exists( path ) ) {
		if ( path[ strlen( path ) - 1 ] == '/' )
			path += "*";
		else
			path += "/*";
	}

	/* begin narrow columnar "nlst" */
	if (column) {
		files = get_dir( path );

		/* can only happen if permissions are messed up at account level */
		if (!files)
			return "";

		files -= ({ ".", ".." });

		if (!(i = sizeof( files )))
			return "";

		/* no wild cards...must have been the exact pathname to a file */
		if (strsrch(path, '*') == -1 && strsrch(path, '?') == -1) {
			return files[0] + "\n";
		}

		/* remove globber at end of path, leave a trailing slash */
		j = strsrch(path, '/', -1);
		path = path[0..j];

		while ( i-- ) {
			/* scan next level down for files */
			tmp = sprintf("%s%s/", path, files[i]);
			if ( directory_exists( tmp ) ) {
				files[i] += "/";
			}
		}
		return implode( files, "\n" ) + "\n";
	}

	/* begin long "list" */
	xfiles = get_dir( path, -1 );
	if (!xfiles || !(s = sizeof( xfiles )))
		return "";

	files = allocate(s);

	// the Unix-like file permissions are mainly for effect...hopefully it
	// isn't too much, since anything more would likely be too cpu intensive
	// and cause it to max eval...
	creator = (string)MASTER_OB->creator_file(path);
	if (!creator)  creator = ROOT_UID;

	domain = (string)MASTER_OB->domain_file(path);
	if (!domain)  domain = ROOT_UID;

	i = strsrch(path, '/', -1);
	if (i >= 0)
		path = path[0..i];

	for (i = 0; i < s; i++) {
		/* process timestamp */
		tmp2 = ctime((xfiles[i])[2]); /* get last modified timestamp */
		if ((xfiles[i])[2] + SECS_IN_YEAR < time()) {
			/* MMM DD  YYYY */
			tmp = sprintf("%s  %s", tmp2[4..9], tmp2[20..23]);
		} else {
			/* MMM DD hh:mm */
			tmp = tmp2[4..15];
		}

		j = (xfiles[i])[1];   /* get filesize */
		if (j == -2) {
			/* directory */
			files[i] = sprintf("drwxrwsr-x  %12s  %12s	 <DIR>  %12s  %s/",
				  creator, domain, tmp, (xfiles[i])[0]);
		} else {
			/* file */
			stats = stat(path + (xfiles[i])[0]);
			files[i] = sprintf("-rw%crw-r--  %12s  %12s  %8d  %12s  %s",
				  stats[2] ? 'x' : '-', /* 'x' if loaded, else ' ' */
				  creator, domain, j, tmp, (xfiles[i])[0]);
		}
	}

	return sprintf( "%-#70s\n", implode( files, "\n" ) );
}

void data_write_callback( int fd ) {
	int pos, length, ret_val;
	buffer tmp;

	if ( socket_info[fd][TYPE] == DOWNLOAD )  return;

	tmp = allocate_buffer( 0 );
	pos = socket_info[ fd ][ POS ];
	length = ( (pos+BLOCK_SIZE) >= socket_info[ fd ][ LEN ] ) ?
			 ( socket_info[ fd ][ LEN ] - pos ) : BLOCK_SIZE;

#ifdef DEBUG_SEND
	TP( "Entering dwc(), pos: " + pos + " length should be: " + length + ".\n" );
#endif
	socket_info[ socket_info[ fd ][ PARENT_FD ] ][ LAST_DATA ] = time();

	if ( socket_info[ fd ][ TYPE ] == STRING ) {
#ifdef DEBUG_SEND
		TP( "type == STRING\n" );
#endif
		while ( (ret_val = socket_write( fd,
			  socket_info[fd][DATA][pos..(pos+BLOCK_SIZE-1)] )) >= 0 ) {
			if (ret_val == 0) {
#ifdef DEBUG_SEND
				TP( "Ret_val == 0, continuing\n" );
#endif
				continue;
			}

			pos += BLOCK_SIZE;

			if ( pos > socket_info[ fd ][ LEN ] ) {
				socket_write( socket_info[ fd ][ PARENT_FD ],
					  "226 Transfer complete.\n" );
				socket_close( fd );
				map_delete( socket_info[ socket_info[ fd ][ PARENT_FD ] ],
							DATA_FD );
#ifdef DEBUG_SEND
				TP( "dwc() complete, exiting.\n" );
#endif
				return;
			}
		}
	} else {
#ifdef DEBUG_SEND
		TP( "type is other then STRING\n" );
#endif
		if (catch( tmp = read_buffer( socket_info[ fd ][ DATA ], pos,
			  length ) ))
			socket_write( socket_info[ fd ][ PARENT_FD ],
				  "551 Error on input file.\n" );

		while ( ( ret_val = socket_write( fd, tmp ) ) >= 0 ) {
			if ( ret_val == 0 ) {
#ifdef DEBUG_SEND
				TP( "Ret_val == 0, continuing\n" );
#endif
				continue;
			}
#ifdef DEBUG_SEND
			TP( "sent from " + pos + " to " + ( pos + length ) + ".\n" );
			TP( "ret_val was: " + ret_val + ".\n" );
#endif

			pos += length;
			if ( pos >= socket_info[ fd ][ LEN ] ) {
				socket_write( socket_info[ fd ][ PARENT_FD ],
					  "226 Transfer complete.\n" );
				socket_close( fd );
				map_delete( socket_info[ socket_info[ fd ][ PARENT_FD ] ],
					  DATA_FD );
#ifdef DEBUG_SEND
				TP( "dwc() complete, exiting.\n" );
#endif
				return;
			}
			length = ( (pos+BLOCK_SIZE) >= socket_info[ fd ][ LEN ] ) ?
				  ( socket_info[ fd ][ LEN ] - pos ) : BLOCK_SIZE;
			tmp = allocate_buffer( 0 );
			tmp = read_buffer( socket_info[ fd ][ DATA ], pos, length );
		}
	}
#ifdef DEBUG_SEND
	TP( "ret_val was: " + ret_val + ".\n" );
	TP( "leaving dwc(), pos: " + pos + ".\n" );
#endif

	socket_info[ fd ][ POS ] = pos;
	if ( ret_val == EEWOULDBLOCK ) {
		/* it would block, so it's up to us to try again */
#ifdef DEBUG_SEND
		TP( "Adding call_out\n" );
#endif
		call_out( "data_write_callback", 2, fd );
	} else if (ret_val != EECALLBACK) {
		/* not going to be called again by driver */
		while ( remove_call_out( "data_write_callback" ) != -1 ) {
#ifdef DEBUG_SEND
			  TP( "Killing callout.\n" );
#endif
		}
	}
} /* data_write_callback() */


static void data_conn( int fd, string mess, string name, int type ) {
	int new_fd, ret, data_mode;
	string data_mode_name;
	mixed tmp;

	if ( type == STRING ||
		  ( type == FILE && UTYPE == STRING ) ) {
		data_mode_name = "ASCII";
		data_mode = STREAM;
		tmp = "";
	} else {
		data_mode_name = "BINARY";
		data_mode = STREAM_BINARY;
		tmp = allocate_buffer( 0 );
	}

	if ( socket_info[ fd ][ DATA_FD ] ) {
		socket_write( fd, "425 Can't open data connection.\n" );
		return;
	}
	new_fd = socket_create( data_mode, "data_read_callback",
		  "data_close_callback" );

	if ( new_fd < 0 ) {
		socket_write( fd, "425 Can't create data socket.\n" );
		return;
	}

	if ( ( ret = socket_connect( new_fd, sprintf("%s %d",
		  socket_info[ fd ][ DATA_ADDR ], socket_info[ fd ][ DATA_PORT ]),
		  "data_read_callback", "data_write_callback" ) ) < 0 ) {
		TP( "Error: " + socket_info[ fd ][ DATA_ADDR ] + " " +
			socket_info[ fd ][ DATA_PORT ] + "\n" );
		TP( socket_error( ret ) + "\n" );
		socket_write( fd, "425 Can't build data connection.\n" );
		socket_close( new_fd );
		return;
	}

	socket_info[ new_fd ] = ([
		DATA	  : (type == STRING ? replace_string(mess, "\n", "\r\n") : mess),
		POS	   : 0,
		PARENT_FD : fd,
		TYPE	  : type,
		LEN	   : (type == STRING ? strlen(mess) : file_size(mess))
	]);

	socket_info[ fd ][ DATA_FD ] = new_fd;

	socket_write( fd, sprintf("150 Opening %s mode data connection for %s "
		  "(%d bytes).\n", data_mode_name, name, socket_info[ new_fd ][ LEN ]));
	data_write_callback( new_fd );
}  /* data_conn() */

static void read_connection( int fd, string path, int append ) {
	int new_fd, ret, data_mode;
	string data_mode_name;
	mixed tmp;

	if ( UTYPE == BINARY ) {
		data_mode_name = "BINARY";
		data_mode = STREAM_BINARY;
		tmp = allocate_buffer( 0 );
	} else {
		data_mode_name = "ASCII";
		data_mode = STREAM;
		tmp = "";
	}

	if ( socket_info[ fd ][ DATA_FD ] ) {
		socket_write( fd, "425 Can't open data connection.\n" );
		return;
	}

	new_fd = socket_create( data_mode, "data_read_callback",
							"data_close_callback" );

	if ( new_fd < 0 ) {
		socket_write( fd, "425 Can't create data socket.\n" );
		return;
	}

	if ( ( ret = socket_connect( new_fd, sprintf("%s %d",
		  socket_info[ fd ][ DATA_ADDR ], socket_info[ fd ][ DATA_PORT ]),
		  "data_read_callback", "data_write_callback" ) ) < 0 ) {
		TP( "Error: " + socket_info[ fd ][ DATA_ADDR ] + " " +
			socket_info[ fd ][ DATA_PORT ] + "\n" );
		TP( socket_error( ret ) + "\n" );
		socket_write( fd, "425 Can't build data connection.\n" );
		socket_close( new_fd );
		return;
	}

	socket_info[ new_fd ] = ([
		PATH	  : path,
		PARENT_FD : fd,
		DATA	  : tmp,
		TYPE	  : DOWNLOAD,
		APPEND	: append
	]);

	socket_info[ fd ][ DATA_FD ] = new_fd;

	socket_write( fd, sprintf("150 Opening %s mode data connection for %s.\n",
		  data_mode_name, path) );
}  /* read_connection() */


void data_read_callback( int fd, mixed mess ) {
	if ( socket_info[ fd ][ TYPE ] != DOWNLOAD )
		return;

	socket_info[ socket_info[ fd ][ PARENT_FD ]][ LAST_DATA ] = time();

	if ( stringp( mess ) )
		mess = replace_string( mess, "\r", "" );

	socket_info[ fd ][ DATA ] += mess;
}  /* data_read_callback() */


void data_close_callback( int fd ) {
	int pos, size, res;

	if ( socket_info[ fd ][ TYPE ] == DOWNLOAD ) {
		if ( socket_info[ fd ][ APPEND ] != 1 )
			catch( rm( socket_info[ fd ][ PATH ] ) );
		else pos = file_size( socket_info[ fd ][ PATH ] );

		do {
			if (catch( res = write_buffer( UPATH, pos,
									   UDATA[pos..(pos+(BLOCK_SIZE-1))] ) ))
				socket_write( socket_info[ fd ][ PARENT_FD ],
					  "452 Error writing file.\n");
			if (res)
				pos += BLOCK_SIZE;
		} while (res);

		size = stringp( UDATA ) ? strlen( UDATA ) : sizeof( UDATA );

#ifdef FILE_LOCKING
		flock_wrapper( socket_info[ fd ][ PATH ], F_UNLOCK,
			  socket_info[ fd ][ PARENT_FD ]);
#endif

		if ( socket_info[ fd ][ APPEND ] == -1)
			socket_write( socket_info[ fd ][ PARENT_FD ],
				  sprintf("226 Transfer complete (unique file name:%s).\n",
				  socket_info[ fd ][ PATH ]) );
		else
			socket_write( socket_info[ fd ][ PARENT_FD ],
					  "226 Transfer complete.\n" );
	}

	/*
	 * only close data connections here
	 */
	if (!undefinedp( socket_info[fd][PARENT_FD] )) {
		socket_close( fd );
		map_delete( socket_info[ socket_info[ fd ][ PARENT_FD ] ],
			  DATA_FD );
	}
}  /* data_close_callback() */


static void logout( int fd ) {
	socket_info[ fd ][ LOGGED_IN ] = 0;
	if ( UNAME ) {
#ifdef LOG_TIME
		log_file( LOG_FILE, FTP_TIME );
#endif

#ifdef LOG_CONNECT
		log_file( LOG_FILE, sprintf("%s logged out from %s.\n", UNAME, USITE) );
#endif

	}
}  /* logout() */


/*
 * parse user command
 */
static void parse_comm( int fd, string str ) {
	string *command, tmp, tmp2;
	mixed *misc;
	int port, i, s;

	TP( "Parsing " + str + ".\n" );
	command = explode( str, " " );
	socket_info[ fd ][ LAST_DATA ] = time();

	switch( lower_case( command[ 0 ] ) )  {
		case "port": // specify data connection port
			command = explode( implode( command[ 1..1000 ], " " ), "," );
			if ( sizeof( command ) < 6 )
				socket_write( fd, "550 Failed command.\n" );
			else {
				socket_info[ fd ][ DATA_ADDR ] = implode( command[ 0..3 ], "." );
				sscanf( command[ 4 ], "%d", i );
				port = i << 8;
				i = atoi( command[5] );
				port += i;
				socket_info[ fd ][ DATA_PORT ] = port;
				socket_write( fd, "200 PORT command successful.\n" );
			}
			break;
		case "user": // specify user name
			if ( socket_info[ fd ][ LOGGED_IN ] ) {
				logout( fd );
				UNAME = 0;
			}

			CHECK_CMD(1);

			if ( !check_access( command[ 1 ] ) ) {
				socket_write( fd, sprintf("530 User %s access denied.\n",
					  command[ 1 ]) );
#ifdef LOG_TIME
				log_file( LOG_FILE, FTP_TIME );
#endif

#ifdef LOG_NO_CONNECT
				log_file( LOG_FILE, sprintf("%s denied access from %s.\n",
					  command[ 1 ], USITE) );
#endif
			} else {
#ifdef ANONYMOUS_FTP
				if ( command[ 1 ] == "anonymous" )
					socket_write( fd,
	"331 Guest login ok, send your complete E-mail address as password.\n" );
				else
#endif
					socket_write( fd, sprintf(
						  "331 Password required for %s.\n", command[ 1 ]) );
				UNAME = command[ 1 ];
			}
			break;
		case "pass": // specify password
			if ( socket_info[fd][LOGGED_IN] || !socket_info[fd][USER_NAME] ) {
				socket_write( fd, "503 Log in with USER first.\n" );
				break;
			}

			if ( !check_password( socket_info[fd][ USER_NAME ],
				  implode( command[ 1..sizeof( command ) - 1 ], " " ) ) ) {
#ifdef ANONYMOUS_FTP
				if (UNAME == "anonymous")
					socket_write( fd,
"530 Login failed.  Please send your complete E-mail address as password.\n" );
				else
#endif
					socket_write( fd, "530 Login incorrect.\n" );

#ifdef LOG_TIME
				log_file( LOG_FILE, FTP_TIME );
#endif

#ifdef LOG_NO_CONNECT
				log_file( LOG_FILE, sprintf(
					  "%s failed/incorrect login from %s.\n", UNAME, USITE) );
#endif
				UNAME = 0;
			} else
#ifdef CHECK_SITE
			if (!check_site( UNAME, fd )) {
				/*
				 * Note: this particular response of 530 is not mentioned
				 * as a possible response to the PASS command in RFC959,
				 * because site checking is TMI specific.
				 */
				socket_write( fd, sprintf("530 User %s: Can't login from %s.\n",
					  UNAME, USITE) );
#ifdef LOG_TIME
				log_file( LOG_FILE, FTP_TIME );
#endif

#ifdef LOG_NO_CONNECT
				log_file( LOG_FILE, sprintf("%s refused login from %s.\n",
					  UNAME, USITE) );
#endif
				UNAME = 0;
				lose_user( fd );
			} else
#endif
			{
				socket_info[ fd ][ LOGGED_IN ] = 1;
#ifdef ANONYMOUS_FTP
				if ( UNAME == "anonymous" )
					UCWD = FTP_DIR;
				else
#endif
					UCWD = HOME_DIR( UNAME );
#ifdef LOG_TIME
				log_file( LOG_FILE, FTP_TIME );
#endif

#ifdef LOG_CONNECT
#ifdef ANONYMOUS_FTP
				if (UNAME == "anonymous")
					log_file( LOG_FILE, sprintf("%s (%s) connected from %s.\n",
						  UNAME, str[strlen(command[0]) + 1..<1], USITE) );
				else
#endif
					log_file( LOG_FILE, sprintf("%s connected from %s.\n",
						  UNAME, USITE) );
#endif

				if ( !directory_exists( UCWD ) ) {
					socket_write( fd, "230 No directory! Logging in with home="
#ifdef GUEST_WIZARD_FTP
						  PUB_DIR ".\n" );
					socket_info[ fd ][ CWD ] = PUB_DIR;
#else
						  "/\n" );
					socket_info[ fd ][ CWD ] = "/";
#endif
				} else {
#ifdef LOGIN_MSG
					tmp = read_file( LOGIN_MSG );
					tmp = tmp[0..<2];
					tmp = sprintf("230- %s\n",
						  replace_string( tmp, "\n", "\n230- " ) );
					socket_write( fd, tmp );
#endif
#ifdef ANONYMOUS_FTP
					if (UNAME == "anonymous")
						socket_write( fd,
					  "230 Guest login ok, access restrictions apply.\n" );
					else
#endif ANONYMOUS_FTP
					socket_write( fd, sprintf(
						  "230 User %s logged in successfully.\n", UNAME) );
				}
				socket_info[ fd ][ TYPE ] = STRING;
			}
			break;
		case "allo": // allocate storage (vacuously)
			socket_write( fd, "202 ALLO command ignored.\n" );
			break;
		case "noop": // do nothing
			socket_write( fd, "200 NOOP command successful.\n" );
			break;
		case "retr": // retrieve a file
			CHECK_LOGIN();
			CHECK_CMD(1);
			tmp = get_path( fd, command[ 1 ] );
			if ((i = file_size(tmp)) == -2) {
				socket_write( fd, sprintf("550 %s: Not a plain file.\n",
					  command[1]));
			} else if (i == -1) {
				socket_write( fd, sprintf(
					  "550 %s: No such file or directory(%s).\n", command[1], tmp));
			} else if ( !check_valid_read( tmp, fd ) )  {
				PERMISSION_DENIED550(command[ 1 ]);
			} else {
#ifdef LOG_TIME
				log_file( LOG_FILE, FTP_TIME );
#endif

#ifdef LOG_FILE
				log_file( LOG_FILE, sprintf("%s retr %s (%s).\n",
					  UNAME, tmp, (UTYPE == BINARY ? "BINARY" : "ASCII") ) );
#endif
				data_conn( fd, tmp, command[ 1 ], FILE );
			}
			break;
		case "stou": // store a file with a unique name
			CHECK_LOGIN();
			CHECK_CMD(1);
			tmp = get_path( fd, command[ 1 ] );
			i = file_size(tmp);
			if (i >= 0 && check_valid_write( tmp, fd )) {
				for (i = MAX_UNIQUE_TRIES; i; i--) {
					if (file_size(sprintf("%s%d", tmp, i)) == -1)
						break;
				}
				if (i) {
					tmp = sprintf("%s%d", tmp, i);
#ifdef FILE_LOCKING
					if (flock_wrapper(tmp, F_LOCK, fd)) {   /* parent fd */
#endif

#ifdef LOG_TIME
						log_file( LOG_FILE, FTP_TIME );
#endif

#ifdef LOG_FILE
						log_file( LOG_FILE, sprintf("%s stou %s (%s).\n", UNAME,
							  tmp, (UTYPE == BINARY ? "BINARY" : "ASCII") ) );
#endif
						read_connection( fd, tmp, -1 );
#ifdef FILE_LOCKING
					} else {
						PERMISSION_DENIED550(command[ 1 ]);
					}
#endif
				} else {
					socket_write( fd, "452 Unique file name cannot be created.\n");
				}
			} else {
				PERMISSION_DENIED553(command[ 1 ]);
			}
			break;
		case "stor": // store a file
			CHECK_LOGIN();
			CHECK_CMD(1);
			tmp = get_path( fd, command[ 1 ] );
			if ( file_size(tmp) != -2 && check_valid_write( tmp, fd ) ) {
#ifdef FILE_LOCKING
				if (flock_wrapper(tmp, F_LOCK, fd)) {   /* parent fd */
#endif

#ifdef LOG_TIME
					log_file( LOG_FILE, FTP_TIME );
#endif

#ifdef LOG_FILE
					log_file( LOG_FILE, sprintf("%s stor %s (%s).\n", UNAME,
						  tmp, (UTYPE == BINARY ? "BINARY" : "ASCII") ) );
#endif
					read_connection( fd, tmp, 0 );
#ifdef FILE_LOCKING
				} else {
					PERMISSION_DENIED550(command[ 1 ]);
				}
#endif
			} else {
				PERMISSION_DENIED553(command[ 1 ]);
			}
			break;
		case "appe": // append to a file
			CHECK_LOGIN();
			CHECK_CMD(1);
			tmp = get_path( fd, command[ 1 ] );
			if ( file_size(tmp) >= 0 && check_valid_write( tmp, fd ) ) {
#ifdef FILE_LOCKING
				if (flock_wrapper(tmp, F_LOCK, fd)) {   /* parent fd */
#endif

#ifdef LOG_TIME
					log_file( LOG_FILE, FTP_TIME );
#endif

#ifdef LOG_FILE
					log_file( LOG_FILE, sprintf("%s appe %s (%s).\n", UNAME,
						  tmp, (UTYPE == BINARY ? "BINARY" : "ASCII") ) );
#endif
					read_connection( fd, tmp, 1 );
#ifdef FILE_LOCKING
				} else {
					PERMISSION_DENIED550(command[ 1 ]);
				}
#endif
			} else {
				PERMISSION_DENIED553(command[ 1 ]);
			}
			break;
		case "dele": // delete a file
			CHECK_LOGIN();
			CHECK_CMD(1);
			tmp = get_path( fd, command[ 1 ] );
			if ((i = file_size(tmp)) == -2) {
				socket_write( fd, sprintf("550 %s: Not a plain file.\n",
					  command[1]));
			} else if (i == -1) {
				socket_write( fd, sprintf(
					  "550 %s: No such file or directory.\n", command[1]));
			} else if ( check_valid_write( tmp, fd ) ) {
#ifdef FILE_LOCKING
				if (flock_wrapper(tmp, F_LOCK, fd)) {   /* parent fd */
#endif

#ifdef LOG_TIME
					log_file( LOG_FILE, FTP_TIME );
#endif

#ifdef LOG_FILE
					log_file( LOG_FILE, sprintf("%s dele %s.\n", UNAME, tmp) );
#endif
					catch( i = rm(tmp) );
					if (i)
						socket_write( fd, "250 DELE command successful.\n" );
					else
						socket_write( fd, sprintf(
							  "550 Permission denied to %s.\n", command[ 1 ]) );
#ifdef FILE_LOCKING
					flock_wrapper(tmp, F_UNLOCK, fd);   /* parent fd */
				} else {
					PERMISSION_DENIED550(command[ 1 ]);
				}
#endif
			} else {
				PERMISSION_DENIED553(command[ 1 ]);
			}
			break;
		/* Supposed to return modified time in the format: YYYYMMDDHHMMSS */
		case "mdtm": // show last modification time of file
			CHECK_LOGIN();
			CHECK_CMD(1);
			tmp = get_path( fd, command[ 1 ] );
			if ( check_valid_read( tmp, fd ) ) {
				if ((i = file_size(tmp)) == -2)
					socket_write( fd, sprintf("550 %s: Not a plain file.\n",
						  command[1]));
				else if (i == -1)
					socket_write( fd, sprintf(
						  "550 %s: No such file or directory.\n", command[1]));
				else {
					misc = stat(tmp);
					tmp2 = ctime(misc[1]);
					tmp2 = sprintf("%s%02d%c%c%s%s%s",
						  tmp2[20..23], member_array(tmp2[4..6], MONTHS),
						  tmp2[8] == ' ' ? '0' : tmp2[8],
						  tmp2[11..12], tmp2[14..15], tmp2[17..18]);
#ifdef LOG_TIME
					log_file( LOG_FILE, FTP_TIME );
#endif

#ifdef LOG_CD_SIZE
					log_file( LOG_FILE, sprintf("%s mdtm %s.\n", UNAME, tmp) );
#endif
					socket_write( fd, sprintf("213 %s\n", tmp2) );
				}
			} else
				PERMISSION_DENIED550(command[ 1 ]);
			break;
		case "size": // return size of file
			CHECK_LOGIN();
			CHECK_CMD(1);
			tmp = get_path( fd, command[ 1 ] );
			if ( check_valid_read( tmp, fd ) ) {
				if ( directory_exists( tmp ) )
					socket_write( fd, sprintf("550 %s: Not a plain file.\n",
						  command[ 1 ]) );
				else
					if ( !file_exists( tmp ) )
						socket_write( fd, sprintf("550 %s does not exist.\n",
							  command[ 1 ]) );
					else {
#ifdef LOG_TIME
						log_file( LOG_FILE, FTP_TIME );
#endif

#ifdef LOG_CD_SIZE
						log_file( LOG_FILE, sprintf("%s size %s.\n",
							  UNAME, tmp) );
#endif
						socket_write( fd, sprintf("215 %d\n", file_size( tmp )) );
					}
			} else
				PERMISSION_DENIED550(command[ 1 ]);
			break;
		case "nlst": // give name list of files in directory
			CHECK_LOGIN();
			/* Send name list */
			if ((i = sizeof(command)) > 1 && command[1] == "-l") {
				if (i == 2)
					command[1] = ".";
				else
					command = ({ command[0] }) + command[2..s-1];
				// and fall through to "list"
			} else {
				/* Used by commands like "dir", "mget", and "mput" */
				if ( i > 1 )
					tmp = get_path( fd, command[ 1 ] );
				else
					tmp = socket_info[ fd ][ CWD ];

				if ( check_valid_read( tmp, fd ) ) {
					tmp2 = ls( tmp, 1, fd );
					if (tmp2 == "")
						socket_write( fd, "550 No files found.\n" );
					else
						data_conn( fd, tmp2, "ls", STRING );
				} else
					PERMISSION_DENIED550(command[ 1 ]);
				break;
			}
		case "list": // give list files in a directory
			CHECK_LOGIN();
			/* Send directory file list (like exec'ing "ls") */
			if ( sizeof( command ) > 1 )
				tmp = get_path( fd, command[ 1 ] );
			else
				tmp = socket_info[ fd ][ CWD ];
			if ( check_valid_read( tmp, fd ) ) {
				tmp2 = ls( tmp, 0, fd );
				if (tmp2 == "")
					socket_write( fd, "550 No files found.\n");
				else
					data_conn( fd, tmp2, "ls", STRING );
			} else
				PERMISSION_DENIED550(command[ 1 ]);
			break;
		case "xpwd": // print the current working directory (deprecated)
		case "pwd":  // print the current working directory
			CHECK_LOGIN();
			socket_write( fd, sprintf("257 \"%s\" is the current directory.\n",
				  socket_info[ fd ][ CWD ]) );
			break;
		case "xcup": // change to parent of current working directory (deprecated)
		case "cdup": // change to parent of current working directory
			if (sizeof(command) > 1)
				command[ 1 ] = "..";
			else
				command += ({ ".." });
		case "xcwd": // change working directory (deprecated)
		case "cwd":  // change working directory
			CHECK_LOGIN();
			if ( sizeof( command ) > 1 )
				tmp = get_path( fd, command[ 1 ] );
			else
				tmp = socket_info[ fd ][ CWD ];
			if ( check_valid_read( tmp, fd ) ) {
				tmp = get_path( fd, tmp );

				if ( !directory_exists( tmp ) ) {
					socket_write( fd, sprintf("550 %s: Not a directory.\n", tmp) );
					break;
				}
#ifdef LOG_TIME
				log_file( LOG_FILE, FTP_TIME );
#endif

#ifdef LOG_CD_SIZE
				log_file( LOG_FILE, sprintf("%s cd to %s.\n", UNAME, tmp) );
#endif
				socket_info[ fd ][ CWD ] = tmp;
#ifdef MESSAGE_FILES
				if (file_size(tmp + "/.message") > 0) {
					tmp = read_file(tmp + "/.message");
					tmp = tmp[0..<2];
					tmp = sprintf("250- %s\n250 %s command successful.\n",
						  replace_string(tmp, "\n", "\n250- "), command[0]);
					socket_write(fd, tmp);
				} else
#endif
				socket_write( fd, sprintf("250 %s command successful.\n",
					  command[0]) );
			} else
				socket_write( fd, sprintf("550 %s: No such file or directory.\n",
					  tmp) );
			break;
		case "quit": // terminate session
			socket_write( fd, "221 Goodbye.\n" );
			logout( fd );
			lose_user( fd );
			break;
		case "type": // specify data transfer type
			CHECK_CMD(1);
			if ( command[ 1 ] == "I" ) {
				socket_info[ fd ][ TYPE ] = BINARY;
				socket_write( fd, "200 Type set to I.\n" );
			} else
				if ( command[ 1 ] == "A" ) {
					socket_info[ fd ][ TYPE ] = STRING;
					socket_write( fd, "200 Type set to A.\n" );
				} else
					socket_write( fd, sprintf("504 Type %s not implemented.\n",
						  command[ 1 ]) );
			break;
		case "stat": // return status of server
			socket_write( fd, sprintf(
				  "211 FTP server status: %s FTP Version %s\r\n",
				  THE_MUD_NAME, FTPD_VERSION) );
			socket_write( fd, sprintf("	 Connected to %s\r\n", USITE) );
			if ( socket_info[ fd ][ LOGGED_IN ] )
				socket_write( fd, sprintf("	Logged in as %s\r\n", UNAME) );
			else
				if ( UNAME )
					socket_write( fd, "	Waiting for password.\r\n" );
				else
					socket_write( fd, "	Waiting for user name.\r\n" );
			socket_write( fd, "	TYPE: ASCII, FORM: Nonprint; STRUcture: "
							  "File; transfer MODE: Stream.\r\n" );
			if ( socket_info[ fd ][ DATA_FD ] )
				socket_write( fd, "	Data connection open.\r\n" );
			else
				if ( socket_info[ fd ][ DATA_ADDR ] )
					socket_write( fd, sprintf("	%s %d\r\n",
						  socket_info[ fd ][ DATA_ADDR ],
						  socket_info[ fd ][ DATA_PORT ]) );
				else
					socket_write( fd, "	No data connection.\r\n" );
			socket_write( fd, "211 End of status.\n" );
			break;
		case "abor": // abort previous command
			/* Stops recvs and stors. At least thats what it is supposed to do. */
			if ( socket_info[ fd ][ DATA_FD ] ) {
				socket_write( fd,
					  "426 Transfer aborted. Data connection closed.\n");
#ifdef FILE_LOCKING
				if ( (socket_info[ fd ][ DATA_FD ])[ TYPE ] == DOWNLOAD )
					flock_wrapper( (socket_info[ fd ][ DATA_FD ])[ PATH ],
						  F_UNLOCK, socket_info[ fd ] );
#endif
				socket_close( socket_info[ fd ][ DATA_FD ] );
				map_delete( socket_info[fd], DATA_FD );
			}
			socket_write( fd, "226 Abort successful.\n" );
			break;
		case "syst": // show operating system type of server system
			socket_write( fd, sprintf("215 MUD Type: %s\n", THE_VERSION) );
			break;
		case "xmkd": // make a directory (deprecated)
		case "mkd":  // make a directory
			CHECK_LOGIN();
			CHECK_CMD(1);
			tmp = get_path( fd, command[ 1 ] );
			if (file_size( tmp ) == -1) {
				if (check_valid_write(tmp, fd)) {
					if (mkdir(tmp)) {
#ifdef LOG_TIME
						log_file( LOG_FILE, FTP_TIME );
#endif

#ifdef LOG_FILE
						log_file( LOG_FILE, sprintf("%s mkd %s.\n",
							  UNAME, tmp) );
#endif
						socket_write(fd, sprintf("257 %s command successful.\n",
							  command[ 0 ]) );
					} else
						socket_write(fd, sprintf("550 %s command failed.\n",
							  command[ 0 ]) );
				} else
					PERMISSION_DENIED550(command[ 1 ]);
			} else
				socket_write(fd, sprintf(
					  "550 %s: Directory or file already exists.\n",
					  command[ 1 ]));
			break;
		case "xrmd": // remove a directory (deprecated)
		case "rmd":  // remove a directory
			CHECK_LOGIN();
			CHECK_CMD(1);
			tmp = get_path( fd, command[ 1 ] );
			if (file_size( tmp ) == -2) {
				if (check_valid_write(tmp, fd)) {
					if (rmdir(tmp)) {
#ifdef LOG_TIME
						log_file( LOG_FILE, FTP_TIME );
#endif

#ifdef LOG_FILE
						log_file( LOG_FILE, sprintf("%s rmd %s.\n",
							  UNAME, tmp) );
#endif
						socket_write(fd, sprintf("250 %s command successful.\n",
							  command[ 0 ]) );
					} else
						socket_write(fd, sprintf("550 %s command failed.\n",
							  command[ 0 ]) );
				} else
					PERMISSION_DENIED550(command[ 1 ]);
			} else
				socket_write(fd, sprintf("550 %s: No such file or directory.\n",
					  command[ 1 ]) );
			break;
		case "site": // non-standard commands
			CHECK_LOGIN();
			CHECK_CMD(1);
			switch (lower_case(command[ 1 ])) {
				case "idle":
					if (sizeof(command) < 3) {
						socket_write(fd,
							  sprintf("200 Current IDLE time limit is %d seconds; max %d\n",
							  socket_info[fd][IDLE_SETTING], MAX_FTPD_IDLE));
						break;
					}

					if (!sscanf(command[2], "%d", i)) {
						socket_write(fd, "550 SITE IDLE command failed.\n");
						break;
					}

					i = (i < FTPD_TIMEOUT ? FTPD_TIMEOUT : (i > MAX_FTPD_IDLE ? MAX_FTPD_IDLE : i));
					socket_info[fd][IDLE_SETTING] = i;
					socket_write(fd, sprintf("200 Maximum IDLE time set to %d seconds\n", i));
					break;
				case "time":
					socket_write(fd,
						  sprintf("200 Local TIME is %s.\n", ctime(time())[4..15] ) );
					break;
				case "help":
					if (sizeof(command) > 1) {
						tmp = lower_case(command[1]);
						if (!undefinedp(sitecmdtab[ tmp ])) {
							misc = sitecmdtab[ tmp ];
							if (misc[1])
								socket_write(fd, sprintf("214 Syntax: %s %s.\n",
									  misc[0], misc[2]) );
							else
								socket_write(fd, sprintf("214 %s %s; unimplemented.\n",
									  misc[0], misc[2]) );
						} else {
							socket_write(fd, sprintf("502 Unknown command %s.\n",
								  command[ 1 ]) );
						}
					} else {
						socket_write(fd, "214- The following SITE commands are recognized "
							  "(* =>'s unimplemented).\n214-\n");
						misc = keys(sitecmdtab);
						s = sizeof(misc);
						tmp = "214- ";
						for (i = 0; i < s; i++) {
							tmp += sprintf("%c%-7s", sitecmdtab[misc[i]][1] ? ' ' : '*',
									   sitecmdtab[misc[i]][0]);
							if (i % 8 == 7) {
								socket_write(fd, tmp + "\n");
								tmp = "214- ";
							}
						}
						if (i % 8)
							socket_write(fd, tmp + "\n");
						socket_write(fd, sprintf("214-\n214 Direct comments to %s.\n",
							  FTP_BUGS_EMAIL));
					}
					break;
				case "chmod":
				case "umask":
					socket_write( fd, sprintf("502 '%s' command not implemented.\n",
						  command[ 0 ]) );
					break;
				default:
					socket_write( fd, sprintf("500 '%s %s' command "
						  "not understood.\n", command[ 0 ], command[ 1 ]) );
					break;
			}
			break;
		case "rnfr": // specify rename-from file name
			CHECK_LOGIN();
			CHECK_CMD(1);
			tmp = get_path( fd, command[1] );
			i = file_size( tmp );
			if (i == -2) {
				socket_write( fd, sprintf("550 %s: Not a plain file.\n",
					  command[ 1 ]) );
			} else if (i == -1) {
				socket_write(fd, sprintf("550 %s: No such file or directory.\n",
					  command[ 1 ]) );
			} else if (check_valid_write(tmp, fd)) {
				socket_info[fd][FROMNAME] = tmp;
				socket_write(fd, "350 File exists, ready for destination name.\n");
			} else {
				PERMISSION_DENIED550(command[ 1 ]);
			}
			break;
		case "rnto": // specify rename-to file name
			CHECK_LOGIN();
			CHECK_CMD(1);
			if (!socket_info[fd][FROMNAME]) {
				socket_write(fd, "503 Bad sequence of commands.\n");
			} else {
				tmp = get_path( fd, command[1] );
				i = file_size( tmp );
				if (i != -1) {
					socket_write(fd, sprintf(
						  "550 %s: Directory or file already exists.\n",
						  command[ 1 ]) );
				} else if (!check_valid_write(tmp, fd)) {
					PERMISSION_DENIED550(command[ 1 ]);
				} else {
					tmp2 = socket_info[fd][FROMNAME];
					if (!check_valid_write(tmp2, fd)) {
						PERMISSION_DENIED550(tmp2);
						socket_info[fd][FROMNAME] = 0;
					} else {
#ifdef FILE_LOCKING
						if (flock_wrapper(tmp, F_LOCK, fd)) {
							if (flock_wrapper(tmp2, F_LOCK, fd)) {
#endif

#ifdef LOG_TIME
								log_file( LOG_FILE, FTP_TIME );
#endif

#ifdef LOG_FILE
								log_file( LOG_FILE, sprintf("%s rnfr %s "
									  "rnto %s.\n", UNAME, tmp2, tmp) );
#endif
								if (catch( i = rename(tmp2, tmp) ) || i)
									socket_write(fd,
										  "550 RNTO command failed.\n");
								else
									socket_write(fd,
										  "250 RNTO command successful.\n");
#ifdef FILE_LOCKING
								flock_wrapper(tmp2, F_UNLOCK, fd);
								flock_wrapper(tmp, F_UNLOCK, fd);
								socket_info[fd][FROMNAME] = 0;
							} else {
								PERMISSION_DENIED550(tmp2);
								flock_wrapper(tmp, F_UNLOCK, fd);
							}
						} else {
							PERMISSION_DENIED550(command[ 1 ]);
						}
#endif
					}
				}
			}
			break;
		case "help": // give help information
			if (sizeof(command) > 1) {
				tmp = lower_case(command[1]);
				if (!undefinedp(cmdtab[ tmp ])) {
					misc = cmdtab[ tmp ];
					if (misc[1])
						socket_write(fd, sprintf("214 Syntax: %s %s.\n",
							  misc[0], misc[2]) );
					else
						socket_write(fd, sprintf("214 %s %s; unimplemented.\n",
							  misc[0], misc[2]) );
				} else {
					socket_write(fd, sprintf("502 Unknown command %s.\n",
						  command[ 1 ]) );
				}
			} else {
				socket_write(fd, "214- The following commands are recognized "
					  "(* =>'s unimplemented).\n214-\n");
				misc = keys(cmdtab);
				s = sizeof(misc);
				tmp = "214- ";
				for (i = 0; i < s; i++) {
					tmp += sprintf("%c%-7s", cmdtab[misc[i]][1] ? ' ' : '*',
							   cmdtab[misc[i]][0]);
					if (i % 8 == 7) {
						socket_write(fd, tmp + "\n");
						tmp = "214- ";
					}
				}
				if (i % 8)
					socket_write(fd, tmp + "\n");
				socket_write(fd, sprintf("214-\n214 Direct comments to %s.\n",
					  FTP_BUGS_EMAIL));
			}
			break;
		case "acct": // specify account (ignored)
		case "mail": // mail to user
		case "mlfl": // mail file
		case "mode": // specify data transfer mode
		case "mrcp": // mail recipient
		case "mrsq": // mail recipient scheme question
		case "msnd": // mail send to terminal
		case "msam": // mail send to terminal and mailbox
		case "msom": // mail send to terminal or mailbox
		case "pasv": // prepare for server-to-server transfer
		case "rein": // reinitialize server state
		case "rest": // restart command/incomplete transfer
		case "smnt": // structure mount
		case "stru": // specify data transfer/file structure
			socket_write( fd, sprintf("502 '%s' command not implemented.\n",
				  command[ 0 ]) );
			break;

		default:
			socket_write( fd, sprintf("500 '%s': command not understood.\n",
				  command[ 0 ]) );
			break;
	}
} /* parse_com() */


/*
 * accept user command
 */
void in_read_callback( int fd, string str ) {
	string *command;
	int i, j;

	if (undefinedp( socket_info[ fd ][ CONNECTED ]) ||
		  !socket_info[ fd ][ CONNECTED ])
		return;

	if (!str)  str = "";
	str = replace_string( str, "\r", "" );
	command = explode( str, "\n" ) - ({ 0 });
	j = sizeof(command);

	for ( i = 0; i < j; i++ )
		parse_comm( fd, command[i] );
}


/*
 * Handle when the socket closes unexpectedly
 */
void in_close_callback( int fd ) {
	/*
	 * Handle case where user aborts (eg CTRL-C) their ftp client, causing
	 * connection to close before getting to login prompt.
	 */
	if (undefinedp(socket_info[fd][CONNECTED]))
		;
	else {
		/*
		 * Handle case where user doesn't quit properly
		 */
		logout( fd );
		lose_user( fd );
	}
}


/*
 * resolve path (absolute vs relative) ... does not validate path here
 */
static string get_path( int fd, string str )
{
	string *dirlist, *dirlist1, temp;
	int i, j, s;

	if ( !str || str == "" ) return socket_info[ fd ][ CWD ];

	if ( str == "/" ) {
		/* root of filesystem */
#ifdef ANONYMOUS_FTP
		if (UNAME == "anonymous")
			return FTP_DIR;
		else
#endif
			return "/";
	}

	if ( str == "~" ) {
		/* change to home dir */
#ifdef ANONYMOUS_FTP
		if (UNAME == "anonymous")
			str = FTP_DIR;
		else
#endif
			str = HOME_DIR( UNAME );
	} else {
		if ( str[ 0 ] == '~' ) {
			/* relative to user directories */
			if ( str[ 1 ] == '/' ) {
				/* relative to user's home directory */
				temp = str[1..sizeof(str)-1];
				str = HOME_DIR( UNAME ) + temp;
			} else {
				/* relative to someone else's home directory */
				string name;

				if ( sscanf( str, "~%s/%s", name, str ) != 2 ) {
					name = str[1..sizeof(str)-1];
					str = HOME_DIR( name );
				} else {
					/* "cheat" at this point and just assume they are a wizard. */
					str = sprintf("%s/%s", HOME_DIR( name ), str);
				}
			}
		} else if (str [0] != '/') {
			/* relative to current working directory */
			str = sprintf("%s/%s/", socket_info[ fd ][ CWD ], str);
		} /* else absolute path name */
	}

	/*
	 * Assume HOME_DIR() might or might not return leading and/or trailing
	 * slashes; process path names for consistency (always a leading slash,
	 * and never a trailing slash); leave it up to caller to check if
	 * path name is a directory or not
	 */

	/*
	 * explode path name into directory components (dirs and/or file);
	 * also remove null strings (eg "//") and single periods (eg "/./")
	 */
	dirlist = explode( str, "/" ) - ({ "", "." });

	s = sizeof(dirlist);
	for (i = 0; i < s; i++) {
		/*
		 * handle ".." occurrences
		 */
		if ( dirlist[ i ] == ".." ) {
			if ( i < 1 ) {
				/* handle ".." at root of filesystem */
#ifdef ANONYMOUS_FTP
				if (UNAME == "anonymous")
					return FTP_DIR;
				else
#endif
				  return "/";
			}

			/*
			 * get leading portion of path name
			 */
			if ( i == 1 )
				dirlist1 = ({ });
			else
				dirlist1 = dirlist[ 0..i - 2 ];

			/*
			 * get trailing portion of path name, ignoring the middle
			 */
			s -= 2;
			if ( i <= s )
				dirlist1 += dirlist[ i + 1 .. sizeof(dirlist) - 1];

			dirlist = dirlist1;
			i -= 2;
		}
	}

	if ( dirlist )
		str = "/" + implode( dirlist, "/" );
	else
		str = "/";

#ifdef ANONYMOUS_FTP
	// To replace old ftpd's buggy method of restricting anonymous user
	// in the FIT_DIR
	if( UNAME == "anonymous"
	&&	strsrch(str, FTP_DIR)!= 0 )
		str = FTP_DIR + str;
#endif

	return str;
}


static void check_connections() {
	int *sockets, i, limit;
	int pfd;

	sockets = keys( socket_info );
	i = sizeof( sockets );

	/*
	 * check control connections for idle users
	 */
	while ( i-- ) {
		if ( !undefinedp(socket_info[ sockets[i]][LAST_DATA]) ) {
			limit = time() - socket_info[ sockets[i]][IDLE_SETTING];
			if ( socket_info[ sockets[i]][LAST_DATA] < limit ) {
				socket_write( sockets[i],
					  "421 Timeout: closing control session.\n" );
				logout( sockets[i] );
				lose_user( sockets[i] );
			}
		}
	}

	sockets = keys( socket_info );
	i = sizeof( sockets );

	/*
	 * check data connections for orphans
	 */
	while ( i-- ) {
		if (!undefinedp( socket_info[ sockets[i] ][ PARENT_FD ] )) {
			pfd = socket_info[ sockets[i] ][ PARENT_FD ];
			if (undefinedp(socket_info[ pfd ])) {
#ifdef FILE_LOCKING
				if (!undefinedp(socket_info[ sockets[i] ][ TYPE ]) &&
					  socket_info[ sockets[i] ][ TYPE ] == DOWNLOAD ) {
					flock_wrapper( socket_info[ sockets[i] ][ PATH ], F_UNLOCK,
						  sockets[i] );
				}
#endif
				lose_connection( sockets[i] );
			}
		}
	}
	call_out( "check_connections", 3 * 60 );
}


void resolve_callback( string address, string resolved, int key ) {
	int id;

	/*
	 * An example where these two errors can occur:
	 *   update the ftpd daemon while a user is logging in
	 */
	if ( undefinedp( id = temp_map[ key ] ) ) {
#ifdef LOG_FILE
		log_file( LOG_FILE, sprintf("No such key in temp_map: %d.\n", key) )
#endif
		;
	} else if ( undefinedp( socket_info[ id ] )) {
#ifdef LOG_FILE
		log_file( LOG_FILE, sprintf("No such fd in socket_info: %d.\n", id) )
#endif
		;
	} else {
		if ( address && address != "" )
			socket_info[id][USER_SITE] = address;
		// else retain unresolved ip number address
	}
}


//void remove()
//{
//	if (number_of_users &&
//		 this_player(1) &&
//		 (string)SECURITY_D->get_status(this_player(1))!="(admin)" )
//	  error( "Cannot destruct while there are active ftp sessions.\n" );
//}

/* EOF */
