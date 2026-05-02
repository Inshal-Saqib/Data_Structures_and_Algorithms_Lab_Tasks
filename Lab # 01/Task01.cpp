#include <iostream>
using namespace std;

int main(){

    int arr_size;
    float total , avg;
    cout << "Enter the size of Array : ";
    cin >> arr_size;
    int *arr = new int[arr_size];

    cout << "Enter the Elements of the array : " << endl;
    for(int i = 0; i < arr_size; i++){
        cin >> arr[i];
    }
    
    for(int i = 0; i < arr_size; i++){
        total = total + arr[i];
    }
    avg = total / arr_size;

    cout << "The average of the emelents in the array is : " << avg;
    
    return 0;
}