#include "../includes/ft_solve.h"

char	*ft_memcpy(char *dst, char *src, int len)
{
	int		i;

	if (!dst || !src || !len)
		return (dst);
	i = -1;
	while (++i < len)
		dst[i] = src[i];
	return (dst);
}

t_list	*ft_free_list(t_list *list)
{
	if (!list)
		return (NULL);
	if (list->next)
		list->next = ft_free_list(list->next);
	free(list);
	list = NULL;
	return (NULL);
}

void	ft_free_answer(char **answer)
{
	if (!answer)
		return ;
	while (*answer)
	{
		free(*answer);
		*answer = NULL;
		answer++;
	}
}