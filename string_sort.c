#include <stdio.h>
#include <string.h>

char str[] = "beedcba";

char string_sort(char *s)
{
	int i, j;
	char len = strlen(s);
	char tem = 0;
	for(i=0; i<len-1; i++)
	{
		for(j=0; j<len-i-1; j++)
		{
			if( s[j+1] < s[j] )
			{	
				tem = s[j+1];
				s[j+1] = s[j];
				s[j] = tem;
			}
		}
	}
}

int main()
{
	string_sort(str);
	printf("%s\n", str);
	return 0;
}
