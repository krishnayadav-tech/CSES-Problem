#include <iostream>
#include <climits>
#include <cmath>
#include <string>
#include <chrono>
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
typedef vector<int> vi;
vi segarr[200000];
int indexofarr[200000];
int indexinarr[200000];
int main(int size,char** args)
{
    if(size >= 2){
        string args2 = args[1];
        if(args2 == "-onlinejudge"){
            freopen("input.txt","r",stdin);
            // freopen("output.txt","w",stdout);
        }
    }
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);   
    int n,q;
    cin >> n;
    fill(indexofarr,indexofarr+n,-1);
    fill(indexinarr,indexinarr+n,-1);
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
        arr[i]--;
    }
    int j = 0;
    for(int i=0;i<n;i++){
        int start = i;
        while(true){
            if(indexofarr[start] != -1){
                j++;
                break;
            }
            segarr[j].push_back(start);
            indexofarr[start] = j;
            indexinarr[start] = segarr[j].size() - 1;
            start = arr[start];
        }
    }
    q = n;
    int vachuvana = 0;
    map<int,int> temp;
    while(q--){
        int a = vachuvana;
        vachuvana++;
        int id1 = indexofarr[a];
        long long int sum = 0;
        temp.clear();
        while(true){
            int id1 = indexofarr[a];
            int id2 = indexinarr[a];
            map<int,int> :: iterator it = temp.find(id1);
            if(it == temp.end()){
                temp.insert({id1,id2});
                sum = sum + segarr[id1].size()  - indexinarr[a];
                a = arr[segarr[id1][segarr[id1].size()-1]];
            }else{
                if(it->second <= id2){
                    cout << sum << '\n';
                    break;
                }else{
                    sum = sum +  it->second - id2;
                    cout << sum << '\n';
                    break;
                }
            }
        }
    }

    return 0;
}