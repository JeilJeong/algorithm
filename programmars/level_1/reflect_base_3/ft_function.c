#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct  s_node
{
    int             digit;
    struct s_node   *next;
}               t_node;

int     solution(int n);
t_node  *ft_free_list(t_node *tmp);
t_node  *ft_create_node(int digit);
void    ft_insert_node(t_node **head, t_node *node);
t_node  *ft_convert_base_to_3(int n);
int     ft_convert_base_to_10(t_node *num_list);

int     solution(int n) {
    int     result;
    t_node  *tmp;

    tmp = ft_convert_base_to_3(n);   
    result = ft_convert_base_to_10(tmp);
    ft_free_list(tmp);
    return (result);
}

t_node  *ft_free_list(t_node *tmp)
{
    if (tmp->next)
        tmp->next = ft_free_list(tmp->next);
    if (!tmp->next)
    {
        free(tmp);
        tmp = NULL;
        return (tmp);
    }
    return (tmp);
}

t_node  *ft_create_node(int digit)
{
    t_node  *ret;

    while (!(ret = (t_node *)malloc(sizeof(t_node))))
        printf("malloc error: ft_create_node\n");
    ret->digit = digit;
    ret->next = NULL;
    return (ret);
}

void    ft_insert_node(t_node **head, t_node *node)
{
    t_node  *temp;

    temp = NULL;
    if (!(node))
        return ;
    if (!(*head))
        *head = node;
    else
    {
        temp = *head;
        node->next = temp;
        *head = node;
    }
}

t_node  *ft_convert_base_to_3(int n)
{
    t_node  *ret;
    t_node  *node;


    ret = NULL;
    while (n / 3)
    {
        node = ft_create_node(n % 3);
        ft_insert_node(&ret, node);
        n = n / 3;
    }
    node = ft_create_node(n);
    ft_insert_node(&ret, node);
    return (node);
}

int     ft_convert_base_to_10(t_node *num_list)
{
    int     sum;
    int     exp;

    sum = 0;
    exp = 1;
    while (num_list)
    {
        sum += (num_list->digit) * (exp);
        exp *= 3;
        num_list = num_list->next;
    }
    return (sum);
}