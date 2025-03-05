#include <iostream>
#include <stack>
#include <utility>

//Swap function to change nubmers around
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Partition function that returns the pivot position
int partition(int arr[], int low, int high) {
    int pivot = arr[high];    // Choose the rightmost element as pivot
    int i = low - 1;         // Index of smaller element

    for (int j = low; j < high; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++;    // Increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Iterative Quicksort function
void quickSort(int arr[], int low, int high) {
    // Create a stack for storing subarray boundaries
    std::stack<std::pair<int, int>> stk;
    
    // Push initial values of low and high to stack
    stk.push(std::make_pair(low, high));

    // Keep popping from stack while it's not empty
    while (!stk.empty()) {
        // Pop low and high
        low = stk.top().first;
        high = stk.top().second;
        stk.pop();

        // If there are elements to be sorted
        if (low < high) {
            // Get pivot position
            int pivot = partition(arr, low, high);

            // Push subarray with elements less than pivot
            if (pivot - 1 > low) {
                stk.push(std::make_pair(low, pivot - 1));
            }

            // Push subarray with elements greater than pivot
            if (pivot + 1 < high) {
                stk.push(std::make_pair(pivot + 1, high));
            }
        }
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// Main function to test the implementation
int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    std::cout << "Original array: ";
    printArray(arr, n);
    
    quickSort(arr, 0, n-1);
    
    std::cout << "Sorted array: ";
    printArray(arr, n);
    
    return 0;
}
