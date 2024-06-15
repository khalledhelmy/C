#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
typedef char QueueEntry;

// Global variables to manage the queue and bracket status
int outsideBrackets = 0; // To check if currently processing outside brackets
int front = 0;
int rear = -1;
int size = 0;
QueueEntry queue[MAX_SIZE]; // Queue to store operators

// Function to initialize the queue
void createQueue() {
    front = 0;
    rear = -1;
    size = 0;
}

// Function to append an element to the rear of the queue
void enqueue(QueueEntry element) {
    rear = (rear + 1) % MAX_SIZE;
    queue[rear] = element;
    size++;
}

// Function to clear the queue
void clearQueue() {
    front = 0;
    rear = -1;
    size = 0;
}

// Function to traverse the queue and apply an operation on each element
void traverseQueue(void (*operation)(QueueEntry element)) {
    int position = front;
    for (int i = 0; i < size; i++) {
        (*operation)(queue[position]);
        position = (position + 1) % MAX_SIZE;
    }
}

// Function to print the operation based on the current bracket status
void print_operation(QueueEntry element) {
    if (element == '+') {
        if (outsideBrackets) {
            printf("Do addition\n");
        } else {
            printf("Do addition inside brackets\n");
        }
    } else {
        if (outsideBrackets) {
            printf("Do subtraction\n");
        } else {
            printf("Do subtraction inside brackets\n");
        }
    }
}

int main() {
    createQueue(); // Initialize the queue
    
    char* expre = malloc(MAX_SIZE * sizeof(char));
    char noBrackets[MAX_SIZE]; // To store the expression without brackets
    
    // Read the expression from standard input
    scanf("%s", expre);
    
    int j = 0;
    // Iterate through the expression
    for (int i = 0; expre[i] != '\0'; ++i, ++j) {
        if (expre[i] == '(') {
            int k = 0;
            i++;
            // Process the contents inside the brackets
            while (expre[i] != ')') {
                if (expre[i] == '*') {
                    printf("Do multiplication inside brackets\n");
                } else if (expre[i] == '/') {
                    printf("Do division inside brackets\n");
                } else if (expre[i] == '+' || expre[i] == '-') {
                    enqueue(expre[i]); // Add operator to the queue
                }
                k++;
                i++;
            }
            i++;
        }
        noBrackets[j] = expre[i]; // Store the expression without brackets
    }
    noBrackets[j] = '\0';
    
    outsideBrackets = 0; // Set to inside brackets context
    traverseQueue(print_operation); // Process the queued operations inside brackets
    clearQueue(); // Clear the queue for next use
    
    // Process the part of the expression outside brackets
    for (int i = 0; noBrackets[i] != '\0'; ++i) {
        if (noBrackets[i] == '*') {
            printf("Do multiplication\n");
        } else if (noBrackets[i] == '/') {
            printf("Do division\n");
        } else if (noBrackets[i] == '+' || noBrackets[i] == '-') {
            enqueue(noBrackets[i]); // Add operator to the queue
        }
    }
    
    outsideBrackets = 1; // Set to outside brackets context
    traverseQueue(print_operation); // Process the queued operations outside brackets
    
    free(expre); // Free the allocated memory
    return 0;
}
