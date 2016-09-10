#ifndef STRING_H
#define STRING_H 0

static uint8_t char_toNum(char sv)
{
	switch(sv)
	{
		case '0': return 0;
		case '1': return 1;
		case '2': return 2;
		case '3': return 3;
		case '4': return 4;
		case '5': return 5;
		case '6': return 6;
		case '7': return 7;
		case '8': return 8;
		case '9': return 9;
	}
}

static char num_toChar(uint8_t i)
{
	switch(i)
	{
		case 0: return '0';
		case 1: return '1';
		case 2: return '2';
		case 3: return '3';
		case 4: return '4';
		case 5: return '5';
		case 6: return '6';
		case 7: return '7';
		case 8: return '8';
		case 9: return '9';
	}
}

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
