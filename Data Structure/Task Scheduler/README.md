# Task Management System using Priority Queue

This project implements a simple task management system using a priority queue in C. Tasks are prioritized based on their priority values, with lower values indicating higher priority.

## Features

- Enqueue tasks with a specified priority.
- Dequeue tasks based on their priority, with the highest priority task (lowest priority value) being dequeued first.
- Check if the queue is full or empty.
- Display the execution order of tasks based on their priority.
- Display the number of tasks remaining in the queue.

## Code Overview

### Queue Implementation

The program uses an array to implement the priority queue. The queue functions include:

- `bool IsFull()`: Checks if the queue is full.
- `bool IsEmpty()`: Checks if the queue is empty.
- `void Enqueue(int element)`: Adds a task with a given priority to the queue.
- `void Dequeue(int* res, int* taskNumber)`: Removes and returns the highest priority task from the queue.
- `int QueueNElement()`: Returns the number of elements in the queue.

### Main Logic

1. **Reading Task Count and Priorities**:
   - The number of tasks is read from the standard input.
   - The priority for each task is read and the task is enqueued.

2. **Dequeueing and Displaying Tasks**:
   - Tasks are dequeued based on their priority and the execution order is displayed.
   - The number of remaining tasks in the queue is displayed.

