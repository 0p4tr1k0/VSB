#include "stack.hpp"
#include <iostream>

using namespace std;

// Function to push an item onto the stack
void push(int stack[], int &top, int item, int max_size)
{

    if (top == max_size - 1)
    {
        cout << "Stack overflow" << endl;
    }
    else
    {
        top++;
        stack[top] = item;
    }
}

// Function to pop an item from the stack
void pop(int stack[], int &top)
{
    if (top >= 0) {
        top--;
    }
}

// Function to return the top item of the stack
int top(int stack[], int top)
{
   if (top >= 0) {
        return stack[top];
    } else {
        return -1;
    }
    
}

// Function to check if the stack is empty
bool is_stack_empty(int top)
{
    return top == -1;
}

// Function to return the size of the stack
int stack_size(int top)
{
    int size = top + 1;
    return size;
}
