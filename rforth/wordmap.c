#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wordmap.h"

void wordmap_init(wordmap_t *map,int capacity){
  map->head=malloc(capacity*sizeof(worddef_t*));
  map->size=0;
  map->capacity=capacity;
}

void wordmap_print(wordmap_t* map){
  worddef_t* w;
  for(int i=0; i<map->capacity; i++){
    w=map->head+i;
    if(w->word!=NULL){
      printf("{%s,%s}\n",w->word,w->def);
    }
  }
}

int wordmap_put(wordmap_t *map,char *word,char *def){ // handle collisions
  if(map->size>=map->capacity){
    printf("Map is at full capacity.\n");
    return 0; // fail
  }
  worddef_t* newWord=map->head+hash(map->capacity,word);
  newWord->word=word;
  newWord->def=def;
  map->size++;
  return 1; // pass
}

int wordmap_containsKey(wordmap_t *map,char *key){
  worddef_t *slot=map->head+hash(map->capacity,key);
  return (0==strcmp(slot->word,key))?1:0;
}

char* wordmap_get(wordmap_t *map,char *key){
  worddef_t *slot=map->head+hash(map->capacity,key);
  return (0==strcmp(slot->word,key))?strdup(slot->def):NULL;
}

/*
void wordmap_delete(wordmap* map){
  worddef* w;
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