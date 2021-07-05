#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long   ft_mini_num(long long num);

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
        ret[i] = ft_mini_num(numbers[i]);
    return (ret);
}

long long   ft_mini_num(long long num)
{
    int         j;
    int         count;
    long long   ret;
    
    j = 0;
    count = 3;
    while (count > 2)
    {    
        count = 0;
        ret = num + (++j);
        ret = num ^ ret;
        while (ret)
        {
            count += ret % 2 == 1 ? 1 : 0;
            ret /= 2;
        }
    }
    return (num + j);
}