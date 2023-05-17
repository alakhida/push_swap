#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>


typedef struct s_data
{
    int a_max_size;
    int *a_list;
} t_data;

int print_error(int i);
int	is_valid_inputs(int ac, char **argv);
char *get_argv(char **argv);
int	is_int(const char *str);
void free_2d(char **str);
size_t len_2d(char **str);
void sort(char **av);
void swap(t_data *stack);
void rotate(t_data *stack);
void reverse_rotate(t_data *stack);
void push_stack(t_data *stack_from, t_data *stack_to);


 #endif