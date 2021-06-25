#include "../includes/ft_solve.h"

char	**ft_solve(const char *param0[], int param0_len)
{
	int		i;
	char	*cpy_str;
	t_list	*list;
	char	**answer;

	if (!param0 || !param0_len)
		return (NULL);
	i = -1;
	list = NULL;
	while (++i < param0_len)
	{
		// 확장자 검사 & 분리
		if (!(cpy_str = ft_parse_extension(param0[i])))
			continue;
		// directory 검사 & 분리
		if (!(cpy_str = ft_parse_directory(cpy_str)))
			continue;
		// version 검사 & 분리
		if (!(cpy_str = ft_parse_version(cpy_str)))
			continue;
		// file명 검사
		if (!(cpy_str = ft_parse_file(cpy_str)))
			continue;
		// cpy_str을 리스트에서 비교 및 (삽입 or 카운트)
		if (!(list = ft_insert_string(list, cpy_str)))
			continue;
	}
	// 모든 string 검사 완료 => 2차원 배열에 return
	answer = ft_make_answer(list);
	return (answer);
}

char	**ft_make_answer(t_list *list)
{
	int		i;
	int		len;
	char	**answer;
	t_list	**cur;

	if (!list)
		return (NULL);
	len = ft_list_len(list);
	// answer 할당
	if (!(answer = (char **)malloc(sizeof(char *) * (len * 2))))
	{
		ft_free_list(list);
		list = NULL;
		return (NULL);
	}
	i = 0;
	cur = &list;
	while (i < (len * 2))
	{
		if ((*cur)->count > 1)
		{
			answer[i] = (*cur)->str;
			answer[i + 1] = ft_itoa((*cur)->count);
			i += 2;
		}
		cur = &((*cur)->next);
	}
	ft_free_list(list);
	list = NULL;
	return (answer);
}

int		ft_compare_str(char *dst, char *src)
{
	if (!dst || !src)
		return (0);
	while (*dst && *src)
	{
		if (*dst != *src)
			return (0);
		dst++;
		src++;
	}
	if (*dst != *src)
		return (0);
	return (1);
}
