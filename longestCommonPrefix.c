#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char str[3][10] = {"flower","flow","flowght"};

#if 1
char * longestCommonPrefix(char ** strs, int strsSize){
    if(strsSize == 0) return "";  
    for(int i=0; i<strlen(strs[0]); i++)
    {   
        for(int j=1; j<strsSize; j++)
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
