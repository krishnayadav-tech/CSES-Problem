// Problem Link - https://my.newtonschool.co/playground/code/rmzcozyf8f/

#include <bits/stdc++.h>
using namespace std;
int isPrimeArray[1000000];
void isPrime(){
    fill(isPrimeArray,isPrimeArray+1000000,true);
    isPrimeArray[0] = false;
    isPrimeArray[1] = false;
    for(int i=2;i<=sqrt(1000000);i++){
        if(isPrimeArray[i] == true){
            for(int j=i*i;j<1000000;j=j+i){
                isPrimeArray[j] = false;
            }
        }
    }
}

long long int euler_totient(int n){
    
    
        if(isPrimeArray[n]){
            return n-1;
        }
    
        double x = n;
        for(int i=2; (i*i) <= n;i++){
            if(n%i == 0 && isPrimeArray[i]){
                x = (x * (i - 1))/i;
            }
            if(n%i == 0){
                int y = n/i;
                if(i != y && isPrimeArray[y]){
                    x = (x * (y - 1))/y;
                }
            }
        }
        return x;
    }
    

void solve()
{
    int n;
    cin >> n;
    set<int> abc;
    for(int i=1;i<=sqrt(n);i++){
        if(n%i == 0){
            abc.insert(i);
            abc.insert(n/i);
        }
    }
    long long int sum = 0;
    for(int d : abc){
        int x = n/d;
        int y = euler_totient(x);
        sum = sum + (y * d);
    }
    cout << sum << endl;
}


void test()
{
    int t;
    cin >> t;
    while(t--)
        solve();
}


int main()
{   

    isPrime();
    test();
    return 0;
}
