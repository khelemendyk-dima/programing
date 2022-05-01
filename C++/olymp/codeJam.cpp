#include <iostream>
using namespace std;

void Printer3D(int t, int *c, int *m, int *y, int *k);

int main()
{
    int t;
    cin >> t;
    int *c = new int[t * 3];
    int *m = new int[t * 3];
    int *y = new int[t * 3];
    int *k = new int[t * 3];
    for (int i = 0; i < t * 3; i++) {
        cin >> c[i];
        cin >> m[i];
        cin >> y[i];
        cin >> k[i];
    }
    Printer3D(t, c, m, y, k);
    delete [] c;
    delete [] m;
    delete [] y;
    delete [] k;
    return 0;
}

void Printer3D(int t, int *c, int *m, int *y, int *k)
{
    int x = 1;
    int mode = 0;
    int counter = 0;
    for (int i = 0; i < t; i++) {
        cout << "Case #" << x << ": ";
        for (int j = 0; j < 3; j++) {
            for (int p = counter; p < counter + 4; p++) {
                if ((c[p] + m[p] + y[p] + k[p]) == 1000000) {
                    mode = 1;
                    cout << *c << ' ' << *m << ' ' << *y << ' ' << *k << endl;
                }
            }
            counter += 4;
        }
        if (mode == 0) {
            cout << "IMPOSSIBLE" << endl;
        }
        mode = 0;
        x++;
    }
}