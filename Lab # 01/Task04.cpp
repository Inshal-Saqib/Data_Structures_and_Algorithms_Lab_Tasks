#include <iostream>
using namespace std;

int* mergeArray(int* arrA, int sizeA, int* arrB, int sizeB)
{
    int totalSize = sizeA + sizeB;
    int* mergedArray = new int[totalSize];

    for (int i = 0; i < sizeA; i++)
        mergedArray[i] = arrA[i];

    for (int i = 0; i < sizeB; i++)
        mergedArray[sizeA + i] = arrB[i];

    return mergedArray;
}

int main()
{
    int arrA[] = {1, 2, 3};
    int arrB[] = {4, 5, 6, 7};

    int sizeA = 3;
    int sizeB = 4;

    int* result = mergeArray(arrA, sizeA, arrB, sizeB);

    cout << "Merged Array: ";
    for (int i = 0; i < sizeA + sizeB; i++)
    {
        cout << result[i] << " ";
    }

    delete[] result;

    return 0;}