#include <iostream>
#include "queue.hpp"
#include "stack.hpp"

using namespace std;

int main()
{
    const int max_size = 6;
    int stack[max_size];
    int queue[max_size];
    int top_of_stack = -1;
    int front_of_queue = -1;
    int rear_of_queue = -1;

    int number_of_items = 7;

    for (int i = 0; i < number_of_items; i++)
    {
        // fill stack and queue
        // last item should not be added, Overflow...
        push(stack, top_of_stack, (i + 1) * 2, max_size);
        enqueue(queue, front_of_queue, rear_of_queue, (i + 1) * 2, max_size);
    }
    // test dequeue and enqueue
    dequeue(queue, front_of_queue, rear_of_queue, max_size);
    enqueue(queue, front_of_queue, rear_of_queue, 42, max_size);

    cout << endl;
    for (int i = 0; i < max_size; i++)
    {
        // print top of stack, front of queue

        if (i % 2 == 1)
        {
            cout << "Size of stack is: " << stack_size(top_of_stack) << endl;
            cout << "So the stack is:" << (is_stack_empty(top_of_stack) ? "" : " not") << " empty" << endl;

            cout << "Size of queue is: " << queue_size(front_of_queue, rear_of_queue, max_size) << endl;
            cout << "So the queue is:" << (is_queue_empty(front_of_queue) ? "" : " not") << " empty" << endl;
        }
        cout << "Element on top of stack is: " << top(stack, top_of_stack) << endl;
        cout << "First element in queue is: " << front(queue, front_of_queue) << endl;

        cout << "pop and dequeue" << endl;
        pop(stack, top_of_stack);
        dequeue(queue, front_of_queue, rear_of_queue, max_size);

        cout << endl;
    }

    cout << "Size of stack is: " << stack_size(top_of_stack) << endl;
    cout << "So the stack is:" << (is_stack_empty(top_of_stack) ? "" : " not") << " empty" << endl;

    cout << "Size of queue is: " << queue_size(front_of_queue, rear_of_queue, max_size) << endl;
    cout << "So the queue is:" << (is_queue_empty(front_of_queue) ? "" : " not") << " empty" << endl;

    cout << endl;
    cout << "pop and deque" << endl;
    // Underflow...
    pop(stack, top_of_stack);
    dequeue(queue, front_of_queue, rear_of_queue, max_size);

    return 0;
}
