#include <iostream>
#include <ctime>
using namespace std;

#define N 6

int Put(int vec [], int x, int y, int v, int indx); // Запись в вектор (сжатие)
int PrintVector(int vec []); // Чтение из вектора 
void RandArray(int a[N][N]); // Заполнение двумерного массива
void PrintArray(int a[N][N]); // Печать массива

int main()
{  
    int vec[16];
    int array[N][N];

    RandArray(array);

    clock_t start1 = clock();
    PrintArray(array);
    clock_t end1 = clock();
    double seconds1 = (double)(end1 - start1) / CLOCKS_PER_SEC;
    cout  << "Time: " << seconds1 << endl << endl;
    
    int index = 0;
    for(int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            index = Put(vec, i, j, array[i][j], index);
        }
    }

    for(int i = 0; i < 16; i++) {
        printf("%3i", vec[i]);
    }
    printf("\n\n");
    
    clock_t start2 = clock();
    PrintVector(vec);
    clock_t end2 = clock();
    double seconds2 = (double)(end2 - start2) / CLOCKS_PER_SEC;
    cout  << endl << "Time: " << seconds2 << endl << endl;
    
    return 0;
}
int Put(int vec [], int x, int y, int v, int indx)   
{  
    int z = N / 3;
    if ( (x > z - 1) && ( (y < z) || (y > N - z - 1) ) ) {
        vec[indx] = v;
        indx++;
    }
    return indx;
}
int PrintVector(int vec [])
{  
    int z = N / 3;
    int index = 0;
    for(int i = 0; i < N; i++) { 
        for (int j = 0; j < N; j++)	{
            if ( (i <= z - 1) || ( (j <= N - z - 1) && (j > z - 1) ) ) {
                printf("%3i", 0);
            } else {
                printf("%3i", vec[index]);
                index++;
            }
        }
        printf("\n");
    }
}
void RandArray(int a[N][N])
{
    int z = N / 3;
    for(int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if ( (i <= z - 1) || ( (j <= N - z - 1) && (j > z - 1) ) ) {
                a[i][j] = 0;
            } else {
                a[i][j] = rand() % 50;
            }
        }
    }
}
void PrintArray(int a[N][N])
{    
    for(int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
	        printf("%3i", a[i][j]);
        }
	    printf("\n");
    }
    printf("\n");
}