#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct s_stack
{
    int topindex;
    int *arr;
    int size;
}t_stack;

void ops_intraction(t_stack *a, t_stack *b);
int is_number(char *str);
int ft_isdigit(char num);
t_stack *take_inputs(char **args, int size, int *error);
void print_stack(t_stack *s, char *name);
t_stack *empty_stack(int size);


void swap_top_stack(t_stack *s);
void ft_swap(int *a, int *b);
void swap(int *a, int *b);

void push_value(t_stack *dst, t_stack *src);
void rotat_s(t_stack *s);
void reverse_rotat_s(t_stack *s);


void sort_three_elem(t_stack *a);


