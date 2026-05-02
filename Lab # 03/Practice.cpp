#include<iostream>
using namespace std;

int swap(int &a , int &b){

    int temp = a;
    a = b;
    a = temp;

}

int main(){
    int x , y;
    x = 5;
    y = 6;
    
    swap(x , y);
    cout << x << y;

    return 0;
}