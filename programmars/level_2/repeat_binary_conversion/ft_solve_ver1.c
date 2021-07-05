#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char    *ft_putnbr(int sum);
int* solution(const char* s);

int		main(void)
{
	char	*str_1 = "110010101001";
	char	*str_2 = "01110";
	char	*str_3 = "1111111";

	int		*ret_1 = solution(str_1);
	int		*ret_2 = solution(str_2);
	int		*ret_3 = solution(str_3);

	printf("repeat: %d, zero_cnt: %d\n", ret_1[0], ret_1[1]);
	printf("repeat: %d, zero_cnt: %d\n", ret_2[0], ret_2[1]);
	printf("repeat: %d, zero_cnt: %d\n", ret_3[0], ret_3[1]);
}

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int* solution(const char* s) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int     i;
	int		j;
    int     sum;
    int     zero_cnt;
    int     *result;
    char    *cpy;
    
	j = 0;
    zero_cnt = 0;
    if (!(result = (int *)calloc(2, sizeof(int))))
        return (NULL);
    if (!(cpy = (char *)malloc(sizeof(char) * (strlen(s) + 1))))
	{
		free(result);
        return (NULL);
	}
	cpy[strlen(s)] = '\0';
    strcpy(cpy, s);
    while (strcmp(cpy, "1") != 0)
    {
		j++;
		if (j > 20)
			sleep(10);
        result[0] += 1;
		sum = 0;
        i = -1;
        while (cpy[++i])
        {
            if (cpy[i] == '0')
                zero_cnt++;
            else if (cpy[i] == '1')
                sum++;
        }
        free(cpy);
        cpy = ft_putnbr(sum);
    }
    result[1] = zero_cnt;
    return (result);
}

char    *ft_putnbr(int sum)
{
    int     len;
    int     tmp;
    char    *ret;
    
    len = 0;
    tmp = sum;
    while (tmp)
    {
        len++;
        tmp /= 2;
    }
    if (!(ret = (char *)malloc(sizeof(char) * (len + 1))))
        return (NULL);
    ret[len] = '\0';
    while (len--)
    {
        ret[len] = '0' + sum % 2;
        sum /= 2;
    }
    return (ret);
}