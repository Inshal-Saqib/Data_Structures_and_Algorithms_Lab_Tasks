#include <iostream>
using namespace std;

int maxValue(int arr[] , int Size)
{
    int temp = arr[0];
    for (int i = 0; i < Size ; i++)
    {
        if (temp < arr[i]){
            temp = arr[i];
        }
    }
    return temp;
}
int main(){
    int *arr = new int[10]{23 , 22 , 1 , 60 , 23 , 33 ,45 , 64 , 12 , 7};
    int arr_size = 0;
    cout << "Enter the size of your array: ";
    cin >> arr_size;

    cout << "Enter the Elements of the array: " << endl;
    for (int i = 0; i < arr_size ; i++)
    {
        cin >> arr[i];
    }

    cout << "Max Element in the Array is = " << maxValue(arr,arr_size);
    return 0;
}