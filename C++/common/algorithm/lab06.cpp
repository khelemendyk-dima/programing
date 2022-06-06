#include <iostream>
#include <ctime>
using namespace std;

struct Node {
    char val[50];
    Node* next;
};
void writeToList(char s[], struct Node *node);
//поиск вхождения подстроки в строку	
int SubstringInString(char s[], char sb[], int &l);

int main ()
{ 
    setlocale(LC_ALL, "Rus");
    char *strArray = new char[50];
    char *substrArray = new char[50]; 
    struct Node strList;
    struct Node substrList;
    int poz;

    cout << "Which string?: ";
    gets(strArray);
    writeToList(strArray, &strList);
    cout << "Which substring?: ";
    gets(substrArray);
    writeToList(substrArray, &substrList);

    int len;
    clock_t start1 = clock();
    poz = SubstringInString(strArray, substrArray, len);
    clock_t end1 = clock();
    double seconds1 = (double)(end1 - start1) / CLOCKS_PER_SEC;
    if (poz > 0) cout << poz <<" len = "<< len << endl;
    else cout << "substring in string error \n";
    cout  << "Time from array: " << seconds1 << endl << endl;
    
    clock_t start2 = clock();
    poz = SubstringInString(strList.val, substrList.val, len);
    clock_t end2 = clock();
    double seconds2 = (double)(end2 - start2) / CLOCKS_PER_SEC;
    if (poz > 0) cout << poz <<" len = "<< len << endl;
    else cout << "substring in string error \n";
    cout  << "Time from linked list: " << seconds2 << endl << endl;

    delete strArray;
    delete substrArray;
    return 0;
}

void writeToList(char s[], struct Node *node)
{
    int i = 0;
    while (i != 50) {
        node->val[i] = s[i];
        i++;
    }
}	
int SubstringInString(char s[], char sb[], int &l)		
{  
    l = 0;
    int i = 0, j = 0;
    while(s[i] && sb [j] && s[i] != sb[j]) i++;	//поиск первого совпадения первого символа подстроки			
    if (s[i] == sb[j])
    {   
        while(s[i] && sb [j] && s[i] == sb[j]) { // определение длины цепочки совпавших символов
            j++;
            i++;
        }
        l = j;   
        return i - l;
    }
    return -1;
}



// int stackArr[SIZE];
// unsigned top;

// void StackInit(void);
// void StackClr(void);
// int StackSize(void);
// int StackArrayPush(int Elem);
// int StackArrayPop(int &p);

// void StackInit(void) 
// {    
//     top = SIZE;   
// } 
// void StackClr(void)
// {    
//     top = SIZE;   
// } 
// int StackSize(void)
// {    
//     return (SIZE-top);
// } 
// int StackArrayPush(int Elem)  
// {  
//     if(top == 0) {
//         cout << "ERROR! Stack full..." << endl; 
//         return 0;    
//     } 
//     top = top - 1; 
//     stackArr[top] = Elem; 
//     return 1;
// }
// int StackArrayPop(int &p)
// { 
//     if (top == SIZE) {
//         cout << "ERROR! Stack empty..." << endl; 
//   	    return 0;    
//     } 
//     p = stackArr[top]; 
//     top = top + 1; 
//     return 1;   
// } 