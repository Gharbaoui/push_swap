#include "push_swap.h"

void sort_three_elem(t_stack *a)
{
    if (a->arr[a->topindex] > a->arr[a->topindex + 1])
    {
        if (a->arr[a->topindex + 1] < a->arr[a->topindex + 2])
        {
            if (a->arr[a->topindex + 2] > a->arr[a->topindex]){
                printf("sa\n");
               swap_top_stack(a);
            }
            else{
                printf("ra\n");
                rotat_s(a);
            }
        }else
        {
            printf("sa\n");
            printf("rra\n");
            swap_top_stack(a);
            reverse_rotat_s(a);
        }
    }
    else {
        if (a->arr[a->topindex] > a->arr[a->topindex + 2]){
            printf("rra\n");
            reverse_rotat_s(a);
        }
        else if (a->arr[a->topindex + 1] > a->arr[a->topindex + 2])
        {
            printf("sa\n");
            printf("ra\n");
            swap_top_stack(a);
            rotat_s(a);
        }
    }
}
