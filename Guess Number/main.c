#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Function declarations
int get_random_num();
bool validate_user_input(int input, int random);
void print_lose();
void print_win();
void print_previous_attempts(int arr[], int n);

int main()
{
    // Initialize random number generator
    srand(time(0));
    
    int arr[10]; // Array to store user guesses
    int n = 0; // Number of attempts
    int input; // User's input
    int random = get_random_num(); // Random number to be guessed

    while (true)
    {
        // Prompt user for input
        printf("Guess the number between 10 => 250:  ");
        scanf("%d", &input);

        // Validate user input
        if (validate_user_input(input, random))
        {
            // If user guessed correctly, print win message and exit
            print_win();
            break;
        }

        // Check if maximum attempts reached
        if (n >= 9)
        {
            // If maximum attempts reached, print lose message and exit
            print_lose();
            break;
        }

        n++; // Increment number of attempts
        printf("Remaining Attempts: %d\n", 10 - n);
        printf("----------------------------------------------\n");

        // Store the user input in the array
        arr[n - 1] = input;
        
        // Print previous attempts
        print_previous_attempts(arr, n);
    }
}

// Function to generate a random number between 10 and 250
int get_random_num()
{
    return (rand() % (240 + 1)) + 10;
}

// Function to validate user input against the random number
bool validate_user_input(int input, int random)
{
    if (input == random)
        return true;
    else
    {
        if (input > random)
            printf("The real number is smaller\n");
        else
            printf("The real number is bigger\n");
        return false;
    }
}

// Function to print win message
void print_win()
{
    printf("\n\t\t<----- Congratulation ,You Win ----->\n\n\n\n");
}

// Function to print lose message
void print_lose()
{
    printf("\n\t\t<----- Hmmmm Sorry ,You Lose ----->\n\n\n\n");
}

// Function to print previous attempts
void print_previous_attempts(int arr[], int n)
{
    printf("Previous attempts = [");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}
