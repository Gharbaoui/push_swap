#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;
    int err;

    a = take_inputs(argv, argc - 1, &err);
    ///// check here err variable is if that so exit
    b = empty_stack(argc - 1);
    b->topindex = b->size;
    swap_f_elements(a, b);
    //ops_intraction(a, b);
    

}
