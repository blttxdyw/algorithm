#include <stdio.h>



/*
给出一个32位的有符号整数,你需要将这个整数中每位上的数字进行反转。
示例 1:
    输入: 123
    输出: 321
示例 2:
    输入: -123
    输出: -321
示例 3:
    输入: 120
    输出: 21
假设我们的环境只能存储得下 32 位的有符号整数,
则其数值范围为 [−2^31,  2^31 − 1]。请根据这个假设,如果反转后整数溢出那么就返回 0。

题目来源:力扣<<LeetCode>>
链接:https://leetcode-cn.com/problems/
著作权归领扣网络所有。商业转载请联系官方授权,非商业转载请注明出处。
*/


/*****************************************************
@funtion: integer_reverse
@description: reverse a integer
@param: x is the target will be reverse
@return: the integer reversed
****************************************************/
int integer_reverse(int x)
{
	long temp = 0;
	if(x == 0)return x;
	while(x != 0)
	{
        temp = temp * 10 + x % 10;
        x = x / 10;		
	}
    return ( (temp > 2147483647) || (temp < -2147483648) ? 0 : temp );
}


int main()
{
    int num = 0;
    printf("please input a num:");
    scanf("%d", &num);
    printf("before reverse is %d\n", num);
    num = integer_reverse(num);
    printf("later reverse is %d\n", num);
    return 0;
}
