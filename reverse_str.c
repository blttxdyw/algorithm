#include <stdio.h>

char str[] = "hello   world are";


/*
@funtion: reverse
@description: reverse a words
@param: str is the target will be reverse
        w_start is the words start postion
        w_end is the words end positon
@return: none
*/
void reverseWord(char *str, int w_start, int w_end)
{ 
    while (w_start < w_end) {
        char temp = str[w_start];
        str[w_start] = str[w_end];
        str[w_end] = temp;
        w_start++;
        w_end--;
    }
}


char *reverseStrings(char * s)
{
    int left = 0;
    int right = 0;
    while (s[right++] != '\0') {
        if (s[right] == ' ' || s[right] == '\0') {
            reverseWord(s, left, right - 1);
            left = right + 1;
        }
    }
    return s;
}

int main()
{
	char *s_sort;
	printf("before sort:%s\n", str);
	s_sort = reverseStrings(str);
	printf("sort later : %s\n", s_sort);
	return 0;
}
