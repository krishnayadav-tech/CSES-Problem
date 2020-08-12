#include <iostream>
#include <chrono>
using namespace std;
int X[8] = { 2, 1, -1, -2, -2, -1, 1, 2 }; 
int Y[8] = { 1, 2, 2, 1, -1, -2, -2, -1 }; 
bool isValid(int a,int b,int n){
    if(a < 1 or a > n){
        return false;
    }
    if(b < 1 or b > n){
        return false;
    }
    return true;
}

void solve(int i)
{
    int count = 0;
    int total = 0;
    int touch = 0;
    for(int j=1;j<=i;j++){
        if(j <= 2 or j + 2 >= i){
            for(int k=1;k<=i;k++){
                count = 0;
                touch++;
                for(int l=0;l<8;l++){
                    bool x= isValid(j+X[l],k+Y[l],i);;
                    if(x == true){
                        count++;
                    }
                }    
                total = total + (i*i - 1 - count);                
            }   
        }else{
            for(int k=1;k<=2;k++){
                touch++;
                count = 0;
                for(int l=0;l<8;l++){
                    bool x= isValid(j+X[l],k+Y[l],i);;
                    if(x == true){
                        count++;
                    }
                }    
                total = total + (i*i - 1 - count);
            }
            for(int k=i-1;k<=i;k++){
                touch++;
                count = 0;
                for(int l=0;l<8;l++){
                    bool x= isValid(j+X[l],k+Y[l],i);;
                    if(x == true){
                        count++;
                    }
                }    
                total = total + (i*i - 1 - count);
            }
        }
    }
    int restblock = (i*i) - touch;
    total = total + (restblock * ((i*i) -1 - 8));
    cout << total/2 << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    long long int total = 0;   
    for(long long int i=1;i<=n;i++){
        total = 0;
        if(i <= 3)
            solve(i);       
        else{
            total = total + (4*((i*i) - 1 - 2));
            total = total + (4*((i*i) - 1 - 3));
            total = total + (4*((i*i) - 1 - 3));
            total = total + (4*((i*i) - 1 - 4));
            long long int rest = 4*(i - 4)*((i*i) - 1 - 4);
            total = total + rest;
            rest = 4*(i - 4)*((i*i) - 1 - 6);
            total = total + rest;
            total = total + (((i-4)*(i-4))  * (i*i -1 - 8));
            cout << total/2 << '\n';
        }
    }

    return 0;
}