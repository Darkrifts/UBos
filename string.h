#ifndef STRING_H
#define STRING_H 0

static char char_toUpper(char sv)
{
	char sv_ret = 0;
	if(sv >= 'a' && sv <= 'z')
	{
		int sv_int = (int) sv-32;
		sv_ret = (char) sv_int;
	}

	return sv_ret;
}

static char char_toLower(char sv)
{
	char sv_ret = 0;
	if(sv >= 'A' && sv <= 'Z')
	{
		int sv_int = (int) sv+32;
		sv_ret = (char) sv_int;
	}
	return sv_ret;
}

size_t strlen(const char* str) {
	size_t len = 0;
	while (str[len])
		len++;
	return len;
}

size_t strlen(char* str) {
	size_t len = 0;
	while (str[len])
		len++;
	return len;
}

size_t strlen(unsigned char* str) {
	size_t len = 0;
	while (str[len])
		len++;
	return len;
}

static void str_toUpper(char* str)
{
	int len = strlen(str);
	for(int i = 0; i < len; i++) str[i] = char_toUpper(str[i]);
}

static void str_toLower(char* str)
{
	int len = strlen(str);
	for(int i = 0; i < len; i++) str[i] = char_toLower(str[i]);
}

#endif
