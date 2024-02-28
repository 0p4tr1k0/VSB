#ifndef QUEUE_HPP
#define QUEUE_HPP

// Function to enqueue an item into the queue
void enqueue(int queue[], int &front, int &rear, int item, int max_size);

// Function to dequeue an item from the queue
void dequeue(int queue[], int &front, int rear, int max_size);

// Function to return the front item of the queue
int front(int queue[], int front);

// Function to check if the queue is empty
bool is_queue_empty(int front);

// Function to return the size of the queue
int queue_size(int front, int rear, int max_size);

#endif
