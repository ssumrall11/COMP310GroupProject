#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"
#include "token.h"
#include "astmap.h"

// generate an abstract syntax tree given a line of forth code
AST_node_t* generate_AST(map_t* worddefs,char* str,char* triggerword){
  // create the AST node and assign the basic fields
  AST_node_t* node=(AST_node_t*)malloc(sizeof(AST_node_t));
  node->str=triggerword;
  node->children=LL_init();
  // what word to is needed to end the function
  char* breakword;
  if(strcmp(triggerword,"if")){
    breakword="then"; // how do i handle else
  }else if(strcmp(triggerword,"do")){
    breakword="loop";
  }else if(strcmp(triggerword,"begin")){
    breakword="until";
  }
  // fill the children linked list
  token_t* token=get_next_token(str);
  while(strcmp(token->str,breakword)){
    if(token->type!=4){ // or default word
      LL_node_t* child=LL_node_init(token,NULL);
      LL_add(node->children,child);
    }else{
      if(wordmap_containsKey(worddefs,token->str){ // user defined word (already defined)
        AST_node_t* sub=wordmap_get(worddefs,token->str);
        LL_node_t* sib=LL_node_init(NULL,sub);
        LL_add(node->children,sib);
      }else if(strcmp(token->str,"if") || strcmp(token->str,"do") || strcmp(token->str,"begin")){ // 'if' 'do' and 'until'
        node->children=LL_init(); // initialize the linked list to hold the children
        char* keyword=strdup(token->str); // specifies the word that starts the new recursion (triggerword for the recursive call)
        AST_node_t* sub=AST_init(worddefs,char* str,keyword); // recursive call
        LL_node_t* child=LL_node_init(NULL,sub);
        LL_add(node->children,child);
      }//else{ (a word that is currently being defined or an error)
    }
    token=get_next_token(str);
  }
  return node;
}

void process_AST(AST_node_t* root){
  LL_node_t* c = root->children->head;
  while(c != NULL){
    if(c->value.node == NULL){
      token_t* token = value.token;
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
        }
    }else{ // c->value.token==NULL
       process_AST(c->value.node);
    }
    c = c->next; 
  }
}

void free_AST(AST_node_t* root){
  //(added children_len field to AST_node to replace this) use root.token to determine the size of root.children?
  free_token(root.token);
  for(int i=0; i<root->children_len; i++){
    free_AST((root.children+i));
  }
}

