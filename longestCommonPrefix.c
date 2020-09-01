#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/*
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀,返回空字符串 ""。

示例 1:
输入: ["flower","flow","flight"]
输出: "fl"

示例 2:
输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。

说明:
所有输入只包含小写字母 a-z 。

题目来源:力扣<<LeetCode>>
链接:https://leetcode-cn.com/problems
著作权归领扣网络所有。商业转载请联系官方授权,非商业转载请注明出处。
*/



char str[3][10] = {"flower","flow","flowght"};

#if 1
/*****************************************************
@funtion: longestCommonPrefix
@description: find longestCommonPrefix of the strings
@param: strs is point the string array, strsSize is the array number of the elements 
@return: the address storage result
****************************************************/
char * longestCommonPrefix(char ** strs, int strsSize)
{
    int i, j;
    if(strsSize == 0) return "";  
    for(i=0; i<strlen(strs[0]); i++)
    {   
        for( j=1; j<strsSize; j++)
        {    
            if(strs[0][i] != strs[j][i])
            { 
                strs[0][i] = '\0';
                break;
            }
        }
    }
    return strs[0];
}
#else
char * longestCommonPrefix(char ** strs, int strsSize)
{
    int len = 0;
    printf("*str[0]: %c\n", *str[0]);
    while((*str[0] ^ *str[1] ^ *str[2]) == *str[0])
    {
        res[len++] = *str[0];
        str[0]++;    
        str[1]++;
        str[2]++;
    }
}
#endif

int main()
{
    char **p = (char**)malloc(sizeof(char *)*3);
    p[0] = str[0];
    p[1] = str[1];
    p[2] = str[2];
    longestCommonPrefix(p, 3);
    printf("%s\n", p[0]);
    printf("%s\n", str[0]);
    return 0;    
}
