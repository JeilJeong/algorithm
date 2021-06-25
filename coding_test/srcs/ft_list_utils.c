#include "../includes/ft_solve.h"

int		ft_list_len(t_list *list)
{
	int		len;
	t_list	**cur;

	if (!list)
		return (0);
	cur = &list;
	len = 0;
	while (*cur)
	{
		if ((*cur)->count > 1)
			len++;
		cur = &((*cur)->next);
	}
	return (len);
}

t_list	*ft_create_node(void)
{
	t_list	*ret;

	if (!(ret = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	ret->count = 0;
	ret->str = NULL;
	ret->next = NULL;
	return (ret);
}

t_list	*ft_insert_string(t_list *list, char *str)
{
	if (!str)
		return (NULL);
	if (!list)
	{
		if (!(list = ft_create_node()))
		{
			free(str);
			str = NULL;
			return (NULL);
		}
		list->str = str;
		list->count += 1;
		return (list);
	}
	else
	{
		if (ft_compare_str(list->str, str))
		{
			list->count += 1;
			free(str);
			str = NULL;
			return (list);
		}
		list->next = ft_insert_string(list->next, str);
	}
	return (list);
}