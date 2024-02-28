#ifndef STACK_HPP
#define STACK_HPP

// Function to push an item onto the stack
void push(int stack[], int &top, int item, int max_size);

// Function to pop an item from the stack
void pop(int stack[], int &top);

// Function to return the top item of the stack
int top(int stack[], int top);

// Function to check if the stack is empty
bool is_stack_empty(int top);

// Function to return the size of the stack
int stack_size(int top);

#endif
