/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"

/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  // if we reached the end of 'in', just return
  if (in==nullptr){
    return;
  }

  // if the value in 'in' is even, move it to the evens list
  else if (in->value % 2 == 0){
    // if this is the first value in the evens list, set the list to 'in' and recursively call the function again
    if (evens==nullptr){
      evens = in;
      in = in->next;
      evens->next = nullptr;
      split(in, odds, evens);
    }
    // if there are already nodes in the list, point it to 'in', and recursively call the function again
    else{
      evens->next = in;
      in = in->next;
      evens->next->next = nullptr;
      split(in, odds, evens->next);
    }
  }

  // if the value in 'in' is odd, move it to the odds list
  else{
    // if this is the first value in the odds list, set the list to 'in' and recursively call the function again
    if (odds==nullptr){
      odds = in;
      in = in->next;
      odds->next = nullptr;
      split(in, odds, evens);
    }
    // if there are already nodes in the list, point it to 'in', and recursively call the function again
    else{
      odds->next = in;
      in = in->next;
      odds->next->next = nullptr;
      split(in, odds->next, evens);
    }    
  }
    
}

/* If you needed a helper function, write it here */
