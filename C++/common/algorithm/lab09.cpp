#include <iostream>
#include <ctime>
using namespace std;

void pushArray(int *arr, int sizeOfArray);
int linearSearch(int[], int key, int sizeOfArray);
int binarySearch (int arr[], int left, int right, int key, int *count);
void printResultLinear(int element, int sizeOfArray);
void printResultBinary(int element, int *counter);

int main()
{	
	int a[10000], searchKey, element;
	int *count;
    int i = 0;
    int size = 20;

    pushArray(a, 10000);
   
    while (i != 4) {
        cout << "Input key (integer) from 1 to " << size << ": ";
        cin >> searchKey;
        clock_t start1 = clock();
        element = linearSearch(a, searchKey, size);
        clock_t end1 = clock();
        double seconds1 = (double)(end1 - start1) / CLOCKS_PER_SEC;
        cout << "Linear search:\n\n";
        printResultLinear(element, size);
        cout  << "Time: " << seconds1 << endl << endl;

        *count = 0;
        clock_t start2 = clock();
        element = binarySearch(a, 0, size, searchKey, count);
        clock_t end2 = clock();
        double seconds2 = (double)(end2 - start2) / CLOCKS_PER_SEC;
        cout << "Binary search:\n\n";
        printResultBinary(element, count);
        cout  << "Time: " << seconds2 << endl << endl;
        if (i == 0)
            size = 100;
        else if (i == 1)
            size = 1000;
        else
            size = 10000; 
        i++;
    }
    return 0;
}

void pushArray(int *arr, int sizeOfArray)
{
    for (int i = 0; i < sizeOfArray; i++)
		arr[i] = i + 1;
}
int linearSearch(int array[], int key, int sizeOfArray)
{  
    for (int n = 0; n < sizeOfArray; n++) {
        if (array[n] == key)
            return n;
    }
    return -1;
}
int binarySearch(int arr[], int left, int right, int key, int *count)
{
    int midd = 0;
    while (1) {
        midd = (left + right) / 2;

        if (key < arr[midd]) {       
            right = midd - 1; 
            *count += 1;   
        } else if (key > arr[midd]) {
            left = midd + 1;  
            *count += 1; 
        } else {
            *count += 1;                 
            return midd;    
        }
        if (left > right)
            return -1;
    }
}
void printResultLinear(int element, int sizeOfArray)
{
    if (element != -1) {
		cout << "Found element in position: "<< element + 1 << endl;
        cout << "Number of comparisons: " << element + 1 << endl;
	} else {
		cout << "Element non found..." << endl;
        cout << "Number of comparisons: " << sizeOfArray << endl;
    }
}
void printResultBinary(int element, int *counter)
{
    if (element != -1) {
		cout << "Found element in position: "<< element + 1 << endl;
        cout << "Number of comparisons: " << *counter << endl;
	} else {
		cout << "Element non found..." << endl;
        cout << "Number of comparisons: " << *counter << endl;
    }
}