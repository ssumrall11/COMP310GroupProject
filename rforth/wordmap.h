#ifndef WORDMAP_H
#define WORDMAP_H
#include <stdio.h>

typedef struct worddef {
  char *word,*def;
} worddef_t; // hash node

typedef struct wordmap {
  worddef_t *head;
  int capacity,size;
} wordmap_t ; // hash map

extern void wordmap_init(wordmap_t *map,int capacity);
extern void wordmap_print(wordmap_t *map);
//extern void wordmap_delete(wordmap* head_ptr);
extern int wordmap_put(wordmap_t *map,char *word,char *def);
extern int wordmap_containsKey(wordmap_t *map,char *key);
extern char* wordmap_get(wordmap_t *map,char *key);
extern int hash(int capacity,char *word);

#endif