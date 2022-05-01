#include <iostream>
using namespace std;

char *substring(char arrayString[], int position, int length);

int main()
{
    char arrayString[] = "abcdefg";
    char *subString = substring(arrayString, 3, 4);
    for (int i = 0; i < 4; i++)
    {
        cout << subString[i];
    }
    delete [] subString;
    return 0;
}

char *substring(char arrayString[], int position, int length)
{
    char *subString = new char[length];
    for (int i = position - 1; i < length + position; i++)
        subString[i - position + 1] = arrayString[i];
    subString[length] = 0;
    return subString;
}