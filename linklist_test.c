/**
 * @file linklist_test.c
 * @author Joseph Allred 
 * @brief tests for all methods implemented in linklist.c 
 * @date 2024-03-27 
 */

#include <stdlib.h>
#include <stdio.h>

#include "linklist.h"

List* buildList(int a, int b, int c);

int main(int argc, char* argv[]) {
    // TEST: new_List, init_List, List_prepend, new_Node, and init_Node
  
    //****************************************************************************
    // TEST: List_print
    printf("Test print:\n");
    //****************************************************************************

    List* list1 = buildList(1, 2, 3);
    List_print(list1);
    printf("\n");

    //****************************************************************************



    // //*************************************************************************
    // TEST: List_append
    printf("Test append:\n"); 
    // //*************************************************************************

    // append to populated list 
    printf("list1: "); 
    List_print(list1); 
    List_append(list1, 4);
    List_print(list1);

    // append to empty list 
    List* list2 = new_List(); 
    printf("list2: "); 
    List_print(list2); 
    List_append(list2, 1);  
    List_print(list2); 

    // append to list of size 1
    List_append(list2, 2);
    List_print(list2);

    // append negative number
    List_append(list2, -100);
    List_print(list2);

    printf("\n"); 

    // //**************************************************************************
    

     // //*************************************************************************
    // TEST: List_prepend
    printf("Test prepend:\n"); 
    // //*************************************************************************


    // prepend to populated list 
    List* listA = buildList(4, 5, 6); 
    printf("listA: ");
    List_print(listA); 
    List_prepend(listA, 3);
    List_print(listA);

    // prepend to empty list 
    List* listB = new_List(); 
    printf("listB: ");
    List_print(listB); 
    List_prepend(listB, 2);  
    List_print(listB); 

    // prepend to list of size 1
    List_prepend(listB, 1);
    List_print(listB);

    // prepend negative number
    List_prepend(listB, -100);
    List_print(listB);

    printf("\n"); 


    // //**************************************************************************
    // // Test: List_contains
    printf("Test contains:\n");
    // //**************************************************************************

    List* list3 = buildList(4, 6, 8); 
    printf("List3: "); 
    List_print(list3); 
    if (!List_contains(list3, 5)) {
        printf("List3 does not contain 5\n");
    }
    if (List_contains(list3, 4)) {
        printf("List3 contains 4\n");
    }

    List* list4 = new_List(); 
    printf("List4: "); 
    List_print(list4);
    if (!List_contains(list4, 5)) { // test empty list 
        printf("List4 does not contain 5\n");
    } 

    printf("\n");

    // //**************************************************************************



    // //**************************************************************************
    // TEST: List_insert
    printf("Test insert:\n");
    // //**************************************************************************
  
    List* list5 = new_List(); 
    printf("list5 before insert at index 1: ");
    List_print(list5); 
    if (List_insert(list5, 1, 10) == 0) { // insert value into empty list at index one greater than list length (0) 
        printf("list5 should still be empty): ");
        List_print(list5); 
    }
    List* list6 = new_List(); 
    printf("list6 before insert: ");
    List_print(list6);
    if (List_insert(list6, 0, 10) == 0) { // insert value into empty list at index 0 
        printf("list6 after insert: ");
        List_print(list6);
    }    
    List* list7 = buildList(5, 7, 8); 
    printf("list7 before insert at index 1: ");
    List_print(list7);
    if (List_insert(list7, 1, 6) == 0) { // insert value into index 1 of populated list 
        printf("list7 after insert: ");
        List_print(list7);
    }
    printf("list7 before insert at end of list: ");
    List_print(list7);
    if (List_insert(list7, 4, 10) == 0) { // insert value at the end of a list 
        printf("list7 after insert: ");
        List_print(list7);
    }
    printf("list7 before insert at index 4: ");
    List_print(list7);
    if (List_insert(list7, 4, 9) == 0) { // insert value in the middle of a list 
        printf("list7 after insert: ");
        List_print(list7);
    }
    printf("\n");

    // //**************************************************************************
    


    // //**************************************************************************
    //   // TEST: List_get
    printf("Test get:\n");
    // //**************************************************************************

    List* list8 = buildList(1, 2, 3); 
    printf("list8: ");
    List_print(list8); 

    errno = 0;  
    int idx = -1; // test negative index 
    printf("retrieving value at negative index:\n");
    int val = List_get(list8, idx);
    if (errno == 0) {
        printf("The value of list8 at index %d is %d\n", idx, val);
    }

    errno = 0; 
    idx = 0; // test first value 
    val = List_get(list8, idx);
    if (errno == 0) {
        printf("The value of list8 at index %d is %d\n", idx, val);
    }

    errno = 0; 
    idx = 3; // test value one greater than length-1 of list 
    printf("retrieving value at index 3 from a list of length 3:\n"); 
    val = List_get(list8, idx);
    if (errno == 0) {
        printf("The value of list8 at index %d is %d\n", idx, val);
    }

    errno = 0; 
    idx = 2; // test last value  
    val = List_get(list8, idx);
    if (errno == 0) {
        printf("The value of list8 at index %d is %d\n", idx, val);
    }
    List* list9 = new_List(); 
    printf("list9: ");
    List_print(list9); 

    errno = 0; 
    idx = 1; 
    printf("Retrieving index 1 from empty list9:\n");
    val = List_get(list9, idx); // test retrieval from empty list 
    if (errno == 0) {
        printf("The value of list9 at index %d is %d\n", idx, val);
    }
    printf("\n"); 

    //**************************************************************************



    //**************************************************************************
        // Test List_extend 
        printf("Test extend:\n");
    //**************************************************************************

    List* list10 = new_List(); 
    List* list11 = new_List(); 

    printf("list10 before adding list11: ");
    List_print(list10);
    printf("list11 before being added to list10: ");
    List_print(list11);
    List_extend(list10, list11); // extend two empty lists 
    printf("list10 after adding list11: ");
    List_print(list10); 
     printf("list11 after being added to list10: ");
    List_print(list11); 
    printf("\n"); 

    List* list12 = buildList(1, 2, 3); 
    List* list13 = buildList(4, 5, 6); 
    printf("list12 before adding list13: ");
    List_print(list12);
    printf("list13 before being added to list12: ");
    List_print(list13);
    List_extend(list12, list13); // extend two populated lists 
    printf("list12 after adding list13: ");
    List_print(list12);
    printf("list13 after being added list14: ");
    List_print(list13);
    printf("\n");

    printf("list10 before adding list12: "); 
    List_print(list10); 
    printf("list12 before being added to list10: "); 
    List_print(list12); 
    List_extend(list10, list12); // add populated list to empty list 
    printf("list10 after adding list12: "); 
    List_print(list10); 
    printf("list12 after being added to list10: "); 
    List_print(list12); 
    printf("\n");

    printf("list13 before adding list11: ");
    List_print(list13); 
    printf("list11 before being added to list13: ");
    List_print(list11); 
    List_extend(list13, list11); // add empty list to populated list 
    printf("list13 after adding list11: ");
    List_print(list13); 
    printf("list11 after being added to list13: ");
    List_print(list11); 
    printf("\n");

    //**************************************************************************



    //**************************************************************************
        // Test: List_remove
        printf("Test remove:\n");
    //**************************************************************************

    List* list14 = new_List(); 
    printf("list 14: ");
    List_print(list14); 
    printf("attempting to remove at index 0 and 1 from empty list:\n");
    List_remove(list14, 0); // try to remove from empty list 
    List_remove(list14, 1); 
    printf("\n"); 

    List* list15 = buildList(5, 7, 9); 
    printf("list 15: ");
    List_print(list15); 
    printf("attempting to remove at out-of-bounds indeces:\n");
    List_remove(list15, 4); // try to remove an index out of bounds on high end 
    List_remove(list15, -1); // try to remove an index out of bounds on low end
    printf("removing index 0 then 1 \n");
    List_remove(list15, 0); // remove the first value 
    List_remove(list15, 1); // remove what is now the last value 
    printf("resulting list15: "); 
    List_print(list15); 

    int returned = List_remove(list15, 0); 
    printf("removing idex 0 and checking return value:\n"); 
    if (returned == 7) {
    printf("returned value from removing index 0: %d\n", returned); 
    }
    printf("resulting list15: ");
    List_print(list15); 

    printf("\n");

    //**************************************************************************



    //**************************************************************************
    // TEST: List_clear 
    printf("Test clear:\n");
    //**************************************************************************
    List* list16 = new_List(); 
    printf("list 16: ");
    List_print(list16); 
    List_clear(list16); // clear empty list 
    List_print(list16); 

    List* list17 = buildList(100, 500, 1000);  
    printf("list 17: ");
    List_print(list17); 
    List_clear(list17); // clear populated list  
    List_print(list17); 

    List_append(list17, 25); 
    printf("list17 repopulated: ");
    List_print(list17); 
    List_clear(list17); // clear list with one value 
    List_print(list17); 
    printf("\n"); 

    //**************************************************************************



    //**************************************************************************
    // TEST: delete_List
    printf("Test delete:\n");
    //**************************************************************************

    delete_List(list1);
    delete_List(list2);
    delete_List(list3); 
    delete_List(list4); 
    delete_List(list5); 
    delete_List(list6); 
    delete_List(list7); 
    delete_List(list8); 
    delete_List(list9); 
    delete_List(list10); 
    delete_List(list11); 
    delete_List(list12); 
    delete_List(list13);  
    delete_List(list14); 
    delete_List(list15); 
    delete_List(list16); 
    delete_List(list17);  

    printf("all lists (should have been) successfuly deleted\n\n"); 

    //**************************************************************************

    return EXIT_SUCCESS;
}

List* buildList(int a, int b, int c) {
    List* list = new_List();
    List_prepend(list, c);
    List_prepend(list, b);
    List_prepend(list, a);
    return list;
}

/* CORRECT OUTPUT
[ 1 2 3 ]
[ 1 2 3 4 ]
List does not contain 5
List contains 4
[ 5 7 8 ]
[ 5 6 7 8 ]
The value of listB at index 2 is 7
[ 1 2 3 4 5 6 7 8 ]
[ 3 4 5 6 7 ]
*/