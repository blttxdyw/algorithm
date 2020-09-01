#include <stdio.h>

/*
判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

示例 1:

输入: 121
输出: true
示例 2:

输入: -121
输出: false
解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
示例 3:

输入: 10
输出: false
解释: 从右向左读, 为 01 。因此它不是一个回文数。

题目来源:力扣<<LeetCode>>
链接:https://leetcode-cn.com/problems
著作权归领扣网络所有。商业转载请联系官方授权,非商业转载请注明出处。
*/

bool isPalindrome(int x)
{
    int temp = 0;
    if(x < 0)
        return false;
    temp = integer_reverse(x);
    if(temp == x)
        return true;
    else
        return false;
}

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

    return 0;
}
