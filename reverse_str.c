#include <stdio.h>

//字符串翻转:
//对字符串中的每个单词逐个进行翻转
// hello world are ====> olleh dlrow era
//题目来源:力扣<<LeetCode>>
//链接:https://leetcode-cn.com/problems/
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
char str[] = "hello world are";


/*****************************************************
@funtion: reverse
@description: reverse a words
@param: str is the target will be reverse
        w_start is the words start postion
        w_end is the words end positon
@return: none
****************************************************/
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



/*****************************************************
@funtion: reverseStrings
@description: reverse a string
@param: str is the target will be reverse
@return: the string reversed
****************************************************/
char *reverseStrings(char * s)
{
    int left = 0, right = 0;
    while ( s[right++] != '\0' ) 
    {
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
