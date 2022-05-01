#include <iostream>
#include <conio.h>
#include <ctime>
using namespace std;

void BYTE(unsigned char A);
struct Program1
{     
    int s;	/* 4 bytes */
    short data1:1;	
    short data2:1;
    short data3:1;
    short data4:1;
    short data5:1;
    short data6:4;
    short data7:4;
    union
    {  
        struct
        {   
            bool  is_platform_dependent;
            double dl;
        } dependent;
        struct
        {  
            bool is_payment;
            short st;
        } payment;
    } un;
};
struct Program2 
{   
    short s;	/* 4 bytes */
    int data1:1;	
    int data2:1;
    int data3:1;
    int data4:1;
    int data5:1;
    int data6:4;
    int data7:4;
};
int main()
{    
    Program1 obj1 = {3, 4, 2, 5, 0, 5, 1, 2};
    obj1.un.dependent.dl = 3.5;
    obj1.un.dependent.is_platform_dependent = true;	 
    unsigned char *p =  (unsigned char*) &obj1;
    clock_t start1 = clock();
    for (int byte = 0; byte < sizeof(Program1); byte++, p++) {
        if (byte && !( byte % 8) ) cout << endl;
            BYTE(*p);
    }
    clock_t end1 = clock();
    double seconds1 = (double)(end1 - start1) / CLOCKS_PER_SEC;
    cout  << endl << "Time: " << seconds1 << endl << endl;
    Program2 obj2 = {3, 4, 2, 5, 0, 5, 1, 2};
    p =  (unsigned char*) &obj2;
    clock_t start2 = clock();
    for (int byte = 0; byte < sizeof(Program2); byte++, p++) 
        BYTE(*p);
    clock_t end2 = clock();
    double seconds2 = (double)(end2 - start2) / CLOCKS_PER_SEC;
    cout  << endl << "Time: " << seconds2 << endl << endl;
    Program1 array[2];
    array[0] = {3, 4, 2, 5, 0, 5, 1, 2};
    array[1] = {4, 2 ,5, 0, 4, 1, 2, 0};
    p =  (unsigned char*) &obj2;
    clock_t start3 = clock();
    for (int byte = 0; byte < sizeof(Program1) * 2; byte++, p++) {
        BYTE(*p);
        if (byte == sizeof(Program1) - 1) cout << endl << endl;
    }
    clock_t end3 = clock();
    double seconds3 = (double)(end3 - start3) / CLOCKS_PER_SEC;
    cout  << endl << "Time: " << seconds3 << endl << endl;
    return 0;
}
void BYTE(unsigned char A)
{
    for(int bit = 128; bit >= 1; bit >>= 1) {
	 	cout << (A & bit ? '1' : '0');
    }
	cout << ' ';
}