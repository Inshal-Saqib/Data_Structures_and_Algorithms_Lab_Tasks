#include <iostream>
using namespace std;

int main(){
    int *arr = new int[3]{3 , 4 ,5}; 

    for(int i = 0 ; i < 3 ; i++){
        cout << *(arr + i);
        cout << arr[i];
    }

    delete[]arr;
    arr = nullptr;


    return 0;
}