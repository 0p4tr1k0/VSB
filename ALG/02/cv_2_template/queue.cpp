#include "queue.hpp"
#include <iostream>

using namespace std;

// Function to enqueue an item into the queue
void enqueue(int queue[], int &front, int &rear, int item, int max_size)
{
    if ((rear + 1) % max_size == front)
    {
        cout << "Queue is full." << endl;
    }
    else
    {
        rear = (rear + 1) % max_size;
        queue[rear] = item;
        if (front == -1)
        {
            front = rear;
        }
    }
}

// Function to dequeue an item from the queue
void dequeue(int queue[], int &front, int rear, int max_size)
{
    if (front == -1) {
        cout << "Queue is empty." << endl;
        return;
    }

    front++;

    if (front == rear) {
        front = -1;
        rear = -1;
    }
}

// Function to return the front item of the queue
int front(int queue[], int front)
{
    return queue[front];
}

// Function to check if the queue is empty
bool is_queue_empty(int front)
{
    return front == -1;
}

// Function to return the size of the queue
int queue_size(int front, int rear, int max_size)
{
    for (int i = front; i <= max_size; i++) {
        return i;
    }
    //int size = ;
    //return size;
}
