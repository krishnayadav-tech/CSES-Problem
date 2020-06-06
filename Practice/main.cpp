#include <iostream>
#include <vector>
#include <climits>
using namespace std;
bool done[1000001];
int min_c[1000001];
int path[1000001];
vector<int> arr;
int min_coin(int x){
    if(x == 0){
        return 0;
    }
    if(done[x] == true){
        return min_c[x];
    }
    long long int best = INT_MAX;
    for(int y : arr){
        if(x - y >= 0){
            int temp = min_coin(x-y) + 1;
            if(temp < best){
                best = temp;
                path[x] = y;
            }
        }
    }

    min_c[x] = best;
    done[x] = true;
    return best;
}
int main()
{
    arr.resize(3);
    int n = 3;
    arr[0]  = 1;
    arr[1] = 1000;
    arr[2] = 1500;
    cout << min_coin(14000) << '\n';
    int x = 14000;
    while(x){
        cout << path[x] << ' ';
        x = x - path[x];
    }
    cout << '\n';
    return  0;
}