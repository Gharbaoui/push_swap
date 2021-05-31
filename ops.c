#include "push_swap.h"

void swap_top_stack(t_stack *s)
{
    int index;
    if (s && s->size > 1)
    {
        index = s->topindex;
        ft_swap(&(s->arr[index]), &(s->arr[index + 1]));
    }
}

void swap_stacks(t_stack *a, t_stack *b)
{
    swap_top_stack(a);
    swap_top_stack(b);
}

void ft_swap(int *a, int *b)
{
    int c;
    
    c = *a;
    *a = *b;
    *b = c;
}


void push_value(t_stack *dst, t_stack *src)
{
    int val;
    
    if (src->size - src->topindex > 0)
    {
        val = src->arr[src->topindex];
        src->topindex++;
        dst->topindex--;
        dst->arr[dst->topindex] = val;
    }
}

void reverse_rotat_s(t_stack *s)
{
    int lastindex;
    
    if (s)
    {
        lastindex = s->size - 1;
        while (lastindex > s->topindex)
        {
           ft_swap(&(s->arr[lastindex]), &(s->arr[lastindex - 1]));
            lastindex--;
        }
    }
}

void rotat_s(t_stack *s)
{
    int tindex;

    if (s)
    {
        tindex = s->topindex;
        while (tindex < s->size - 1)
        {
            ft_swap(&(s->arr[tindex]), &(s->arr[tindex + 1]));
            tindex++;
        }        
    }
}




