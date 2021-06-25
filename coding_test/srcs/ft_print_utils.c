#include "../includes/ft_solve.h"

void	ft_print_answer(char **answer)
{
	int		i;

	i = 0;
	if (!answer)
		return ;
	while (*answer)
	{
		printf("%s ", *answer);
		if (i % 2 == 1)
			printf("\n");
		i++;
		answer++;
	}
}

void	ft_print_list(t_list *list)
{
	if (!list)
		return ;
	printf("%s ", list->str);
	printf("%d\n", list->count);
	ft_print_list(list->next);
}
