#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int get_random_num();
bool validate_user_input(int input, int random);
void print_lose();
void print_win();
void print_previous_attempts(int arr[], int n);

int main()
{
    srand(time(0));
    int arr[10];
    int n = 0, input, random = get_random_num();
    while (true)
    {
        printf("Guess the number between 10 => 250:  ");
        scanf("%d", &input);
        if (validate_user_input(input, random))
        {
            print_win();
            break;
        }
        if (n >= 9)
        {
            print_lose();
            break;
        }
        n++;
        printf("Remaining Attempts: %d\n", 10 - n);
        printf("----------------------------------------------\n");

        arr[n - 1] = input;
        print_previous_attempts(arr, n);
    }
}

int get_random_num()
{
    return (rand() % (240 + 1)) + 10;
}

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

void print_win()
{
    printf("\n\t\t<----- Congratulation ,You Win ----->\n\n\n\n");
}

void print_lose()
{
    printf("\n\t\t<----- Hmmmm Sorry ,You Lose ----->\n\n\n\n");
}

void print_previous_attempts(int arr[], int n)
{
    printf("Previous attempts = [");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}
