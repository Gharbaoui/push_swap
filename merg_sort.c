#include "push_swap.h"

void merg_sort(int *arr, int l, int r)
{
    int mid;
    
    if (r > l)
    {
        mid = l + (r -l) / 2;
        merg_sort(arr, l, mid);
        merg_sort(arr, mid + 1, r);
        merg(arr, l, r, mid);
    }
}

void merg(int *arr, int l, int r, int mid)
{
    int *left;
    int *right;

    left = get_array_part(arr, l, mid);
    right = get_array_part(arr, mid + 1, r);
    merg_two_sorted(arr, left, right, conctnate_two_nums(l, r));
    free(left);
    free(right);
}


void merg_two_sorted(int *arr, int *left, int *right, long both)
{
    //// that both variable will be used as variable
    int l;
    int r;
    int i;
    int j;
    int k;

    recover_nums(both, &l, &r);
    both = l + (r - l) / 2;
    k = l;
    i = 0;
    j = 0;
    while (i < (both - l + 1) && j < (r - both))
    {
        if (left[i] < right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else if (right[j] < left[i])
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < (both - l + 1))
    {
        arr[k] = left[i];
        k++;
        i++;
    }
    while (j < (r - both))
    {
        arr[k] = right[j];
        k++;
        j++;
    }
}


int *get_array_part(int *arr, int l, int r)
{
    int i;
    int j;
    int *newarr;
    
    newarr = malloc(sizeof(int) * (r - l));
    i = l - 1;
    j = -1;
    while (++i <= r)
        newarr[++j] = arr[i];
    return newarr;
}

long conctnate_two_nums(int a, int b)
{
    long both;
    
    both = a;
    both = both << (sizeof(int) * 8);
    both = both | b;
    return both;
}

void recover_nums(long both, int *a, int *b)
{
    *a = both >> (sizeof(int) * 8);
    both = both << (sizeof(int) * 8);
    *b = both >> (sizeof(int) * 8);
}
