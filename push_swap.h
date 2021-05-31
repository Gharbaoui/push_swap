#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
//////// steps codes [-1:"pa", 0:"pb", 1:"sa", 2:"sb", 3:"ss", 4:"ra", 5:"rb", 6:"rr", 7:"rra", 8:"rrb", 9:"rrr"]
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

//// sort1
void sort_three_elem(t_stack *a);
//// sort2
void swap_f_elements(t_stack *a, t_stack *b);
int *get_array_from_stack(t_stack *s, int *size);
void get_steps_for_ftop(t_stack *a, t_stack *b, int sm, int ssm);
int index_of(t_stack *a, int num);
void move_according_to_steps(t_stack *a, int diff_to_top);
int get_steps_required(t_stack *a, int elm_index);

///// merg sort
int *get_array_part(int *arr, int l, int r);
void merg_sort(int *arr, int l, int r);
void merg(int *arr, int l, int r, int mid);
void merg_two_sorted(int *arr, int *left, int *right, long both);
long conctnate_two_nums(int a, int b);
void recover_nums(long both, int *a, int *b);
