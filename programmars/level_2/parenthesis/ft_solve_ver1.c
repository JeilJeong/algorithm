#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct  s_stack
{
    int             data;
    struct s_stack  *next;
}               t_stack;

t_stack *ft_create_node(int data);
int     ft_stack_push(t_stack **stack, int data);
t_stack *ft_stack_pop(t_stack **stack);
int     ft_is_empty(t_stack *stack);

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
bool solution(const char* s) {
    int     len;
    int     i;
    int     check;
    t_stack *stack;
    
    len = strlen(s);
    i = -1;
    check = 0;
    stack = NULL;
    while (++i < len)
    {
        if (s[i] == '(')
            ft_stack_push(&stack, '(');
        else if (s[i] == ')')
        {
            if (!ft_stack_pop(&stack))
                return (false);
        }
    }
    return (ft_is_empty(stack));
}

t_stack *ft_create_node(int data)
{
    t_stack *ret;
    
    if (!(ret = (t_stack *)calloc(1, sizeof(t_stack))))
        return (NULL);
    ret->data = data;
    ret->next = NULL;
    return (ret);
}

int     ft_stack_push(t_stack **stack, int data)
{
    t_stack *node;
    t_stack *cur;
    
    if (!stack)
        return (0);
    node = ft_create_node(data);
    if (!(*stack))
    {
        *stack = node;
        return (1);
    }
    cur = *stack;
    while (cur->next)
        cur = cur->next;
    cur->next = node;
    return (1);
}

t_stack *ft_stack_pop(t_stack **stack)
{
    t_stack  *cur;
    t_stack  *before;
    
    if (!stack || !(*stack))
        return (NULL);
    cur = (*stack);
    before = NULL;
    while (cur->next)
    {
        before = cur;
        cur = cur->next;
    }
    if (!before)
        (*stack) = NULL;
    else
        before->next = NULL;
    return (cur);
}

int     ft_is_empty(t_stack *stack)
{
    if (!stack)
        return (1);
    return (0);
}