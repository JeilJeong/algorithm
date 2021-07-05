#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long* solution(long long numbers[], size_t numbers_len) {
    int         i;
    long long   *ret;
    
    if (!(ret = (long long *)calloc(numbers_len, sizeof(long long))))
    {
        printf("calloc error: ret << solution\n");
        return (NULL);
    }
    i = -1;
    while (++i < numbers_len)
    {
        if (numbers[i] % 2 == 0)
            ret[i] = numbers[i] + 1;
        else
           ret[i] = numbers[i] + ((numbers[i] ^ (numbers[i] + 1)) + 1) / 4;
    }
    return (ret);
}