# Postfix Expression Evaluator

This project provides a simple C program to evaluate postfix expressions (Reverse Polish Notation).

## Features

- Supports addition (`+`), subtraction (`-`), multiplication (`*`), and division (`/`) operations.
- Handles single-digit operands.
- Detects and reports division by zero.

## Code Overview

### Stack Implementation

The program uses a stack to manage operands during the evaluation of the postfix expression. The stack functions include:

- `Push(float value)`: Adds a value to the top of the stack.
- `Pop()`: Removes and returns the value from the top of the stack.

### Main Logic

1. **Reading the Expression**:
   - The postfix expression is read from the standard input and stored in `exp`.

2. **Evaluating the Expression**:
   - The program iterates through each character in the postfix expression.
   - If the character is a digit, it is pushed onto the stack.
   - If the character is an operator (`+`, `-`, `*`, `/`), the program pops two operands from the stack, performs the corresponding operation, and pushes the result back onto the stack.
   - After processing all characters, the final result is at the top of the stack.

### Error Handling

- The program checks for division by zero and reports an error if encountered.
- The program reports invalid operators that are not supported.
