#include "stdlib.h"
#include "iostream"
#define PB(value)(byte*)(value)
using namespace std;

typedef unsigned char byte;
typedef unsigned int dword;

template <class T> void show (const T &value);
void BYTE(char A);

int main() 
{
    int val1 = 0;
	cout << "Enter int value: ";
	cin >> val1;
	show(val1);

    long double val2 = 0;
    cout << "Enter long double value: ";
	cin >> val2;
	show(val2);

    int val3 = 0;
    cout << "Enter char value: ";
	cin >> val3;
    char *p = (char*) &val3;
	for (int i = 0; i < sizeof(int); i++, p++) {
        BYTE(*p);
    }
    cout << endl;

    int size = 0;
    cout << "Enter size of array: ";
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++) {
        cout << "Enter " << i + 1 << "th element of array(integer): ";
        cin >> arr[i];
    }
    for (int i = 0; i < size; i++) {
        show(arr[i]);
    }
    return 0;
}

template <class T> void show (const T &value)
{	
    for (dword i = 0; i < sizeof(T); i++) {	
        byte Byte =*(PB(&value) + i);
		for (dword j = 0; j < 8; j++) {
			cout << dword((Byte >> (7 - j)) & 1);
        }
		cout << ' ';
	}
	cout << endl;
}

void BYTE(char A)
{	for(int bit = 128; bit >= 1; bit >>= 1) {
	 	cout << (A & bit ? '1' : '0');
    }
    cout << ' ';
}