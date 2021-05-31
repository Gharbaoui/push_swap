#include "push_swap.h"

void ops_intraction(t_stack *a, t_stack *b)
{
    char *op = malloc(4);
    op[3] = 0;
    while (1)
    {
        read(0, op, 3);
        if (op[2] == '\n')
            op[2] = 0;
        if (!strcmp(op, "pa"))
            push_value(a, b);
        else if (!strcmp(op, "pb"))
            push_value(b, a);
        else if (!strcmp(op, "sa"))
            swap_top_stack(a);
        else if (!strcmp(op, "sb"))
            swap_top_stack(b);
        else if (!strcmp(op, "ra"))
            rotat_s(a);
        else if (!strcmp(op, "rb"))
            rotat_s(b);
        else if (!strcmp(op, "rra"))
            reverse_rotat_s(a);
        else if (!strcmp(op, "rrb"))
            reverse_rotat_s(b);
        if (*op != '\n')
        {
            print_stack(a, "A");
            print_stack(b, "B");
        }
    }
}
