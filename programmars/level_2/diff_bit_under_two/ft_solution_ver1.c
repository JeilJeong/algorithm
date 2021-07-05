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

int     *ft_bit_num(long long num)
{
    int     i;
    int     *bit;
    
    if (!(bit = (int *)calloc(64, sizeof(int))))
    {
        printf("calloc error: ft_bit_num\n");
        return (NULL);
    }
    i = -1;
    while (++i < 64)
    {
        bit[63 - i] = (int)(num % 2);
        num /= 2;
    }
    return (bit);
}

long long   ft_mini_num(long long num)
{
    int         i;
    int         j;
    int         sum;
    int         *bit_num;
    long long   ret;
    
    j = 1;
    ret = num + j;
    while (1)
    {    
        bit_num = ft_bit_num(num);
        i = -1;
        while (++i < 64)
        {
            bit_num[63 - i] -= (int)(ret % 2);
            ret /= 2;
        }
        sum = 0;
        while (i--)
            sum += bit_num[i] < 0 ? bit_num[i] * -1 : bit_num[i];
        if (sum > 2)
        {
            ret = num + (++j);
            free(bit_num);
        }
        else
            break;
    }
    return (num + j);
}