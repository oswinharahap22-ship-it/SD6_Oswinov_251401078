#include <iostream>
using namespace std;

int main()
{
    system("cls");
    int arr[3][3][4], n = 2;

    cout << "Array 3D\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++) 
        {
            for (int k = 0; k < 4; k++)
            {
                arr[i][j][k] = n;
                cout << arr[i][j][k] << "\t";
                if (k < 3) cout << " - \t"; 
                if (k % 2 == 0) {
                    n -= 1;
                } else {
                    n += 2;
                }
            }
            cout << "\n";
        }
        cout << "\n";
    }

    return 0;
}