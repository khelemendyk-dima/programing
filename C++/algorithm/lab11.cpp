#include <iostream>
#include <ctime>
using namespace std;

#define N 50000

void randArraySort(int *arr, int size);
void randArraySortReverse(int *arr, int size);
void randArrayUnsort(int *arr, int size);
int selectionSort(int *arr, int size);

int main()
{
    int arr[N];
    randArrayUnsort(arr, N);
    clock_t start1 = clock();
    int counter = selectionSort(arr, N);
    clock_t end1 = clock();
    
    for (int i = 0; i < N; i++) {
        cout << arr[i] << endl;
    }
    double seconds1 = (double)(end1 - start1) / CLOCKS_PER_SEC;
    cout  << endl << "Time: " << seconds1 << endl;
    cout  << endl << "Counter: " << counter << endl << endl;
    return 0;
}

int selectionSort(int *arr, int size)
{
    int count = 0;
    for (int i = 0; i < size - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            swap(arr[i], arr[min_index]);
            count++;
        }
    }
    return count;
}
void randArraySort(int *arr, int size)
{
    for (int i = 0; i < N; i++) {
        arr[i] = i + 1;
    }    
}
void randArraySortReverse(int *arr, int size)
{
    for (int i = 0; i < N; i++) {
        arr[i] = N - i;
    } 
}
void randArrayUnsort(int *arr, int size)
{
    for (int i = 0; i < N; i++)
    {
        arr[i] = rand() % 50000;
    }
}