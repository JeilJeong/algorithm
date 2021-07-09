#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* number, int k) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int     i;
    int     index;
    int     len;
    int     max_index;
    int     ret_len;
    char    *ret;
    
    ret_len = strlen(number) - k;
    if (!(ret = (char *)calloc(ret_len, sizeof(char))))
    {
        printf("calloc error: ret << solution\n");
        return (NULL);
    }
    i = 0;
    index = -1;
    max_index = 0;
    len = k;
    while (++index < ret_len)
    {
        while (++i <= len)
            max_index = number[max_index] >= number[i] ? max_index : i;
        ret[index] = number[max_index];
        i = max_index++;
        len++;
    }
    return (ret);
}