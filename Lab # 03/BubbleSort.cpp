#include<iostream>
using namespace std;

void bubble_sort (int arr[] , int size)
{
    for (int i = 0 ; i < size - 1 ; i ++)
    {
        for (int j = 0; j < size - i -1 ; j ++)
        {
            if (arr[j] > arr [j + 1])
            {
                //Swap the pair
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main(){
    int my_array[5] = {5 , 8 , 3 , 4 , 2};
    int size = 5;
    cout << "Array Before Bubble Sort = " << endl;
    for (int i = 0 ; i < size ; i ++)
    {
        cout << my_array[i] << " " ;
    }

    bubble_sort(my_array , size);

    cout << "\nArray After Bubble Sort = " << endl;
    for (int i = 0 ; i < size ; i ++)
    {
        cout << my_array[i] << " " ;
    }


    return 0;
}