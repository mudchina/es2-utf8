
string chinese_number(int i)
{
	return CHINESE_D->chinese_number(i);
}

string to_chinese(string str)
{
	return CHINESE_D->chinese(str);
}

int is_chinese(string str)
{
	if( strlen(str)>=2 && str[0] > 128 && str[0] < 255 ) return 1;
	return 0;
}

int utf8_strlen(string str)
{
  int i;
  int n = 0;
  int len = strlen(str);
  for(i=0; i<len; i++) {
    if ((str[i] & 0xC0) != 0x80) n++;
  }
  return n;
}
