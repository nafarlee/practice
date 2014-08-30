#include <stdio.h>
#include <limits.h>

signed char sc = 0;
unsigned char uc = 0;
signed short ss = 0;
unsigned short us = 0;
signed int si = 0;
unsigned int ui = 0;
signed long sl = 0, max = 0;
unsigned long ul = 0;

int main(void)
{
	printf("%ld\n", LONG_MAX);
	return 0;
}
