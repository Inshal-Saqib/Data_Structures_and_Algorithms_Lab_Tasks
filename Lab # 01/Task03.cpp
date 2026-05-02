#include <iostream>
using namespace std ;

int *newfun(int arr[] , int size){
    int new_size = size * 2;
    int *newarr = new int[new_size];

    for(int i = 0; i < size ; i++){
        newarr[i] = arr[i];
    }
    for(int i = size; i < new_size; i++){
        newarr[i] = -1;
    }
    return newarr;}
int main(){
    int *arr = new int[5]{3 , 4 , 5 , 6 , 7};

    cout << "Original Array : " << endl;

    for (int i = 0; i < 5 ; i++)
    {
        cout << arr[i] << " ";
    }

    int *ans = newfun(arr,5); 

    cout << "\nNew Array : " << endl;

    for (int i = 0; i < 10 ; i++)
    {
        cout << ans[i] << " ";    }

    delete[] arr;
    delete[] ans;

    return 0;}