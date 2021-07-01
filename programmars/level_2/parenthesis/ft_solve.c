#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
bool solution(const char* s) {
    int     len;
    int     i;
    int     check;
    
    len = strlen(s);
    i = -1;
    check = 0;
    while (++i < len)
    {
        if (s[i] == '(')
            check += 1;
        else if (s[i] == ')')
            check -= 1;
    }
    return (check == 0 ? true : false);
}