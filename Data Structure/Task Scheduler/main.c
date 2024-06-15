#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the maximum size for the queue
#define MAX_SIZE 50

int que_arr[MAX_SIZE]; // Array to hold queue elements
int max_size = 10; // Maximum size of the queue
int nElement = 0, front = -1, rear = 0; // Queue counters
int taskNumbers[MAX_SIZE]; // Array to hold task numbers
int priorities[MAX_SIZE]; // Array to hold priorities

// Function declarations
bool IsFull();
bool IsEmpty();
void Enqueue(int element);
void Dequeue(int* res, int* taskNumber);
int QueueNElement();

int main() {
    int taskCount, priority;

    // Input the number of tasks from the user
    printf("Enter the number of tasks: ");
    scanf("%d", &taskCount);

    // Input priorities for each task
    for (int i = 0; i < taskCount; ++i) {
        printf("Enter priority for Task %d: ", i + 1);
        scanf("%d", &priority);
        Enqueue(priority);
    }

    int currentTask;
    int taskNumber;

    // Dequeue and display the task execution order
    printf("Task Execution Order:\n");
    for (int i = 1; i <= taskCount; ++i) {
        Dequeue(&currentTask, &taskNumber);
        printf("Task %d (Priority %d) - Task Number %d\n", currentTask, priorities[taskNumber - 1], taskNumber);
    }

    // Display the number of tasks remaining in the queue
    printf("Number of Tasks in the Queue: %d\n", QueueNElement());

    return 0;
}

// Check if the queue is full
bool IsFull() {
    return nElement == max_size;
}

// Check if the queue is empty
bool IsEmpty() {
    return nElement == 0;
}

// Add an element to the queue
void Enqueue(int element) {
    if (!IsFull()) {
        if (rear == max_size) {
            rear = 0;
        }
        que_arr[rear] = element;
        taskNumbers[rear] = nElement + 1; // Store the task number
        priorities[rear] = element; // Store the priority
        rear++;
        nElement++;

        if (front == -1)
            front = 0;
    } else {
        printf("Queue Overflow\n");
    }
}

// Remove and return the highest priority task from the queue
void Dequeue(int* res, int* taskNumber) {
    if (!IsEmpty()) {
        if (front == rear)
            printf("This can happen rear overlaps front\n");

        // Find the element with the lowest priority (highest priority task)
        int lowestPriority = que_arr[front];
        int lowestPriorityIndex = front;

        for (int i = front + 1; i < front + nElement; ++i) {
            int currentIndex = i % max_size;
            if (que_arr[currentIndex] < lowestPriority) {
                lowestPriority = que_arr[currentIndex];
                lowestPriorityIndex = currentIndex;
            }
        }

        *res = que_arr[lowestPriorityIndex]; // Store the result
        *taskNumber = taskNumbers[lowestPriorityIndex]; // Store the task number

        // Replace the dequeued element with the front element
        que_arr[lowestPriorityIndex] = que_arr[front];
        taskNumbers[lowestPriorityIndex] = taskNumbers[front];

        // Update the front and number of elements
        front = (front + 1) % max_size;
        nElement--;

    } else {
        printf("Queue Underflow\n");
    }
}

// Return the number of elements in the queue
int QueueNElement() {
    return nElement;
}
