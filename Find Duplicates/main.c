#include <stdio.h>

// Function declaration to find duplicates in an array
void Duplicates(int arr[], int size);

int main()
{
    int size;

    // Prompt user to enter the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Declare an array with the given size
    int arr[size];

    // Prompt user to enter the elements of the array
    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Call the function to find and print duplicates
    Duplicates(arr, size);

    return 0;
}

// Function to find and print duplicate elements in an array
void Duplicates(int arr[], int size) {
    int *ptr1, *ptr2;
    int count = 0;

    // Print the message for duplicate elements
    printf("Duplicate elements in the array: ");

    // Traverse the array with two pointers to find duplicates
    for (ptr1 = arr; ptr1 < arr + size; ptr1++) {
        for (ptr2 = ptr1 + 1; ptr2 < arr + size; ptr2++) {
            if (*ptr1 == *ptr2) {
                count++; // Increment count for each duplicate found
                printf("%d ", *ptr1); // Print the duplicate element
                break; // Break the inner loop to avoid printing the same duplicate again
            }
        }
    }

    // Print the total number of duplicate elements found
    printf("\nNumber of duplicates: %d\n", count);
}
