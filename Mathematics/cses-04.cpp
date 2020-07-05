#include <bits/stdc++.h>
using namespace std;
int main(int size,char** args)
{
    // basic input output preset
    if(size >= 2){
        string args2 = args[1];
        if(args2 == "-onlinejudge"){
            freopen("input.txt","r",stdin);
            // freopen("output.txt","w",stdout);
        }
    }
    int n;
    cin >> n;
    int arr[n];
    int freq[1000001] = {0};
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    for(int i=0;i<n;i++){
        double sqrt_n = sqrt(arr[i]);
        for(int j=1;j<sqrt_n;j++){
            if(arr[i] % j == 0){
                freq[j]++;
                freq[arr[i]/j]++;
            }
                
        }
        
        if((int)sqrt_n * (int)sqrt_n == n)
            freq[(int)sqrt_n]++;
    }
    int maxe;
    for(int i=0;i<1000001;i++){
        if(freq[i] > 1){
            maxe = i;
        }
    }
    cout << maxe << '\n';
    return 0;
}