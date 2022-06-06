#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<vector<int>> A(2, vector<int>(2));
	A[0][0] = 1;
	A[0][1] = 2;
	A[1][0] = 3;
	A[1][1] = 4;
    for (int i = 0; i < A.size(); i++) {
        int temp = A[i][A.size() - 1];
        for (int j = 0; j < A.size(); j++) {
            A[j][A.size() - i - 1] = A[i][j];
        }
        A[A.size() - 1][A.size() - i - 1] = temp;
    }
	cout << A[0][0] << ' ' << A[0][1] << endl;
	cout << A[1][0] << ' ' << A[1][1] << endl;
    return 0;
}