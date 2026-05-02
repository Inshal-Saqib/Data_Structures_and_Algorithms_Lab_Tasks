#include <iostream>
#define MAX_LIST_SIZE 100
using namespace std;

struct ELEMENT{
    int number;
    string data;
};

struct LIST {
    ELEMENT arr[MAX_LIST_SIZE];
    int size;
};

void createList(LIST *list) {
    list->size = 0;
}

void Add(LIST *list , int index ,ELEMENT item) 
{
    if (list -> size >= MAX_LIST_SIZE) 
    {
        cout << "List is full. Cannot add more elements." << endl;
        return;
    }

    if(index < 0 || index > MAX_LIST_SIZE - 1 || index > list->size)
    {
        cout << "Invalid index. Please provide an index between 0 and " << list->size - 1 << "." << endl;
        return;
    }
    for (int i = list -> size; i > index; i--)
    {
        list -> arr[i] = list -> arr[i - 1];
    }
    list -> arr[index] = item;
    list -> size++;
    cout << "Element added successfully at index " << index << "." << endl;
}

void Remove(LIST *list , int index)
{
    if (index < 0 || index > list -> size)
    {
        cout << "Invalid index. Please provide an index between 0 and " << list->size - 1 << "." << endl;
        return;
    }
    for (int i = index; i < list -> size ; i++)
    {
        list -> arr[i] = list -> arr[i + 1];
    }
    list -> size--;
    cout << "Element removed successfully from index " << index << "." << endl;
}

ELEMENT Get (LIST *list , int index)
{
    ELEMENT temp = {0, "N / A"}; // Default-constructed ELEMENT
    if (index < 0 || index >= list -> size)
    {
        cout << "Invalid index. Please provide an index between 0 and " << list->size - 1 << "." << endl;
        return temp; // Return a default-constructed ELEMENT
    }
    return list -> arr[index];
}

int Size (LIST *list)
{
    return list -> size;
}

int is_empty(LIST *list)
{
    return list -> size == 0? 1 : 0;
}

int End(LIST *list)
{
    return list -> arr[list -> size - 1];
}

int Start(LIST *list)
{
    return list -> arr[0];
}




int main() {
    


    return 0;
}