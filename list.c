// list/list.c
// 
// Implementation for linked list.
//
// Ciara Wharton @02880894
// With help from breakout room

#include <stdlib.h>
#include <stdio.h>
#include "list.h"

list_t *list_alloc() { 
  list_t *tList = (list_t *) malloc(sizeof(list_t));
  return tList;
}

void list_free(list_t *l) {
  node_t *currentNode = l->head;
  while(currentNode != NULL){
    node_t *node = currentNode;
    currentNode = currentNode->next;
    free(node);
  }
  free(l);
}

void list_print(list_t *l) {
  node_t *currentNode = l->head;
  
  // List is empty
  if(currentNode == NULL){
    printf("Empty list.");
    return;
  }
  
  printf("[");
  // List contains nodes
  while(currentNode != NULL){
    if(currentNode != NULL){
      printf("%d,", currentNode->value);
    }else{
      printf("%d", currentNode->value);
    }
    currentNode = currentNode->next;
  }
  printf("]\n");
}
int list_length(list_t *l) {
  node_t *current_node = malloc(sizeof(node_t));
  current_node = l->head;
  if (current_node == NULL) {
    return 0;
  }

  int list_length = 0;
  while (current_node != NULL) {
    list_length++;
    current_node = current_node->next;
  }
  return list_length;
}

void list_add_to_back(list_t *l, elem value) {
  node_t *tail = l->head;
  
  // List is empty, add to front
  if (tail == NULL){
    list_add_to_front(l, value);
  }
  while(tail->next != NULL){
    tail = tail->next;
  }
  
}
void list_add_to_front(list_t *l, elem value) {
  node_t *headBackup = l->head;
  l->head = (node_t *)malloc(sizeof(node_t));
  l->head->value = value;
  l->head->next = headBackup;
}
void list_add_at_index(list_t *l, elem value, int index) {
  // Index out of range, add to back/front
  if(index >= sizeof(node_t)){
    list_add_to_back(l, value);
    return;
  }else if (index <= 0){
    list_add_to_front(l, value);
    return;
  }
  int currentIndex = 0;
  node_t *currentNode = l->head;
  while(currentIndex != index){
    currentIndex++;
    currentNode = currentNode->next;
  }
}

elem list_remove_from_back(list_t *l)
{
    if (!l)
    {
        return 0; 
    }
    node_t *t = l->head;
    while (t->next != NULL)
    {
        t = t->next;
    }
    elem returnee = t->value;
    free(t);
    return returnee;
}

elem list_remove_from_front(list_t *l)
{
    if (!l)
    {
        printf("The list does not exist.");
        return 0;
    }
    elem returnee = l->head->value;
    node_t *freer = l->head;
    l->head = l->head->next;
    free(freer);
    return returnee;
}
elem list_remove_at_index(list_t *l, int index)
{
    if (!l)
    {
        printf("The list does not exist.");
        return 0;
    }
    int i = 0;
    node_t *t = l->head;
    while (t->next != NULL && i < index)
    {
        t = t->next;
        i++;
    }
    node_t *freer = t->next;
    elem val = t->next->value;
    t->next = t->next->next;
    free(freer);
    return val;
}

bool list_is_in(list_t *l, elem value)
{
    if (!l)
    {
        printf("The list does not exist.");
        return false;
    }
    node_t *t = l->head;
    while (t->next)
    {
        t = t->next;
    }
    return t->value == value;
}

elem list_get_elem_at(list_t *l, int index) {
  if (index > sizeof(index) || index < 0){
    printf("Index[%d] range is out of bounds \n", index);
    return index; 
  }
  node_t *ptr = l -> head;
  int counter = 0;
  int val;
  if(index == 0 ){
     val =  ptr -> value ;
  }else{
    while(counter < index){
      ptr = ptr->next;
     val = ptr -> value;
    counter++;}
}
}
