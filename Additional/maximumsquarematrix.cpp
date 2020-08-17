#include <iostream>
using namespace std;
int multiarray[1000][1000];    
int largest_submatrix(int id1,int id2)
{
    int DPTable[id1][id2];
    int size = 0;
    for (int i = 0; i < id1; i++)
    {
        for (int j = 0; j < id2; j++)
        {
            DPTable[i][j] = multiarray[i][j];
            if (i and j and multiarray[i][j])
            DPTable[i][j] = min(min(DPTable[i][j-1], DPTable[i -1][j]),DPTable[i - 1][j - 1]) + 1;
            if (size < DPTable[i][j])
            {
                size = DPTable[i][j];
            }
        }
    }
    return size;
}
int main()
{
    int x,y;
    cin >> x >> y;
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            cin >> multiarray[i][j];
        }
    }
    cout << largest_submatrix(x,y) << '\n';
    return 0;
}