#include <iostream>
using namespace std;

int linear_search(int arr[] , int size , int target){

    for(int i = 0 ; i < size ; i++){
        if (arr[i] == target){
            return i;
        }
    }
    return -1;
}

int binary_search(int arr[] , int size , int target){
    int low = 0;
    int high = size - 1;
    while (low <= high){
        int mid = low + (high - low) / 2;
        if (arr[mid] == target){
            return mid;
        }
            else if(arr[mid] < target){
                low = mid +1;
        }
        else {
            high = mid - 1;
        }
    }
    return 0;
}

int main(){
    int array[10] = {1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10};
    int value , location_index_Linear, location_index_Binary;

    location_index_Linear = linear_search(array,10,4);
    location_index_Binary = binary_search(array,10,4);
    cout << "The Target value for Linear Search is at : " << location_index_Linear << endl;
    cout << "The Target value for Binary Search is at : " << location_index_Binary;

    return 0;
}