#ifndef FT_SOLVE_H
# define FT_SOLVE_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>

typedef struct	s_list
{
	int				count;
	char			*str;
	struct s_list	*next;
}				t_list;

// ft_solve.c
char	**ft_solve(const char *param0[], int param0_len);
char	**ft_make_answer(t_list *list);
int		ft_compare_str(char *dst, char *src);

// ft_mem_utils.c
char	*ft_memcpy(char *dst, char *src, int len);
t_list	*ft_free_list(t_list *list);
void	ft_free_answer(char **answer);

// ft_list_utils.c
int		ft_list_len(t_list *list);
t_list	*ft_create_node(void);
t_list	*ft_insert_string(t_list *list, char *str);

// ft_string_utils.c
char	*ft_itoa(int n);
int		ft_isnum(char c);
int		ft_islower(char c);
int		ft_issign(char c, char compare);
int		ft_strlen(const char *str);

// ft_parse_utils.c
char	*ft_parse_file(char *str);
char	*ft_parse_version(char *str);
char	*ft_parse_directory(char *str);
char	*ft_parse_extension(const char *str);

// ft_print_utils.c
void	ft_print_answer(char **answer);
void	ft_print_list(t_list *list);

#endif