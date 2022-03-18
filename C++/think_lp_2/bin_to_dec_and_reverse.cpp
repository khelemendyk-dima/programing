// converting decimal numbers to binary and reverse

#include <iostream>
#include <string>
using namespace std;

char askOperation(string query);
void decimalToBinary(string query);
void binaryToDecimal(string query);

int main()
{
    char answer = askOperation("Input (d) for decimal or (b) for binary: ");
    if (answer == 'd')
        decimalToBinary("Input decimal number: ");
    else
        binaryToDecimal("Input binary number: ");
    return 0;
}

char askOperation(string query)
{
    cout << query;
    char answer;
    cin >> answer;
    while (answer != 'd' && answer != 'b')
    {
        cout << "Incorect input data...\nTry again: ";
        cin >> answer;
    }
    return answer;
}
void decimalToBinary(string query)
{
    cout << query;
    int decimal, mod, binary = 0;
    int n = 1;
    cin >> decimal;
    while (decimal)
    {
        int mod = decimal % 2;
        decimal /= 2;
        binary = binary + mod * n;
        n *= 10;
    }
    cout << "Your number is: " << binary << endl;
}
void binaryToDecimal(string query)
{
    cout << query;
    int binary = 11010;
    int mod = 0;
    int decimal = 0;
    int counter = 0;
    cin >> binary;
    while (binary)
    {
        mod = binary % 10;
        if (mod == 1)
        {
            if (counter != 0)
            {
                int number = 1;
                for (int i = 0; i < counter; i++)
                {
                    number *= 2;
                }
                decimal += number;
            }      
            else
                decimal += 1; 
        }
        binary /= 10;
        counter++;
    }
    cout << "Your number is: " << decimal << endl;
}