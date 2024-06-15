# Expression Processor

This project provides a simple C program to process mathematical expressions, distinguishing between operations inside and outside of brackets.

## Features

- Supports addition (`+`), subtraction (`-`), multiplication (`*`), and division (`/`) operations.
- Differentiates between operations inside brackets and those outside.
- Utilizes a circular queue to manage and process operators.

## Code Overview

### Queue Implementation

The program uses a circular queue to manage operators (`+`, `-`) both inside and outside of brackets. The queue functions include:

- `createQueue()`: Initializes the queue.
- `enqueue(QueueEntry element)`: Adds an element to the rear of the queue.
- `clearQueue()`: Clears the queue.
- `traverseQueue(void (*operation)(QueueEntry element))`: Applies a given operation to each element in the queue.

### Main Logic

1. **Reading the Expression**: 
   The expression is read from the standard input and stored in `expre`.

2. **Processing Inside Brackets**: 
   - When encountering an opening bracket `(`, the program processes all operations until the corresponding closing bracket `)`.
   - Multiplication (`*`) and division (`/`) inside brackets are immediately printed.
   - Addition (`+`) and subtraction (`-`) are added to the queue.

3. **Processing Outside Brackets**:
   - After processing inside brackets, the program processes the remaining part of the expression outside brackets.
   - Multiplication (`*`) and division (`/`) are immediately printed.
   - Addition (`+`) and subtraction (`-`) are added to the queue.


