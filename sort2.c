#include "push_swap.h"

void swap_f_elements(t_stack *a, t_stack *b)
{
    //// i need to move the smallest and the second smallest to the top
    int *arrsorted;
    int size;
    
    arrsorted = get_array_from_stack(a, &size);
    merg_sort(arrsorted, 0, size - 1);
    get_steps_for_ftop(a, b, arrsorted[0], arrsorted[1]);
}


void get_steps_for_ftop(t_stack *a, t_stack *b, int sm, int ssm)
{
    int index;
    int diff_to_top;
    int i;
    
    index = index_of(a, sm);
    diff_to_top = get_steps_required(a, index);
    move_according_to_steps(a, diff_to_top);
    push_value(b, a);


    index = index_of(a, ssm);
    diff_to_top = get_steps_required(a, index);
    move_according_to_steps(a, diff_to_top);
    push_value(b, a);
    
    print_stack(a, "A");
    print_stack(b, "B");
}

void move_according_to_steps(t_stack *a, int diff_to_top)
{
    int i;
    
    if (diff_to_top < 0)
    {
        i = (diff_to_top * (-1));
        while (i > 0)
        {
            reverse_rotat_s(a);
            i--;
        }
    }
    else
    {
        i = diff_to_top;
        while (i > 0)
        {
            rotat_s(a);
            i--;
        }
    }
}

int get_steps_required(t_stack *a, int elm_index)
{
    int to_top_w0;
    int to_top_w1;
    int to_bot; // this represents steps requird to go downwards to 
    // end up in top

    elm_index += a->topindex;
    to_top_w0 = elm_index - a->topindex;
    to_bot = elm_index - a->size;
    to_top_w1 = to_bot;
    if (to_bot < 0)
        to_top_w1 *= -1;
    if (to_top_w1 < to_top_w0)
        return to_bot;
    return to_top_w0;
}


int index_of(t_stack *a, int num)
{
    int i;
    
    i = a->topindex - 1;
    while (++i < a->size)
        if (a->arr[i] == num)
            return i - a->topindex;
    return -1;
}

int *get_array_from_stack(t_stack *s, int *size)
{
    int *arr;
    int i;
    int j;

    arr = NULL;
    if (s && s->size)
    {
        j = -1;
        i = s->topindex - 1;
        if (size)
            *size = s->size - s->topindex;
        arr = malloc(sizeof(int) * s->size);
        while (++i < s->size)
            arr[++j] = s->arr[i];
    }
    return arr;
}
