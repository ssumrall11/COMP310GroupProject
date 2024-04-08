#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "astmap.h"

void map_init(map_t *map,int capacity){
  map->head=malloc(capacity*sizeof(map_node_t*));
  map->size=0;
  map->capacity=capacity;
}

void map_print(map_t* map){
  map_node_t* w;
  for(int i=0; i<map->capacity; i++){
    w=map->head+i;
    if(w->word!=NULL){
      printf("{%s,%p}\n",w->word,w->def);
    }
  }
}

int map_put(map_t *map,char *word,AST_node_t *def){ // handle collisions
  if(map->size>=map->capacity){
    printf("Map is at full capacity.\n");
    return 0; // fail
  }
  map_node_t* newWord=map->head+hash(map->capacity,word);
  newWord->word=word;
  newWord->def=def;
  map->size++;
  return 1; // pass
}

int map_containsKey(map_t *map,char *key){
  map_node_t *slot=map->head+hash(map->capacity,key);
  return (0==strcmp(slot->word,key))?1:0;
}

AST_node_t* map_get(map_t *map,char *key){
  map_node_t *slot=map->head+hash(map->capacity,key);
  return (0==strcmp(slot->word,key))?slot->def:NULL;
}

/*
void map_delete(map_t* map){
  map_node_t* w;
  for(int i=map->capacity-1; i>=0; i--){
    w=map->head+i;
    free(w->word);
    free(w->def);
    free(w);
  }
  free(map->head);
  //free(&map->size);
  //free(&map->capacity);
  free(map);
}
*/

int hash(int capacity,char* word){
  int hash=0,c,i=0;
  while((c=*(word+i))!='\0'){
    hash=hash*(c/4)-c%4; // trying to produce unique values that are within the integer limit
    i++;
  }
  return (hash&0x7fffffff)%capacity;
}