#include <iostream>
#include <unistd.h>
using namespace std;
bool arr[7][7];
int X[4] = {0,0,-1,1};
int Y[4] = {-1,1,0,0};
int count = 0;
void solve(string& abc,int pos,int i,int j)
{
    if(pos == abc.size() && (i == 6 and j == 0))
    {
        count++;
        return;
    }

    if(i == 6 and j == 0){
        return;
    }

    if(pos == abc.size()){
        return;
    }
    bool x = (i > 0 and i < 6) && (arr[i+1][j] == false && arr[i-1][j] == false);
    bool y = ((j ==6 or arr[i][j+1] == true) && (j == 0 or arr[i][j-1] == true));
    if(x && y)
        return;
    x = (j > 0 and j < 6) && (arr[i][j-1] == false && arr[i][j+1] == false);
    y = ((i == 6 or arr[i+1][j] == true) && (i == 0 or arr[i-1][j] == true));
    if(x && y)
        return;

    if(abc[pos] == '4'){
        for(int x=0;x<4;x++){
            if(arr[i+X[x]][j+Y[x]] == false && (i+X[x] >= 0 and i+X[x] < 7) && (j+Y[x] >= 0 and j+Y[x] < 7)){
                arr[i+X[x]][j+Y[x]] = true;
                solve(abc,pos+1,i+X[x],j+Y[x]);
                arr[i+X[x]][j+Y[x]] = false;
            }
        }
    }else{
        int x = abc[pos] - '0';
        if(arr[i+X[x]][j+Y[x]] == false && (i+X[x] >= 0 and i+X[x] < 7) && (j+Y[x] >= 0 and j+Y[x] < 7)){
            arr[i+X[x]][j+Y[x]] = true;
            solve(abc,pos+1,i+X[x],j+Y[x]);
            arr[i+X[x]][j+Y[x]] = false;
        }
    }
}
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a;
    string b;
    cin >> a;
    for(int i=0;i<a.size();i++){
        if(a[i] == 'L')
            b.push_back('0');
        else if(a[i] == 'R')
            b.push_back('1');
        else if(a[i] == 'U')
            b.push_back('2');
        else if(a[i] == 'D')
            b.push_back('3');
        else 
            b.push_back('4');
    }
    arr[0][0] = true;
    solve(b,0,0,0);
    cout << count << '\n';
    return 0;
}