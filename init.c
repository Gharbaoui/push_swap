#include "push_swap.h"

t_stack *empty_stack(int size)
{
    t_stack *s;
    s = malloc(sizeof(t_stack));
    s->topindex = 0;
    s->size = size;
    s->arr = malloc(sizeof(int) * size);
    return s;
}
t_stack *take_inputs(char **args, int size, int *error)
{
    t_stack *s;
    int i;

    i = 0;
    *error = 0;
    s = empty_stack(size);
    while (++i < size + 1)
    {
        if (is_number(args[i]))
            s->arr[i - 1] = atoi(args[i]);
        else
        {
            *error = 1;
            free(s->arr);
            free(s);
            return NULL;
        }
    }
    return s;
}


int is_number(char *num)
{
    int i;
    int in;

    in = 0;
    i = -1;
    if (num[0] == '+' || num[0] == '-')
        num++;
    while (num[++i]){
        in = 1;
        if (ft_isdigit(num[i]) == 0)
            return 0;
    }
    if (in == 0)
        return 0;
    return 1;
}

int ft_isdigit(char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    return 0;
}

void print_stack(t_stack *s, char *name)
{
    int i;
    
    printf("Stack %s size %d index %d\n", name, s->size, s->topindex); 
    i = s->topindex - 1;
    printf ("------\n");
    while (++i < s->size)
        printf ("|%d|\n------\n", s->arr[i]);
}
