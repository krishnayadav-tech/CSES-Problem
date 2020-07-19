#include <iostream>
#include <climits>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <utility>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <sstream>
#include <unistd.h>
using namespace std;
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define isint(a) ((int)a==a)
#define mod 1000000007
#define INF 1e9
typedef long long int ll;
typedef pair<int,int> pi;
string preprocess(string a,int n){
    string preprocessed;
    for(int i=0;i<n;i++){
        preprocessed.push_back('$');
        preprocessed.push_back(a[i]);
    }
    preprocessed.push_back('$');
    return preprocessed;
}
int main(int size,char** args)
{
    // basic input output preset
    if(size >= 2){
        string args2 = args[1];
        if(args2 == "-onlinejudge"){
            freopen("input.txt","r",stdin);
            freopen("output.txt","w",stdout);
        }
    }
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);   
    string a;
    cin >> a;
    int n = a.size();
    string preprocessed = preprocess(a,n);
    int pren = preprocessed.size();
    int arr[pren]  = {0};
    int center = 0;
    int right = 0;
    for(int i=0;i<pren;i++){
        int left_mirror = center - (i - center);
        if(right > i){
            arr[i] = min(right - i,arr[left_mirror]);
        }else{
            arr[i] = 0;
        }

        while((i+1+arr[i] < pren && i-1-arr[i] >= 0) and preprocessed[i+1+arr[i]] == preprocessed[i-1-arr[i]])
        {
            arr[i]++;
        }

        if(i+arr[i] > right){
            right = i+arr[i];
            center = i;
        }


    }

    int maxi = 0;
    int maxs = 0;
    for(int i=0;i<pren;i++)
    {
        if(arr[i] > maxs){
            maxi = i;
            maxs = arr[i];
        }
    }

    string ans;
    for(int i=maxi-1;i>=maxi-maxs;i--){
        if(preprocessed[i] != '$')
        {
            ans.push_back(preprocessed[i]);
        }
    }
    reverse(ans.begin(),ans.end());
    if(preprocessed[maxi] != '$')
    ans.push_back(preprocessed[maxi]);
    for(int i=maxi+1;i<=maxs+maxi;i++){
        if(preprocessed[i] != '$')
        {
            ans.push_back(preprocessed[i]);
        }
    }
    cout << ans << endl;
    return 0;
}