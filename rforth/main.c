#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "token.h"
#include "int_stack.h"
#include "wordmap.h"

// processes a single line of forth code
int process(int_stack_t *stack,wordmap_t *words,char *line){
  char **toLine=&line;
  int output;
  // parse tokens
  while(*line!='\0'){ // if there is more unread line content
    token_t* token=get_next_token(toLine); // get the next token from the line (similar to Scanner.next() in Java)
    output=0;
    // interpret and execute token
    switch(token->type){
      case 1: // if the token is a number
        int_stack_push(stack,atoi(token->str)); // convert the token string to an int and push it onto the stack
        break;
      case 2: // if the token is a operator
        switch(*token->str){
          case 42: // multiplication (*token->str=='*')
            int_stack_multiply(stack);
            break;
          case 43: // addition (*token->str=='+'
            int_stack_add(stack);
            break;
          case 45: // subtraction (*token->str=='-')
            int_stack_subtract(stack);
            break;
          case 47: // division (*token->str=='/')
            int_stack_divide(stack);
            break;
        }
        break;
      case 3: // if the token is a symbol
        if(*token->str==':'){
          token=get_next_token(toLine);
          int i=0;
          while(line[i]!=' ' || line[i+1]!=';' || !(line[i+2]==' ' || line[i+2]=='\t' || line[i+2]=='\n' || line[i+2]=='\0')){
            i++;
          }
          line[i]='\0';
          wordmap_put(words,token->str,line); // overwrite if the word is already defined
        }
// temporary response
        print_token(token); // print the token
        break;
      case 4: // if the token is a word
        // default words
/* still needs to me added as default words (among others)
  ."              (printing strings)
  if else then    (conditional statements)
  begin until     (while loop)
  do loop         (for loop)
  roll            (just really useful I guess)
*/
        if(0==strcmp(token->str,".s")){
          int_stack_print(stack,stdout);
          output=1;
        }else if(0==strcmp(token->str,"cr")){
          int_stack_cr(stdout);
        }else if(0==strcmp(token->str,".")){
          int_stack_dot(stack,stdout);
          output=1;
        }else if(0==strcmp(token->str,"emit")){
          int_stack_emit(stack,stdout);
          output=1;
        }else if(0==strcmp(token->str,"mod")){
          int_stack_mod(stack);
        }else if(0==strcmp(token->str,"/mod")){
          int_stack_dividemod(stack);
        }else if(0==strcmp(token->str,"=")){
          int_stack_equal(stack);
        }else if(0==strcmp(token->str,"<")){
          int_stack_less(stack);
        }else if(0==strcmp(token->str,">")){
          int_stack_greater(stack);
        }else if(0==strcmp(token->str,"invert")){
          int_stack_invert(stack);
        }else if(0==strcmp(token->str,"and")){
          int_stack_and(stack);
        }else if(0==strcmp(token->str,"or")){
          int_stack_or(stack);
        }else if(0==strcmp(token->str,"swap")){
          int_stack_swap(stack);
        }else if(0==strcmp(token->str,"dup")){
          int_stack_dup(stack);
        }else if(0==strcmp(token->str,"over")){
          int_stack_over(stack);
        }else if(0==strcmp(token->str,"drop")){
          int_stack_drop(stack);
        }else if(0==strcmp(token->str,"rot")){
          int_stack_rot(stack);
        }else if(0==strcmp(token->str,"2swap")){
          int_stack_2swap(stack);
        }else if(0==strcmp(token->str,"2dup")){
          int_stack_2dup(stack);
        }else if(0==strcmp(token->str,"2over")){
          int_stack_2over(stack);
        }else if(0==strcmp(token->str,"2drop")){
          int_stack_2drop(stack);
        }else if(0==strcmp(token->str,"2rot")){
          int_stack_2rot(stack);
        }else if(0==strcmp(token->str,"depth")){
          int_stack_depth(stack);
        }else if(0==strcmp(token->str,"if")){
          process(stack,words,strdup(int_stack_if(stack,toLine)));
        /*}else if(0==strcmp(token->str,"do")){
          int max,min;
          char* statement=int_stack_do(stack,&min,&max,toLine);
          for(int i=min; i<max; i++){
            process(stack,words,strdup(statement));
          }
        */
        }else if(wordmap_containsKey(words,token->str)){
          process(stack,words,strdup(wordmap_get(words,token->str)));
        }
// incomplete response
        //print_token(token); // print the token
        break;
    }
    free_token(token); // free the memory used to store the token
  }
  return output;
}

int main(int argc, char**argv){
  // print header
  printf("RFORTH IMPLEMENTER (version 0.3.0a)\nDev: 02/11/2024-Present by Joshua Morin \n(Type `bye' to exit)\n");
  const int capacity=256; // default capacity (maximum number of integers the stack can hold/words the wordmap can hold)
  // initialize the stack
  int_stack_t stack;
  int_stack_init(&stack,capacity);
  // initialize the word list
  wordmap_t words;
  wordmap_init(&words,capacity);
  // initialise variables to hold the user input (in a line by line manner in real time)
  char* line="\0"; // used to store the input of the current line (starting at the next token to be read)
  size_t l=0; // the size of the buffer allocated for line (getline will make it longer automatically if it is not long enough)
  int output; // records whether the last line had output (so we can start a new line for the next user input line)
  // analyse each line of input as the user enters them
  while(0!=strcmp(line,"bye\n")){ // if the line is not the escape code (i.e. "bye\n")
    int output=process(&stack,&words,line);
    // if the prevous line produced output then start a new line for the next user input
    if(output==1){
      printf("\n");
    }
    // get the next line
    getline(&line,&l,stdin);
    // remove any leading zeros
    while(*line==' ' || *line=='\t' || *line=='\n'){
      line++;
    }
  }
  return 0; // return success
}