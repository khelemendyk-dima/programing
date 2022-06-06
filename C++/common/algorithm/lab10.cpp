#include <iostream>
using namespace std;

void init(void);
void randKeys();
int hash(int key);
int insert(int key, int adr);
int search(int key);

#define N 20		//кількість записів у таблиці
#define EMPTY -1

struct HashTable
{	
	int key;
	int protocol;
};
HashTable hashTable[N];
int keys[N];

int main()
{   
	int i, key, res;
	
	init();
	randKeys();
	
	cout << "\nKeys -> ";
	for (i = 0; i < N; i++)
		cout << keys[i] << " ";
	
	for (i = 0; i < N; i++)
		insert(keys[i], i);

	cout << "\nInput searched keys (key < 0 = exit) -> ";
	cin >> key;
	while (key >= 0) {	
		res = search(key);
		if (res == EMPTY)	  cout << " not search \n";
		else	cout << " " << res << "\n" ;
		cout << "Input searched keys (key < 0 = exit) -> ";
		cin >> key; 
	}
	return 0;
}

int hashing(int key, int n)		//функція хешування
{     
	return (key % n);
}
void init()		//ініціалізація хеш-таблиці
{   
	for (int i = 0; i < N; i++)
 		hashTable[i].protocol = EMPTY;
}
void randKeys()
{
	for (int i = 0; i < N; i++) {
		keys[i] = rand() % 100;
	}
}
int insert(int key, int protocol)	//додавання ключа у хеш-таблицю
{    
	int prot, a1;
	prot = hashing(key, N);
	if (hashTable[prot].protocol != EMPTY) {	
		a1 = prot;
		do {
		    prot = hashing(prot + 1, N);
		} while( !((prot == a1) || (hashTable[prot].protocol == EMPTY)) );
		if (hashTable[prot].protocol != EMPTY)
			return 0;
	}
	hashTable[prot].key = key;
	hashTable[prot].protocol = prot;
	return 1;
}
int search(int key)		//функція пошука ключа
{   
	int prot, a1;
	prot = hashing(key, N);
	if (hashTable[prot].protocol == EMPTY) {
		return EMPTY;
	} else {
		if (hashTable[prot].key == key) {
			return hashTable[prot].protocol;
		} else {     			//місце зайняте іншим ключем
			a1 = hashing(prot + 1, N);
			while((hashTable[a1].key != key) && (a1 != prot)) {
				a1 = hashing(a1 + 1, N);
				if (hashTable[a1].key != key) {
					return EMPTY;
				} else {
					return hashTable[a1].protocol;
				}
			}
		}
	}
}
