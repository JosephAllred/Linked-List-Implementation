/**
 * @file linklist.h
 * @author Joseph Allred 
 * @brief Struct and method declarations for singly-linked list module 
 * @date 2024-03-27
 */

#ifndef COMP230_LINKLIST_H
#define COMP230_LINKLIST_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <errno.h>

extern int errno;

// definition for Node 
typedef struct Node {
    int data; 
    struct Node* next; 
} Node; 

// definition for List 
typedef struct List { 
    int length; 
    Node* head; 
} List; 

// Node constructor methods 
void init_Node(Node* node, int data);
Node* new_Node(int data);
void delete_Node(Node* node);

// List constructor methods 
void init_List(List* list);
List* new_List();
void delete_List(List* list);

// methods supported by singly-linked list 
void List_print(List* list);
void List_append(List* list, int data);
void List_prepend(List* list, int data);
void List_extend(List* listA, List* listB);
bool List_contains(List* list, int value);

int List_get(List* list, int index);
int List_insert(List* list, int index, int value);
int List_remove(List* list, int index);
void List_clear(List* list);

#endif /* COMP230_LINKLIST_H */
    
