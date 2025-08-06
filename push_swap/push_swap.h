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

typedef struct s_moves
{
    int stack_moves_count;
    char *stack_moves_type;
} t_moves;

int print_error(int i);
int	is_valid_inputs(int ac, char **argv);
char *get_argv(char **argv);
int	is_int(const char *str);
void free_2d(char **str);
size_t len_2d(char **str);
void sort(int count,char **av);
void swap(t_data *stack);
void rotate(t_data *stack);
void reverse_rotate(t_data *stack);
void push_stack(t_data *stack_from, t_data *stack_to);
int	sort_three_numbers(t_data *stack_a);
void    ft_putstr(char *str);
int four_fifth_case(t_data *stack_a, t_data *stack_b, int count);
int get_min_num(t_data *stack);
int get_num_position(t_data *stack, int num);
t_moves get_moves_needed(t_data *stack, int pos);
void execute_moves(t_moves moves, t_data *stack);
void sort_big_num(t_data *stack_a, t_data *stack_b, int range_from, int range_to);
int check_is_sorted(t_data *stack);
int get_big_num(t_data *stack);
int sort_two_num(t_data *stack_a);



 #endif