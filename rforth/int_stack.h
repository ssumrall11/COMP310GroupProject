// int_stack.h - interface to the int_stack
#ifndef INT_STACK_H
#define INT_STACK_H

#include "types.h"

// stack basics
extern void int_stack_init(int_stack_t *stk, int capacity);
extern int int_stack_push(int_stack_t *stk, int value);
extern int int_stack_pop(int_stack_t *stk, int *top_value);
extern int int_stack_top(int_stack_t *stk, int *top_value);

// output methods
extern void int_stack_print(int_stack_t *stk, FILE *file);
extern void int_stack_cr(FILE *file); // having this as its own function is kinda but I have OCD
extern void int_stack_dot(int_stack_t *stk, FILE *file);
extern void int_stack_emit(int_stack_t *stk, FILE *file);

// forth single element stack manipulators
extern int int_stack_swap(int_stack_t *stk);
extern int int_stack_dup(int_stack_t *stk);
extern int int_stack_over(int_stack_t *stk);
extern int int_stack_drop(int_stack_t *stk);
extern int int_stack_rot(int_stack_t *stk);

// forth double element stack manipulators
extern int int_stack_2swap(int_stack_t *stk);
extern int int_stack_2dup(int_stack_t *stk);
extern int int_stack_2over(int_stack_t *stk);
extern int int_stack_2drop(int_stack_t *stk);
extern int int_stack_2rot(int_stack_t *stk);

// forth math operations
extern int int_stack_add(int_stack_t *stk);
extern int int_stack_subtract(int_stack_t *stk);
extern int int_stack_multiply(int_stack_t *stk);
extern int int_stack_divide(int_stack_t *stk);
extern int int_stack_mod(int_stack_t *stk);
extern int int_stack_dividemod(int_stack_t *stk);

// forth boolean operations
extern int int_stack_equal(int_stack_t *stk);
extern int int_stack_less(int_stack_t *stk);
extern int int_stack_greater(int_stack_t *stk);
extern int int_stack_invert(int_stack_t *stk);
extern int int_stack_and(int_stack_t *stk);
extern int int_stack_or(int_stack_t *stk);

// forth miscellaneous operations
extern int int_stack_depth(int_stack_t *stk);
extern char* int_stack_if(int_stack_t *stk,char **toLine);

//extern char* int_stack_do(int_stack_t *stk,int *min,int *max,char **toLine);

#endif // INT_STACK_H