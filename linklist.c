/**
 * @file linklist.c
 * @author Joseph Allred
 * @brief Method implementations for singly-linked list module 
 * @date 2024-03-27
 */

#include <errno.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "linklist.h"

/**
 * @brief Initialize an existing Node pointer.
 * 
 * When a node is initialized its data should be set to the given data, and the 
 * next node should be reset to NULL.
 * 
 * @param node  An existing Node to be initialized
 * @param data  The value to be stored in this node
 */
void init_Node(Node* node, int data) {
    node->data = data; 
    node->next = NULL;
}

/**
 * @brief Allocates memory and initializes a new Node with the given value.
 * 
 * Nodes constructed using this function should be cleaned up using delete_Node
 * 
 * @param data  The value to be stored in this node
 */
Node* new_Node(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    init_Node(node, data); 
    return node; 
}

/**
 * @brief Deletes a node and frees the memory allocated for it.
 * 
 * @param node  The node to be deleted
 */
void delete_Node(Node* node) {
    node->data = 0;
    node = NULL; 
    free(node); 
}

/**
 * @brief Initialize a list that already exists in memory.
 * 
 * When a list is initialized its length should be set to 0 and the 
 * head node should be set to NULL.
 * 
 * @param list the list to be initialized
 */
void init_List(List* list) {
    list->length = 0;
    list->head = NULL; 
}

/**
 * @brief Allocate memory and create a new empty list.
 * Lists constructed using this function should be cleaned up using delete_List
 * @return List* to the newly created list
 */
List* new_List() {
    List* list = (List*)malloc(sizeof(List)); 
    init_List(list); 
    return list; 
}

/**
 * @brief Deletes an entire list freeing memory for all nodes and the list.
 * 
 * @param list the list to be deleted
 */
void delete_List(List* list) {
    while(list->head != NULL) {
        Node* temp = list->head; 
        list->head = list->head->next; 
        delete_Node(temp);  // delete node AFTER head-pointer has moved to the next node 
    }
    free(list->head); 
    free(list); 
}

/**
 * @brief Prints out an entire list
 * 
 * @param list the list to be printed
 */
void List_print(List* list) {

    Node* cursor = list->head;
    printf("[ ");
    int cntr = 0;  
    while (cursor != NULL && cntr < 40) {
        printf("%d ", cursor->data);
        cursor = cursor->next;
        cntr++; 
    }
    if (cntr == 40) {
        printf("Failure in print while-loop");
    }
    printf("]\n");
}

/**
 * @brief Appends the given value to the list.
 * 
 * When a value is appended to a list, it should become the last item in the 
 * list and the length of the list should increase by one. This should function 
 * the same as the add method of Java's LinkedList with no index argument.
 * 
 * @param list The list to which a value should be appended.
 * @param data  The value to be appended to the list
 */
void List_append(List* list, int data) {

    Node* newNode = new_Node(data); //make a new Node with the given data 
    Node* temp = list->head; 

        if (temp == NULL) { // check for an empty list 
            list->head = newNode; 
        } else {
            while(temp->next != NULL) { //move to the last Node in the list 
            temp = temp->next; 
            }
            temp->next = newNode; // Replace NULL with the newly created Node 
        }

    newNode->next = NULL; // Assign NULL to the next pointer of the last Node in list 
    list->length += 1; // increase length to reflect new size of list 
}

/**
 * @brief Prepends the given value to the list.
 * 
 * When a value is prepended to a list, it should become the first item in the 
 * list and the length of the list should increase by one and all the old values 
 * should follow the new one maintaining their order. This should function the 
 * same as the add method of Java's LinkedList with 0 as the index argument.
 * 
 * @param node The list to which the value will be appended.
 * @param data The value to be prepended to the list
 */
void List_prepend(List* list, int data) {
    Node* newNode = new_Node(data); // create a new Node with the given data 
    newNode->next = list->head; // assign new Node's next-pointer to the head of the list 
    list->head = newNode; // assign the head-pointer to the newly appended Node 
    list->length += 1; // update length of list 
}

/**
 * @brief Extends list A by adding all elements of list B to the end in order
 * 
 * When a list is extended with another list, all the elements in the second 
 * list are effectively appended to the first list. These elements maintain the 
 * same order they had in their original list. This should NOT be done using 
 * nested loops and repeated calls to List_append since that is terribly 
 * inefficient.
 * 
 * @param listA The list to be extended
 * @param listB The list to be added to the end of list A
 */
void List_extend(List* listA, List* listB) {

    if (listA->head == NULL) {
        listA->head = listB->head; // if listB is empty, this listA's head-pointer will just be reassigned to NULL
    }
    else {
        Node* temp = listA->head; 
        while(temp->next != NULL) {
            temp = temp->next; // move temp pointer to the last node before the NULL terminator 
        }
        temp->next = listB->head; // attach listA to the beginning of listB  HERE*****
    }
    listA->length += listB->length; // if listB is empty, listA's length will remain the same 
}

/**
 * @brief Checks whether or not the given list contains the given value
 * 
 * @param list   The list to be checked for the item
 * @param value  The value for which the list should be searched
 * @return true  If the list contains the item
 * @return false If the list does not contain the item
 */
bool List_contains(List* list, int value) {

    Node* temp = list->head; 

    if (temp == NULL) {
        return false; // empty list will not contain any given value 
    }
    while (temp != NULL) {
        if (temp->data == value) {
            return true; 
        }
        temp = temp->next; // move the pointer along the list 
    }
    return false; // if pointer reaches NULL terminator, list doesn't contain given value 
}

/**
 * @brief Returns the value of the ith node in the list.
 * 
 * @param list  The list to be indexed for the element
 * @param index The index of the node to be retrieved
 * @return      The value in the node at the index
 */
int List_get(List* list, int index) {

    Node* temp = list->head; 
    if (temp == NULL) {
        errno = 1; 
        perror("Empty list");
        return 0; 
    } 
    else if (index < 0 || index >= list->length) {
        errno = 1;
        perror("Index out of bounds"); 
        return 0; 
    } 
    int cntr = 0; 
    int whileCntr = 0; 
    while (cntr < list->length && whileCntr < 40) {
        if (cntr == index) {
            return temp->data; 
        }
        temp = temp->next; // move the pointer along the list 
        cntr += 1; // increment pointer to match new location 
        whileCntr++; 
    }
    if (whileCntr == 40) {
        printf("Get while-loop failed\n");
    }
    errno = 1; 
    perror("Unknown error"); 
    return 0; 
}

/**
 * @brief Inserts a new value into the list at a particular position
 * 
 * After the insertion, the new value should be at the specified index. Every 
 * item before it should still have the same index, while the index of every 
 * item after it should now have its index increased by one.
 * 
 * @param list  The list from which a node will be removed
 * @param index The index where the new value should be inserted
 * @param value The value to be inserted into the list
 * 
 * @return      Returns 0 if operation was successful, otherwise 1
 */
int List_insert(List* list, int index, int value) {

    Node* temp = list->head;  
    Node* newNode = new_Node(value); // create new node, construct with given value 

    if (list->length == 0)  {
        if(index != 0) { // empty lists can only insert at 0
            printf("Empty List only supports insertion at index 0\n");
            return 1; 
        } else {
            newNode->next = temp; 
            list->head = newNode; 
            list->length += 1; 
            return 0; 
        }
    }
    /* allows insertion at index one greater than last index (e.g., a list 
    with ten elements allows insertion at index 10 but not at index 11) */
    if (index < 0 || index > list->length) { 
        printf("Index out of bounds\n"); 
        return 1; 
    }
        
    Node* prev = NULL;
    for (int i = 0; i < index; i++) {
        prev = temp; 
        temp = temp->next; 
    }
    // rearrange pointer nodes surrounding the new node 
    prev->next = newNode; 
    newNode->next = temp;
    list->length += 1; //  update length of list 
    return 0; 
}

/**
 * @brief Removes and returns the value of the Node at the given index.
 * 
 * This function will remove the Node at the specified index from the list, 
 * safely free the memory allocated for that node, and return the value stored 
 * in that node.
 * 
 * @param list  The list from which a node will be removed
 * @param index The index of the node to be removed
 * @return      The value in the node at index i
 */
int List_remove(List* list, int index) {

    // error handling 
    if (list->head == NULL) {
        errno = 1; 
        perror("Cannot remove from empty list"); 
        return 1; 
    }
    if (index < 0 || index > (list->length-1)) {
        errno = 1; 
        perror("Index out bounds");
        return 1; 
    }

    Node* temp = list->head; 
    Node* prev = NULL; 
    int retVal = 0; 

    for (int i = 0; i < list->length; i++) {
        if (i == index) {
            break; // loop until finding specific index 0 1 2 3 
        }
        prev = temp; 
        temp = temp->next; 
    }
    retVal = temp->data; // save the data before deleting node 
    if (index == 0) {
        list->head = list->head->next; // reassign head pointer to drop first node in list 
    } else {
        prev->next = temp->next; // reattach pointer to delete node in the middle of list 
    }
    delete_Node(temp); // free memory;
    list->length -= 1; // update size of list 
    return retVal; 
}

/**
 * @brief Safely removes and frees memory for all nodes in the list
 * 
 * This function should call delete_Node to safely free memory for every Node in 
 * the list, be careful to ensure that every node is freed without losing track 
 * of later nodes in the list. Once all pointers to a node are lost it cannot be 
 * safely freed!
 * 
 * @param list the list to be reset to an empty list
 */
void List_clear(List* list) {
    Node* temp = list->head; 
    Node* remove = list->head; 
    while (temp != NULL) {
        remove = temp;
        temp = temp->next; 
        delete_Node(remove); // delete node after pointer has moved on to next node 
    }
    list->head = NULL; // reset head-pointer 
    list->length == 0; // update size of list 
}