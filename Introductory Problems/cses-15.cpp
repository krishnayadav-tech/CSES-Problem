#include <iostream>
using namespace std;
int count = 0;
bool isvalid(int pos,int i,char arr[][8]){
    if(arr[pos][i] == '*')
        return false;
    for(int j=0;j<pos;j++){
        if(arr[j][i] == 'T'){
            return false;
        }
    }
    int l,m;
    l = pos;
    m = i;
    l = pos-1;
    m = i-1;
    while(l >= 0 and m >= 0){
        if(arr[l][m] == 'T')
        {
            return false;
        }
        l--;
        m--;
    }

    l = pos - 1;
    m = i + 1;
    while(l >= 0 and m < 8){
        if(arr[l][m] == 'T')
            return false;
        l--;
        m++;
    }
    return true;
}
void n_queens(int pos,char arr[][8]){
    if(pos == 8){
        count++;
        return;
    }
    for(int i=0;i<8;i++){
        bool x = isvalid(pos,i,arr);
        if(x == true){
            arr[pos][i] = 'T';
            n_queens(pos+1,arr);
            arr[pos][i] = '.';
        }
    }
}
int main()
{
    char arr[8][8];
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cin >> arr[i][j];
        }
    }

    n_queens(0,arr);
    cout << count << '\n';
    return 0;
}