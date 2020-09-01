#include <stdio.h>

/*
请你来实现一个 atoi 函数,使其能将字符串转换成整数。 

示例 1:
输入: "42"
输出: 42

示例 2:
输入: "   -42"
输出: -42
解释: 第一个非空白字符为 '-', 它是一个负号。
     我们尽可能将负号与后面所有连续出现的数字组合起来，最后得到 -42 。

示例 3:
输入: "4193 with words"
输出: 4193
解释: 转换截止于数字 '3' ,因为它的下一个字符不为数字。
示例 4:

输入: "words and 987"
输出: 0
解释: 第一个非空字符是 'w', 但它不是数字或正、负号。
     因此无法执行有效的转换。
示例 5:

输入: "-91283472332"
输出: -2147483648
解释: 数字 "-91283472332" 超过 32 位有符号整数范围。 
     因此返回 INT_MIN (−231) 。

题目来源:力扣<<LeetCode>>
链接:https://leetcode-cn.com/problems
著作权归领扣网络所有。商业转载请联系官方授权,非商业转载请注明出处。
*/




char str[] = "  12345 hell 12333";

#define SPACE 32
#define MINUS 45
#define POSITIVE 43
#define INT_MAX 2147483647
#define INT_MIN -2147483648


/*****************************************************
@funtion: myAtoi
@description: Converts a string to an integer
@param: str point to the string will converts
@return: the res is the result of the conversion 
****************************************************/
int myAtoi(char *str)
{
	long res = 0;
	int flag = 1; //默认表示正号
	while(*str == SPACE){str++;} 
	switch(*str)
	{
		case MINUS:
			flag = -1;
		case POSITIVE:
			str++;
	}

    if(*str < 48 && *str > (48+9) )	return 0;//第一个字符不在0-9之间直接返回 
 	while(*str >= 48 && *str <= (48+9) )//0~9
 	{
 		res = res * 10 + (*str - 48);//字符转成数字
 		if((int)res != res) //溢出
 			return ( flag == 1) ? (INT_MAX) : (INT_MIN);
 		str++;
 	}
 	res *= flag;//加上符号位
 	return (int)res;
}


int main()
{
	int ret = 0;
 	printf("string is:%s\n", str);
 	ret = myAtoi(str);   
    printf("integer is:%d\n", ret);
    return 0;
}

