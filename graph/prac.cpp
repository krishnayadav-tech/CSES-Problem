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
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
using namespace std;
#define mod 1000000007
typedef long long int ll;
int main()
{
//     freopen("input.txt","r",stdin);
//     freopen("output.txt","w",stdout);
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    list<int> a;
    a.push_back(10);
    queue<list<int>> abc;
    abc.push(a);
    a.push_back(15);
    abc.push(a);
    while(abc.size() > 0){
        for(int x : abc.front()){
            cout << x << ' ';
        }
        cout << '\n';
        abc.pop();
    }
    return 0;
}