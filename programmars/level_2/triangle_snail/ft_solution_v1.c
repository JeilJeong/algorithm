#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

int* solution(int n);

int		main(void)
{
	int		*ret;
	int		n_1 = 10;
	int		i = -1;

	ret = solution(n_1);
	if (ret)
	{
		while (++i < (n_1 * (n_1 + 1)) / 2)
			printf("%d ", ret[i]);
		printf("\n");
	}
}

int* solution(int n)
{
    int     len;
    int     count;
	int		repeat;
    int     i;
    int     j;
    int     p;
    int     *ret;
    int     **tri;
    int     repeat_n;
    
    if (!n)
        return (NULL);
    if (!(tri = (int **)calloc(n, sizeof(int *))))
    {
        printf("calloc error: tri << solution\n");
        return (NULL);
    }
    i = -1;
    while (++i < n)
    {
        if (!(tri[i] = (int *)calloc(i + 1, sizeof(int))))
        {
            printf("calloc error: tri[%d] << solution\n", i);
            while (--i >= 0)
            {
                free(tri[i]);
                tri[i] = NULL;
            }
            free(tri);
            return (NULL);
        }
    }
    len = (n * (n + 1)) / 2;
    count = 0;
    i = -1;
    j = 0;
    repeat_n = n;
    while (count < len)
    {
		repeat = -1;
        while (++repeat < repeat_n && count < len)
        {
            tri[++i][j] = ++count;
            printf("tri[%d][%d] = %d\n", i, j, tri[i][j]);
        }
        repeat_n--;
		repeat = -1;
        while (++repeat < repeat_n && count < len) 
        {
            tri[i][++j] = ++count;
            printf("    tri[%d][%d] = %d\n", i, j, tri[i][j]);
        }
        repeat_n--;
        repeat = -1;
        while (++repeat < repeat_n && count < len)
        {
            tri[--i][--j] = ++count;
            printf("        tri[%d][%d] = %d\n", i, j, tri[i][j]);
        }
        repeat_n--;
    }
    if (!(ret = (int *)calloc(len, sizeof(int))))
    {
        printf("calloc error: ret << solution\n");
        i = -1;
        while (++i < n)
        {
            free(tri[i]);
            tri[i] = NULL;
        }
        free(tri);
        return (NULL);
    }
    i = -1;
    p = -1;
    while (++i < n)
    {
        j = -1;
		repeat = i + 1;
        while (++j < repeat)
            ret[++p] = tri[i][j];
    }
    return (ret);
}