#include <stdio.h>

#define mal(x,y) (x*y)  

int main()
{
	 int i = 3;
	 int a = 1;
	 int **b[5][6];
	 int *c = &a;
	 b[0][0] = &c;
	 *(*b[0][0]) = 100;
	 //a = i++*4+5;
	 //a = mal(i++, sizeof(b) + 5);  //a = i++*4+5;
	 printf("%d", a);
	 return 0;
}