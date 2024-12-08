#include <iostream>
#include <algorithm>

using namespace std;

// Function to merge two sorted subarrays in-place
void inPlaceMerge(int arr[], int start, int mid, int end)
{
    int i = start;   // Starting index for the left subarray
    int j = mid + 1; // Starting index for the right subarray

    // Traverse both subarrays and merge them in place
    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            // If element from left subarray is smaller, no need to swap
            i++;
        }
        else
        {
            // Element from right subarray is smaller, so we need to place it in the correct position
            int value = arr[j];
            int index = j;

            // Shift all elements between arr[i] and arr[j-1] one step to the right
            while (index > i)
            {
                arr[index] = arr[index - 1];
                index--;
            }
            arr[i] = value;

            // Update all indices
            i++;
            mid++;
            j++;
        }
    }
}

// Recursive function to perform in-place merge sort
void mergeSort(int arr[], int start, int end)
{
    if (start < end)
    {
        int mid = start + (end - start) / 2;

        // Sort the first half
        mergeSort(arr, start, mid);

        // Sort the second half
        mergeSort(arr, mid + 1, end);

        // Merge the two sorted halves
        inPlaceMerge(arr, start, mid, end);
    }
}

// Utility function to print the array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, size);

    mergeSort(arr, 0, size - 1);

    cout << "Sorted array: ";
    printArray(arr, size);

    return 0;
}
