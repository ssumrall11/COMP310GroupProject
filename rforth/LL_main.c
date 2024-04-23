#include <sdtio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "token.h"
#include "ast.h"

// imma just use tokens because AST_node_t has a linked list as a feild
int main(int argc,char **argv){
  LL_t* list=LL_init();
  char *line="I sure do hope this code works";
  token_t* token;
  LL_node_t* element;
  while(*line!='\0'){
    token=get_next_token(&line);
    element=LL_node_init(token,NULL);
    LL_add(list,element);
  }

  return 0;
}