#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char	*solution(const char* number, int k)
{
	int		i;
	int		len;
	int		start;
	int		end;
	int		max_index;
	char	*ret;

	len = strlen(number) - k;
	if (!(ret = (char *)malloc(sizeof(char) * (len + 1))))
	{
		printf("malloc error: ret << solution\n");
		return (NULL);
	}]
	ret[len] = '\0';
	i = -1;
	start = -1;
	end = k;
	max_index = 0;
	while (++i < len)
	{
		while (++start <= end)
			max_index = number[max_index] >= number[start] ? max_index : start;
		ret[i] = number[max_index];
		start = max_index;
		end++;
	}
	return (ret);
}