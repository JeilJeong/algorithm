#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE    100000

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
bool solution(const char* s) {
    int     len;
    int     i;
    int     j;
    int     stack[MAX_SIZE];
    
    len = strlen(s);
    i = -1;
    j = 0;
    memset(stack, 0, sizeof(stack));
    while (++i < len)
    {
        if (s[i] == '(')
        {
            stack[j] = '(';
            j++;
        }
        else if (s[i] == ')')
        {
            j--;
            if (j < 0)
                return (false);
            stack[j] = 0;
        }
    }
    return (stack[0] == 0 ? true : false);
}