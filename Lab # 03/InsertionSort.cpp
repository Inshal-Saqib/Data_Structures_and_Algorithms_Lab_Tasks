#include<iostream>
using namespace std;

void insertion_sort (int arr[] , int size)
{
    int key , j;
    for (int i = 1 ; i < size ; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main(){
    int my_array[5] = {5 , 8 , 3 , 4 , 2};
    int size = 5;
    cout << "Array Before Inserion Sort = " << endl;
    for (int i = 0 ; i < size ; i ++)
    {
        cout << my_array[i] << " " ;
    }

    insertion_sort(my_array , size);

    cout << "\nArray After Inserion Sort = " << endl;
    for (int i = 0 ; i < size ; i ++)
    {
        cout << my_array[i] << " " ;
    }

    return 0;
}