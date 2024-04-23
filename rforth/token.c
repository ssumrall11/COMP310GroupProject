//token.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "token.h"

// identify the type of the token from its string
token_type_t id_type(char* str){
  // is it a symbol or an operator
  if(*(str+1)=='\0'){ // single element string
    if(*str=='+' || *str=='*' || *str=='-' || *str=='/'){ 
      return 2; //OPERATOR
    }else if(*str==':' || *str==';'){
      // these characters may be words or symbols (I am not sure): . = ! @
      // these characters cause problems: ? < >
      return 3; //SYMBOL
    }
  }
  // is it a number or a word
  int i=(*str=='-')?1:0; // skips sign if negative
  int v;//=(int)*(str+i); // current character
  while((v=(int)(*(str+i++)))!='\0'){ // check until the string ends
  //while(v!='\0'){ // check until the string ends
    if(v<48 || 57<v){ // non digit chars
      return 4; //WORD
    }
    //v=(int)(*(str+i++)); // increment to the next character
  }
  return 1; //NUMBER
}

token_t* create_token(token_type_t type,char* str) {
  // allocate memory for the token
  token_t* token=(token_t*)malloc(sizeof(token_t));
  // in case of failure
  if(token==NULL){
    return NULL;
  }
  // assign fields
  token->type=type;
  token->str=strdup(str); // Duplicate the string to avoid pointer issues
  // return the new token (pointer)
  return token;
}

// prints the contents of the token
void print_token(token_t* token,int indent){
  for(int i=0; i<indent; i++){
    printf(" ");
  }
  // print type
  int t=token->type;
  if(t==1){
    printf("NUMBER:   ");
  }else if(t==2){
    printf("OPERATOR: ");
  }else if(t==3){
    printf("SYMBOL:   ");
  }else if(t==4){
    printf("WORD:     ");
  }else{ // shouldn't be possible
    printf("ERROR: COULD NOT IDENTIFY TYPE");
  }
  // print contents (str field)
  char* start=token->str;
  printf("\"");
  for(int i=0; *(start+i)!='\0'; i++){ // print a string from the pointer of the first char
    printf("%c",*(start+i));
  }
  printf("\"\n");
}

// delete the from memory/free its memory slot  
void free_token(token_t* token) {
  if(token!=NULL){ // if the token exists
    free(token->str); // free the str field
    free(token); // free the token
  }
}

// pull the next token from the current line (similar to .next() method of java.util.Scanner)
token_t* get_next_token(char** toLine){
  char *line=*toLine;
  // isolate token 
  int i=0; // index iterator (eventually used to represent to length of the token string)
  while(line[i]!=' ' && line[i]!='\t' && line[i]!='\n' && line[i]!='\0'){
    i++;
  }
  line[i]='\0'; // replace whitespace with the end string character (end token string)
  // skip any extra whitespace
  do{
    i++;
  }while(*(line+i)==' ' || *(line+i)=='\t' || *(line+i)=='\n');
  *toLine+=i; // update the new start position in the string
  return create_token(id_type(line),line); // create and return a new token with the token string as its content
}