#include <stdio.h>

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
