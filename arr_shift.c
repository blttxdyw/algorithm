#include <stdio.h>

/*
@function: reverse an array 
@param: arr is the data buff need reverse
		start is the buff data start position
		end is the buff data end position
@return: none
*/
void Reverse(int *arr, int start, int end){      
    for(; start < end; start++,end--){
           int s = arr[end];
           arr[end] = arr[start];
           arr[start] = s;
      }
}



/*
@function: move an array to the left 
@param: arr is the data buff need shift
		N is the buff data number
		K is the counter need shift
@return: none
*/
void LeftShift(int* arr, int N, int K){
      K = K % N;                       
      Reverse(arr, 0, K-1);//翻转前k位          
      Reverse(arr, K, N-1);//翻转剩余数据           
      Reverse(arr, 0, N-1);//最后整体翻转           
}



/*
@function: move an array to the left 
@param: arr is the data buff need shift
		N is the buff data number
		K is the counter need shift
@return: none
*/
void RightShift(int* arr, int N, int K){
      K = K % N;                       
      Reverse(arr, N-K, N-1);         
      Reverse(arr, 0, N-1-K);//翻转剩余数据           
      Reverse(arr, 0, N-1);//最后整体翻转           
}


int main()
{
	int c=0;
	int a[] = {1,2,3,4,5,6,7,8,9};
    RightShift(a, sizeof(a)/4, 3);
    for(c=0; c< sizeof(a)/4; c++)
    	printf("%d ", a[c]);
    return 0;    
}
