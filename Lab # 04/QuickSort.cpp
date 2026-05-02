#include <iostream>
using namespace std;

// Partition function (first element as pivot)
int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while (true) {
        while (i <= high && arr[i] <= pivot)
            i++;

        while (j >= low && arr[j] > pivot)
            j--;

        if (i < j)
            swap(arr[i], arr[j]);
        else
            break;
    }

    swap(arr[low], arr[j]); // Place pivot correctly
    return j;
}

// Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

// Main function
int main() {
    int arr[] = {5, 8, 3, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array Before Quick Sort: " << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    quickSort(arr, 0, n - 1);

    cout << "\nArray After Quick Sort: " << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}