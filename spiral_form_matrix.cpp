#include <iostream>
using namespace std;
int main()
{
    int n, m, i, j;
    cout << "Enter no of rows and colums : ";
    cin >> n >> m;
    cout << "Enter the array elements " << endl;
    int a[n][m];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    int top = 0, bottom = n - 1, right = m - 1, left = 0, dir = 0;
    cout << "Spiral Form of the Matrix is : ";
    while (top <= bottom && left <= right)
    {
        if (dir == 0) //left to right
        {
            for (i = left; i <= right; i++)
            {
                cout << a[top][i] << " ";
            }
            top++;
        }
        if (dir == 1) //top to bottom
        {
            for (i = top; i <= bottom; i++)
            {
                cout << a[i][right] << " ";
            }
            right--;
        }
        if (dir == 2) //right to left
        {
            for (i = right; i >= left; i--)
            {
                cout << a[bottom][i] << " ";
            }
            bottom--;
        }
        if (dir == 3) //bottom to top
        {
            for (i = bottom; i >= top; i--)
            {
                cout << a[i][left] << " ";
            }
            left++;
        }
        dir = (dir + 1) % 4;
    }
}