#include <iostream>
using namespace std;
int main()
{
    long long int n;
    cin >>  n;
    long long int totalsum = (n * (n+1))/2;
    if(totalsum % 2 == 1){
        cout << "NO" << '\n';
        return 0;
    }
    long long int half = totalsum / 2;
    long long int temp = 0;
    int where = 0;
    for(int i=1;i<=n;i++){
        if(temp + i > half){
            where = i ;
            break;
        }else{
            temp = temp + i;
        }
    }
    long long int firstset = 0;
    long long int secondset = 0;
    if(totalsum == half){
        cout << "YES" << '\n';
        cout << where-1 << '\n';
        for(int i=1;i<where;i++){
            cout << i << ' ';
        }
        cout << n - (where - 1) << '\n';
        for(int i=where;i<=n;i++){
            cout << i << ' ';
        }
        cout << '\n';
    }else{
        long long int diff = half - temp;
        for(int i=where;i<=n;i++){
            if(i-diff < where){
                secondset = i-diff;
                firstset = i;
            }
        }
        cout << "YES" << "\n";
        cout << where - 1 << '\n';
        for(int  i=1;i<where;i++){
            if(i == secondset){
                cout << firstset << ' ';
            }else{
                cout << i << ' ';
            }
        }
        cout << '\n';
        cout << n - (where-1) << '\n';
        for(int i=where;i<=n;i++){
            if(i == firstset){
                cout << secondset << ' ';
            }else{
                cout << i << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}