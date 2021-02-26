
#ifndef stack_h
#define stack_h
#include "node.h"
typedef struct {
	NodePtr top;
	int size;
}Stack;

typedef Stack * StackPtr;
void push(StackPtr s, char value){
  Node *new_node=(Node *)malloc(sizeof(Node));
  if(new_node){
  new_node-> data=value;
  new_node-> nextPtr=s->top;
  s->top=new_node;
  }
}
char pop(StackPtr s){
  NodePtr t =s->top;
  char value;
  value=t->data;
  s->top=t->nextPtr;
  free(t);
  return value;
}
void pop_all(StackPtr s){
  NodePtr t =s->top;
  char value;
  while(s->top != NULL){
    value=t->data;
    s->top=t->nextPtr;
    printf("Popping %c\n",value);
    free(t);
  }
}

#endif
