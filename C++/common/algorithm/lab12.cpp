#include <iostream>
#include <ctime>
using namespace std;

void randArraySort(int *arr, int size);
void randArraySortReverse(int *arr, int size);
void randArrayUnsort(int *arr, int size);
int hoaraSort(int arr[], int b, int e);
int surface(int *a, int i, int k);
int treeSort(int *a, int size);
int pairMergeSort(int *a, int size);

#define N 20

int main()
{
    int arr[N];
    int count = 0;

    randArrayUnsort(arr, N);
    
    clock_t start1 = clock();
    count = hoaraSort(arr, 0, N - 1);
    clock_t end1 = clock();
    double seconds1 = (double)(end1 - start1) / CLOCKS_PER_SEC;
    cout << endl << "Hoara sort time: " << seconds1 << endl;
    cout << "Count: " << count << endl; 

    randArrayUnsort(arr, N);

    start1 = clock();
    count = treeSort(arr, N);
    end1 = clock();
    seconds1 = (double)(end1 - start1) / CLOCKS_PER_SEC;
    cout << endl << "Tree sort time: " << seconds1 << endl;
    cout << "Count: " << count << endl; 

    randArrayUnsort(arr, N);

    start1 = clock();
    count = pairMergeSort(arr, N);
    end1 = clock();
    seconds1 = (double)(end1 - start1) / CLOCKS_PER_SEC;
    cout << endl << "Pair merge sort time: " << seconds1 << endl;
    cout << "Count: " << count << endl; 

    return 0;
}

void randArraySort(int *arr, int size)
{
    for (int i = 0; i < size; i++) {
        arr[i] = i + 1;
    }    
}
void randArraySortReverse(int *arr, int size)
{
    for (int i = 0; i < size; i++) {
        arr[i] = N - i;
    } 
}
void randArrayUnsort(int *arr, int size)
{
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 50000;
    }
}
int hoaraSort(int *arr, int b, int e) 
{ 
    int count = 0;
    int i = b; 
    int j = e; 
    int tmp = 0; 
    int x = arr[(i + j) / 2]; 

    do { 
        while (arr[i] < x) 
            i++; 
        while (arr[j] > x) 
            j--; 
        if (i <= j) { 
            swap(arr[i], arr[j]); 
            i++;
            j--;
            count++;
        } 
    } while (i <= j); 
    if (i < e)
        count += hoaraSort(arr, i, e); 
    if (b < j)  
        count += hoaraSort(arr, b, j);
    return count; 
} 
int surface(int *a, int i, int k) 
{ 
    int j;
    int m = 2 * i;
    int temp = a[i];
    int count = 0; 

    while (m <= k) {
        if(m == k) 
            j = m;
        else if (a[m] > a[m + 1]) 
            j = m;
        else 
            j = m + 1; 
        if (a[j] > temp) { 
            a[i] = a[j]; 
            i = j; 
            m = 2 * i; 
            count++;
        } else 
            break;
    }
    a[i] = temp;
    count++;
    return count;
} 
int treeSort(int *a, int size)
{ 
    int i, k, w; 
    int count = 0;

    for (i = size / 2; i >= 0; i--) 
        count += surface(a, i, size); 
    for (k = size - 1; k >= 0; k--) { 
        count += surface(a, 0, k);
        swap(a[k], a[0]);
    } 
    return count;
}
int pairMergeSort(int *a, int size)
{ 
    int i0, j0, i, j, si, sj, k, ke, t, m; 
    int count = 0;
    si = 1; // початковий розмір одного масиву 

    while (si < size) { 
        i0 = 0;
        while (i0 < size) { 
            j0 = i0 + si;
            i = i0; 
            j = j0; 
            // розмір 2-гої множини пари може обмежуватися кінцем масиву 
            if (si >= size - j0) 
                sj = size - j0; 
            else 
                sj = si; 

            if (sj > 0) { 
                k = i0; // поч. індекс злитої множини 
                while ((i < i0 + si + sj) && (j < j0 + sj)) { 
                    if (a[i] > a[j]) {
                        t = a[j]; 
                        for (m = j - 1; m >= k; m--) {
                            a[m + 1] = a[m]; 
                            count++;
                        }
                        a[k] = t; 
                        j++; 
                        count++;
                    } 
                    k++;
                    i++;
                } 
            } 
            i0 += si * 2; // початок наступної пари 
        } 
        si *= 2; // розмір ел-тів пари збільшується вдвічі 
    }
    return count;
} 