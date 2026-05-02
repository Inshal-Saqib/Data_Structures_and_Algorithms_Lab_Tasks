#include<iostream>
using namespace std;

void selection_sort (int arr[] , int size)
{
    for (int i = 0 ; i < size - 1  ; i++)
    {
        int min = i;
        for (int j = i + 1 ; j < size ; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

int main(){
    int my_array[5] = {5 , 8 , 3 , 4 , 2};
    int size = 5;
    cout << "Array Before Selection Sort = " << endl;
    for (int i = 0 ; i < size ; i ++)
    {
        cout << my_array[i] << " " ;
    }

    selection_sort(my_array , size);

    cout << "\nArray After Selection Sort = " << endl;
    for (int i = 0 ; i < size ; i ++)
    {
        cout << my_array[i] << " " ;
    }

    return 0;
}