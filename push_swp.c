#include "push_swap.h"

int main(int argc, char **argv)
{
    char *op = malloc(4);
    op[3] = 0;
    t_stack *a;
    t_stack *b;
    int err;

    a = take_inputs(argv, argc - 1, &err);
    ///// check here err variable is if that so exit
    b = empty_stack(argc - 1);
    b->topindex = b->size;
    while (1)
    {
        read(0, op, 3);
        if (!strcmp(op, "pa"))
            push_value(a, b);
        else if (!strcmp(op, "pb"))
            push_value(b, a);
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
