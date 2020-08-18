#include <stdio.h>

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
