#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_SIZE    100000

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
bool solution(const char* s) {
    int     count;
    
    count = 0;
    while (*s)
    {
        if (count < 0)
            return (false);
        count += (*s == '(' ? 1 : -1);
        s++;
    }
    return (count == 0 ? true : false);
}