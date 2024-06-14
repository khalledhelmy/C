# Number Guessing Game

This is a simple number guessing game written in C. The user has 10 attempts to guess a random number between 10 and 250. After each incorrect guess, the program will inform the user if the real number is smaller or bigger than their guess. The program will also keep track of and display the user's previous attempts.

## Program Explanation

### Functions

- `int get_random_num()`: Generates a random number between 10 and 250.
- `bool validate_user_input(int input, int random)`: Validates the user's input against the random number. Returns `true` if the input matches the random number, otherwise it provides a hint and returns `false`.
- `void print_lose()`: Prints a message indicating the user has lost the game.
- `void print_win()`: Prints a message indicating the user has won the game.
- `void print_previous_attempts(int arr[], int n)`: Prints the user's previous attempts.

### Main Program Flow

1. The program initializes the random number generator and generates a random number between 10 and 250.
2. The user is prompted to guess the number.
3. The user's guess is validated:
   - If the guess is correct, a win message is printed and the program terminates.
   - If the guess is incorrect and the user has reached the maximum number of attempts (10), a lose message is printed and the program terminates.
   - If the guess is incorrect and the user has remaining attempts, the program provides a hint and prints the remaining number of attempts and the user's previous guesses.
4. Steps 2 and 3 are repeated until the user guesses the correct number or runs out of attempts.
