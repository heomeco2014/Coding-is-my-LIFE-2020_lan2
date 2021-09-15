#include <iostream>
#include <queue>
#include <vector>
#include <fstream>
#include <climits>
typedef long long ll;
using namespace std;

// 1 2 3 4 2
int *findLongestAscendingSubarray(int *a, int n, int &length)
{
    int count = 0, max = INT_MIN;
    int start, end;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j < n - 1; ++j)
        {
            if (a[j + 1] > a[j])
            {
                count++;
            }
            else
            {
                if (count > max)
                {
                    max = count;
                    start = i;
                    end = j;
                }
                count = 0;
            }
        }
    }
    length = max;
    int *b = new int[5];
    for (int i = 0; i < max; i++)
    {
        b[i] = a[start++];
    }
    return b;
}

void print(int *a, int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << a[i] << " ";
    }
}

void mutiple2Matrices(int**a, int aCol, int aRow, int **b, int bCol, int bRow, int**&c, int cCol, int cRow){
    if(aCol != bRow) return;
    for(int i = 0; i < aCol; ++i)
    {
        for(int j = 0; j < bRow; j++){
            int sum = 0;
            for(int k = 0; k < bRow; k++){
                sum+=a[i][k]*b[k][j];
                c[i][j] = sum;
            }           
        }
    }
    cCol = aRow;
    cRow = bCol;
}
int** generateMatrix2(int* a, int* b, int na, int nb){
    int**c = new int*[2];
    for(int i = 0; i < 3; i++){
        c[i] = new int;
    }

    for(int i = 0 ; i < na;i++){
        for(int j = 0; j < nb; j++){
            c[i][j] = a[i]*b[j];
        }
    }
    return c;
}

void printMatrix(int**a, int row, int col){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int*a = new int[3]{1,2,3};
    int*b = new int[3]{2,4,6};
    int** c = generateMatrix2(a,b,3,3);
    printMatrix(c,2,3);

    return 0;
}