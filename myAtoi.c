#include <stdio.h>

char str[] = "  12345 hell 12333";

#define SPACE 32
#define MINUS 45
#define POSITIVE 43
#define INT_MAX 2147483647
#define INT_MIN -2147483648


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

    if(*str < 48 && *str > (48+9) )	return 0;
 	while(*str >= 48 && *str <= (48+9) )
 	{
 		res = res * 10 + (*str - 48);
 		if((int)res != res) return ( flag == 1) ? (INT_MAX) : (INT_MIN);
 		str++;
 	}
 	res *= flag;
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

