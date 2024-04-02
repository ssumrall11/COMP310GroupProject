// int_stack.c
#include <stdlib.h>
#include <stdio.h>
#include "int_stack.h"

void int_stack_init(int_stack_t *stk,int capacity) {
  SLIST_INIT(&stk->head);
  stk->size=0;
  stk->capacity=capacity;
}

int int_stack_push(int_stack_t *stk,int value){
  if(stk->size>=stk->capacity){
    printf("Stack is at full capacity.\n");
    return 0; // fail
  }
  int_entry_t *newEntry=malloc(sizeof(int_entry_t));
  if(newEntry){
    newEntry->value=value;
    SLIST_INSERT_HEAD(&stk->head,newEntry,entries);
    stk->size++;
    return 1; //success
  }
  return 0; // fail
}

int int_stack_pop(int_stack_t *stk,int *top_value){
  int_entry_t *entry=SLIST_FIRST(&stk->head);
  if(entry){
    int value=entry->value;
    SLIST_REMOVE_HEAD(&stk->head,entries);
    free(entry);
    stk->size--;
    *top_value=value;
    return 1; // success
  }
  return 0; // fail
}

int int_stack_top(int_stack_t *stk,int *top_value){
  int_entry_t *entry=SLIST_FIRST(&stk->head);
  if(entry){
    *top_value=entry->value;
    return 1; // success
  }
  return 0; // fail
}

// prints out the full stack
void int_stack_print(int_stack_t *stk,FILE *file){
  fprintf(file,"<%d> [",stk->size);
  int_entry_t *entry;
  if(stk->size!=0){
    int_entry_t **entries=malloc(stk->size * sizeof(int_entry_t *));
    if(entries==NULL){
      fprintf(stderr,"Memory allocation failed\n");
      exit(EXIT_FAILURE);
    }
    int i=0;
    // Iterate through the stack and store pointers to elements in an array
    SLIST_FOREACH(entry,&stk->head,entries){
      entries[i++]=entry;
    }
    // Print the elements in reverse order from the array
    for(i=stk->size-1;i>0;i--) {
      fprintf(file,"%d ",entries[i]->value);
    }
    fprintf(file,"%d",entries[0]->value);
    free(entries);
  }
  fprintf(file,"] ");
}

void int_stack_cr(FILE *file){
  fprintf(file,"\n");
}

void int_stack_dot(int_stack_t *stk, FILE *file){
  if(stk->size<1){
    return;
  }
  int top_value;
  int_stack_pop(stk,&top_value);
  fprintf(file,"%d ",top_value);
}

void int_stack_emit(int_stack_t *stk, FILE *file){
  if(stk->size<1){
    return;
  }
  int top_value;
  int_stack_pop(stk,&top_value);
  fprintf(file,"%c ",top_value);
}

/* Functions for FORTH langauge stack operators */

/*single value stack operations*/

// swaps the spots of the top two values in the stack
int int_stack_swap(int_stack_t *stk){
  if(stk->size<2){
    return 0;
  }
  int top_value,next_to_top_value;
  int_stack_pop(stk,&top_value);
  int_stack_pop(stk,&next_to_top_value);
  int_stack_push(stk,top_value);
  return int_stack_push(stk,next_to_top_value); // success only if last operation succeeds
}

// duplicates the top value on the stack
int int_stack_dup(int_stack_t *stk){
  if(stk->size<1){
    return 0;
  }
  int top_value;
  int_stack_top(stk,&top_value);
  return int_stack_push(stk,top_value); // success only if last operation succeeds
}

// duplicates the second-to-top value to the top the stack
int int_stack_over(int_stack_t *stk){
  if(stk->size<2){
    return 0;
  }
  int top_value,next_to_top_value;
  int_stack_pop(stk,&top_value);
  int_stack_top(stk,&next_to_top_value);
  int_stack_push(stk,top_value);
  return int_stack_push(stk,next_to_top_value); // success only if last operation succeeds
}

// deletes the top value on the stack
int int_stack_drop(int_stack_t *stk){
  if(stk->size<1){
    return 0;
  }
  int top_value; // if you want you could use this to store the value that gets deleted for future use
  return int_stack_pop(stk,&top_value); // success only if last operation succeeds
}

// moves the third value from the top to the top of the stack
int int_stack_rot(int_stack_t *stk){
  if(stk->size<3){
    return 0;
  }
  int top_value,next_to_top_value,third_from_top_value;
  int_stack_pop(stk,&top_value);
  int_stack_pop(stk,&next_to_top_value);
  int_stack_pop(stk,&third_from_top_value);
  int_stack_push(stk,next_to_top_value);
  int_stack_push(stk,top_value);
  return int_stack_push(stk,third_from_top_value); // success only if last operation succeeds
}

/*double value stack operations*/

// swaps the spots of the top two pairs of values in the stack
int int_stack_2swap(int_stack_t *stk){
  if(stk->size<4){
    return 0;
  }
  // pop of the stack
  int top_pair_first_value,top_pair_second_value,next_to_top_pair_first_value, next_to_top_pair_second_value;
  int_stack_pop(stk,&top_pair_second_value);
  int_stack_pop(stk,&top_pair_first_value);
  int_stack_pop(stk,&next_to_top_pair_second_value);
  int_stack_pop(stk,&next_to_top_pair_first_value);
  // re-add to the stack
  int_stack_push(stk,top_pair_first_value);
  int_stack_push(stk,top_pair_second_value);
  int_stack_push(stk,next_to_top_pair_first_value);
  return int_stack_push(stk,next_to_top_pair_second_value); // success only if last operation succeeds
}

// duplicates the top pair of values on the stack
int int_stack_2dup(int_stack_t *stk){
  if(stk->size<2){
    return 0;
  }
  int top_pair_first_value,top_pair_second_value;
  int_stack_pop(stk,&top_pair_second_value);
  int_stack_top(stk,&top_pair_first_value);
  int_stack_push(stk,top_pair_second_value);
  int_stack_push(stk,top_pair_first_value);
  return int_stack_push(stk,top_pair_second_value); // success only if last operation succeeds
}

// duplicates the second-to-top pair of values to the top the stack
int int_stack_2over(int_stack_t *stk){
  if(stk->size<4){
    return 0;
  }
  // pop of the stack
  int top_pair_first_value,top_pair_second_value,next_to_top_pair_first_value, next_to_top_pair_second_value;
  int_stack_pop(stk,&top_pair_second_value);
  int_stack_pop(stk,&top_pair_first_value);
  int_stack_pop(stk,&next_to_top_pair_second_value);
  int_stack_top(stk,&next_to_top_pair_first_value);
  // re-add to the stack
  int_stack_push(stk,next_to_top_pair_second_value);
  int_stack_push(stk,top_pair_first_value);
  int_stack_push(stk,top_pair_second_value);
  int_stack_push(stk,next_to_top_pair_first_value);
  return int_stack_push(stk,next_to_top_pair_second_value); // success only if last operation succeeds
}

// deletes the top pair of values on the stack
int int_stack_2drop(int_stack_t *stk){
  if(stk->size<1){
    return 0;
  }
  int top_pair_first_value,top_pair_second_value; // if you want you could use these to store the value that gets deleted for future use
  int_stack_pop(stk,&top_pair_second_value);
  return int_stack_pop(stk,&top_pair_first_value); // success only if last operation succeeds
}

// moves the third pair of values to the top of the stack
int int_stack_2rot(int_stack_t *stk){
  if(stk->size<6){
    return 0;
  }
  // pop of the stack
  int top_pair_first_value,top_pair_second_value,next_to_top_pair_first_value, next_to_top_pair_second_value,third_to_top_pair_first_value,third_to_top_pair_second_value;
  int_stack_pop(stk,&top_pair_second_value);
  int_stack_pop(stk,&top_pair_first_value);
  int_stack_pop(stk,&next_to_top_pair_second_value);
  int_stack_pop(stk,&next_to_top_pair_first_value);
  int_stack_pop(stk,&third_to_top_pair_second_value);
  int_stack_pop(stk,&third_to_top_pair_first_value);
  // re-add to the stack
  int_stack_push(stk,next_to_top_pair_first_value);
  int_stack_push(stk,next_to_top_pair_second_value);
  int_stack_push(stk,top_pair_first_value);
  int_stack_push(stk,top_pair_second_value);
  int_stack_push(stk,third_to_top_pair_first_value);
  return int_stack_push(stk,third_to_top_pair_second_value); // success only if last operation succeeds
}

/*math operators for single values*/

// removes the last two numbers on the stack, adds them together, and puts their sum back on the top of the stack
int int_stack_add(int_stack_t *stk){
  if(stk->size<2){
    return 0;
  }
  int top_value,next_to_top_value;
  int_stack_pop(stk,&top_value);
  int_stack_pop(stk,&next_to_top_value);
  return int_stack_push(stk,top_value+next_to_top_value);
}

// removes the last two numbers on the stack, subtracts the top value from the second from the top together, and puts their difference back on the top of the stack
int int_stack_subtract(int_stack_t *stk){
  if(stk->size<2){
    return 0;
  }
  int top_value,next_to_top_value;
  int_stack_pop(stk,&top_value);
  int_stack_pop(stk,&next_to_top_value);
  return int_stack_push(stk,next_to_top_value-top_value);
}

// removes the last two numbers on the stack, multiplies them together, and puts their product back on the top of the stack
int int_stack_multiply(int_stack_t *stk){
  if(stk->size<2){
    return 0;
  }
  int top_value,next_to_top_value;
  int_stack_pop(stk,&top_value);
  int_stack_pop(stk,&next_to_top_value);
  return int_stack_push(stk,top_value*next_to_top_value);
}

// removes the last two numbers on the stack, divides the second-to-top value by the top value, and puts their quotient (rounded down to an int value) back on the top of the stack
int int_stack_divide(int_stack_t *stk){
  if(stk->size<2){
    return 0;
  }
  int top_value,next_to_top_value;
  int_stack_pop(stk,&top_value);
  if(top_value==0){
    printf("ERROR: division by 0\n");
    return 0;
  }
  int_stack_pop(stk,&next_to_top_value);
  return int_stack_push(stk,next_to_top_value/top_value);
}

// removes the last two numbers on the stack, divides the second-to-top value by the top value, and puts their remainder back on the top of the stack
int int_stack_mod(int_stack_t *stk){
  if(stk->size<2){
    return 0;
  }
  int top_value,next_to_top_value;
  int_stack_pop(stk,&top_value);
  if(top_value==0){
    printf("ERROR: modulo of 0\n");
    return 0;
  }
  int_stack_pop(stk,&next_to_top_value);
  return int_stack_push(stk,next_to_top_value%top_value);
}

// removes the last two numbers on the stack, divides the second-to-top value by the top value, and puts their remainder and their quotient (rounded down to an int value) back on the top of the stack
int int_stack_dividemod(int_stack_t *stk){
  if(stk->size<2){
    return 0;
  }
  int top_value,next_to_top_value;
  int_stack_pop(stk,&top_value);
  if(top_value==0){
    printf("ERROR: division & modulo by 0\n");
    return 0;
  }
  int_stack_pop(stk,&next_to_top_value);
  int_stack_push(stk,next_to_top_value%top_value); // remainder
  return int_stack_push(stk,next_to_top_value/top_value); // quotient
}

/*logical operators for single values*/

// removes the last two numbers on the stack, tests to see if they are equal, and puts the result on the top of the stack (-1=true, 0=false)
int int_stack_equal(int_stack_t *stk){
  if(stk->size<2){
    return 0;
  }
  int top_value,next_to_top_value;
  int_stack_pop(stk,&top_value);
  int_stack_pop(stk,&next_to_top_value);
  return int_stack_push(stk,(next_to_top_value==top_value)?-1:0); // success only if last operation succeeds
}

// removes the last two numbers on the stack, tests to see if the second value is less than the top value, and puts the result on the top of the stack (-1=true, 0=false)
int int_stack_less(int_stack_t *stk){
  if(stk->size<2){
    return 0;
  }
  int top_value,next_to_top_value;
  int_stack_pop(stk,&top_value);
  int_stack_pop(stk,&next_to_top_value);
  return int_stack_push(stk,(next_to_top_value<top_value)?-1:0); // success only if last operation succeeds
}

// removes the last two numbers on the stack, tests to see if the second value is greater than the top value, and puts the result on the top of the stack (-1=true, 0=false)
int int_stack_greater(int_stack_t *stk){
  if(stk->size<2){
    return 0;
  }
  int top_value,next_to_top_value;
  int_stack_pop(stk,&top_value);
  int_stack_pop(stk,&next_to_top_value);
  return int_stack_push(stk,(next_to_top_value>top_value)?-1:0); // success only if last operation succeeds
}

// removes the last number on the stack, preforms a bitwise negation on it, and puts the result on the top of the stack
int int_stack_invert(int_stack_t *stk){
  if(stk->size<1){
    return 0;
  }
  int top_value;
  int_stack_pop(stk,&top_value);
  return int_stack_push(stk,~top_value); // success only if last operation succeeds
}

// removes the last two numbers on the stack, tests if neither is 0, and puts the result on the top of the stack (-1 for true, 0 for false)
int int_stack_and(int_stack_t *stk){
  if(stk->size<2){
    return 0;
  }
  int top_value,next_to_top_value;
  int_stack_pop(stk,&top_value);
  int_stack_pop(stk,&next_to_top_value);
  return int_stack_push(stk,(top_value==0 || next_to_top_value==0)?0:-1);
}

// removes the last two numbers on the stack, tests if both are 0, and puts the result on the top of the stack (-1 for true, 0 for false)
int int_stack_or(int_stack_t *stk){
  if(stk->size<2){
    return 0;
  }
  int top_value,next_to_top_value;
  int_stack_pop(stk,&top_value);
  int_stack_pop(stk,&next_to_top_value);
  return int_stack_push(stk,(top_value==0 && next_to_top_value==0)?0:-1);
}

// adds the current size of the stack to the top of the stack
int int_stack_depth(int_stack_t *stk){
  return int_stack_push(stk,stk->size);
}

// if(/else) statement
char* int_stack_if(int_stack_t *stk,char **toLine){
  char* line=*toLine;
  char *if_true=line,*if_false=NULL;
  int i=0;
  while(line[i]!='\0' && !(line[i]==' ' && line[i+1]=='t' && line[i+2]=='h' && line[i+3]=='e' && line[i+4]=='n' && (line[i+5]==' ' || line[i+5]=='\t' || line[i+5]=='\n' || line[i+5]=='\0'))){
    if(line[i]==' ' && line[i+1]=='e' && line[i+2]=='l' && line[i+3]=='s' && line[i+4]=='e' && (line[i+5]==' ' || line[i+5]=='\t' || line[i+5]=='\n' || line[i+5]=='\0')){
      line[i]='\0';
      if_false=line+i+6;
    }
    i++;
  }
  line[i]='\0';
  *toLine+=i+6;
  int top_value;
  int_stack_pop(stk,&top_value);
  if(top_value==0){
    if(if_false!=NULL){
      //printf("false: \"%s\"\n\"%s\"\n",if_false,line);
      return if_false;
    }
  }else{
    //printf("true: \"%s\"\n\"%s\"\n",if_true,line);
    return if_true;
  }
  //return 0;
}

/*
// for loop
char* int_stack_do(int_stack_t *stk,int *min,int *max,char **toLine){
  char* line=*toLine;
  int_stack_pop(stk,min);
  int_stack_pop(stk,max);
  int i=0;
  while(line[i]!='\0' && !(line[i]==' ' && line[i+1]=='l' && line[i+2]=='o' && line[i+3]=='o' && line[i+4]=='p' && (line[i+5]==' ' || line[i+5]=='\t' || line[i+5]=='\n' || line[i+5]=='\0'))){
    i++;
  }
  line[i]='\0';
  *toLine+=i+6;
  return line;
}
*/