#include <iostream>
#include <algorithm> // For std::min and std::copy
using namespace std;

// Function to merge two sorted subarrays:
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    int* leftArr = new int[n1];
    int* rightArr = new int[n2];

    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];

    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    int i = 0;      // Initial index of left subarray
    int j = 0;      // Initial index of right subarray
    int k = left;   // Initial index of merged array

    // Merge the temp arrays back into arr[left...right]
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of leftArr[], if any
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy remaining elements of rightArr[], if any
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }

    // Deallocate memory
    delete[] leftArr;
    delete[] rightArr;
}

// Main recursive function to sort arr[left...right]
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        // Avoid overflow
        int mid = left + (right - left) / 2;

        // Divide
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Conquer (merge sorted halves)
        merge(arr, left, mid, right);
    }
}

int main() {
    int arr[] = {5 , 8 , 3 , 4 , 2};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    cout << "Array Before Merge Sort: " << endl;
    for (int i = 0; i < arr_size; i++)
        cout << arr[i] << " ";
    cout << endl;

    mergeSort(arr, 0, arr_size - 1);

    cout << "\nArray After Merge Sort: " << endl;
    for (int i = 0; i < arr_size; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}