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
    // chrono::high_resolution_clock::time_point start_t = chrono::high_resolution_clock::now();
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
    int n,q;
    cin >> n >> q;
    fill(indexofarr,indexofarr+n,-1);
    fill(indexinarr,indexinarr+n,-1);
    int arr[n];
    map<pair<int,int>,int> res;
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

    while(q--){
        int a,b;
        cin >> a >> b;
        int x,y;

        a--;
        b--;
        x = a;
        y = b;
        if(res.find({x,y}) != res.end()){
            cout << res.find({x,y})->second << endl;
            continue;
        }
        long long int sum = 0;
        while(true){
            // cout << a << '\n';
            int id1 = indexofarr[a];
            int id2 = indexofarr[b];
            if(id1 == id2){
                int nextele = arr[segarr[id1][segarr[id1].size()-1]];
                if(indexinarr[a] <= indexinarr[b]){
                    sum = sum + indexinarr[b] - indexinarr[a];
                    cout << sum << '\n';
                    res.insert({{x,y},sum});
                    break;
                }else{
                    if(indexofarr[nextele] == id1 && indexinarr[nextele] > indexinarr[b]){
                        cout << -1 << '\n';
                        res.insert({{x,y},-1});
                        break;
                    }else{
                        sum = sum + segarr[id1].size() - 1 - indexinarr[a];
                        a = nextele;
                        sum = sum + 1;
                    }
                }
                
            }else{
                int nextele = arr[segarr[id1][segarr[id1].size()-1]];
                if(indexofarr[nextele] == id1){
                    cout << -1 << '\n';
                    res.insert({{x,y},-1});
                    break;
                }
                sum = sum + segarr[id1].size() - 1 - indexinarr[a];
                a = nextele;
                sum = sum + 1;
            }
        }
    }

    // chrono::high_resolution_clock::time_point end_t = chrono::high_resolution_clock::now();
    // chrono::duration<double> diff = end_t - start_t;
    // cout << diff.count() << endl;
    return 0;
}