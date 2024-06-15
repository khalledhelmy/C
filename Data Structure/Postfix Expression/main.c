#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Global variables for stack
float *Stack;
int top, n;

// Function declarations
float Postfix_Evaluate(char exp[]);
void InputPostfix(char exp[]);
void Push(float value);
float Pop();

int main() {
    top = -1; // Initialize top of stack
    char x[100];
    
    // Get postfix expression from user
    InputPostfix(x);
    
    // Determine the length of the input expression
    n = strlen(x);
    
    // Allocate memory for the stack based on the length of the expression
    Stack = (float *)malloc(n * sizeof(float));
    if (Stack == NULL) {
        printf("Memory allocation failed. Exiting.\n");
        return 1;
    }
    
    // Evaluate the postfix expression and print the result
    printf("Result: %.2f\n", Postfix_Evaluate(x));
    
    // Free allocated memory for the stack
    free(Stack);
    
    return 0;
}

// Function to take postfix expression input from user
void InputPostfix(char exp[]) {
    printf("Enter a postfix expression: ");
    scanf("%s", exp);
}

// Function to push a value onto the stack
void Push(float value) {
    top++; // Increment top
    Stack[top] = value; // Place value at the top of the stack
}

// Function to pop a value from the stack
float Pop() {
    float poppedValue = Stack[top]; // Get value at the top of the stack
    top--; // Decrement top
    return poppedValue; // Return the popped value
}

// Function to evaluate the postfix expression
float Postfix_Evaluate(char exp[]) {
    for (int i = 0; i < n; i++) {
        // If the character is a digit, push it onto the stack
        if (isdigit(exp[i])) {
            Push(exp[i] - '0'); // Convert character to float and push
        } else { // If the character is an operator
            // Pop two operands from the stack
            float op2 = Pop();
            float op1 = Pop();
            float res = 0; // Variable to store result of operation
            
            // Perform the appropriate operation based on the operator
            switch (exp[i]) {
                case '+':
                    res = op1 + op2;
                    break;
                case '-':
                    res = op1 - op2;
                    break;
                case '*':
                    res = op1 * op2;
                    break;
                case '/':
                    if (op2 != 0) {
                        res = op1 / op2;
                    } else {
                        printf("Error: Division by zero.\n");
                        return 0;
                    }
                    break;
                default:
                    printf("Invalid operator: %c\n", exp[i]);
                    return 0;
            }
            
            // Push the result of the operation back onto the stack
            Push(res);
        }
    }
    return Stack[top]; // The final result is at the top of the stack
}
