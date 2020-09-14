#include <stdio.h>
#include "list.h"


int main() {
  printf("Tests for linked list implementation\n");
  list_t *tList = list_alloc();
  printf("Print List:\n");
  list_print(tList);
  printf("Add 8 to back\n");
  // list_add_to_back(tList,8);
  // list_print(tList);
  printf("Add 10 to front\n");
  list_add_to_front(tList, 10);
  list_print(tList);
  printf("Add 20 to index 1\n");
  list_add_at_index(tList, 20, 1);
  list_print(tList);
  printf("Remove from back\n");  
  list_remove_from_back(tList);
  list_print(tList);
  printf("Remove from front\n");    
  list_remove_from_front(tList);
  list_print(tList);
  printf("Remove at index 2\n");  
  list_remove_at_index(tList, 2);
  list_print(tList);
  printf("Is 10 in the list?\n");  
  list_is_in(tList, 10);
  printf("Length:\n");
  list_length(tList);
  return 0;
}