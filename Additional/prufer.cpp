#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <list>
#include <utility>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int counting[n] = {0};
    set<int> set2;
    for(int i=0;i<n;i++){
        set2.insert(i);
    }
    vector<int> prufer(n-2);
    for(int& x : prufer){
        cin >> x;
        --x;
        counting[x]++;
        set2.erase(x);
    }

    list<pair<int,int>> ans;
    for(int x : prufer){
        int y = *set2.begin();
        ans.push_back({y,x});
        set2.erase(y);
        counting[x]--;
        if(counting[x] == 0){
            set2.insert(x);
        }
    }

    set<int> :: iterator it,it2;
    it = set2.begin();
    it2 = it;
    it++;
    ans.push_back({*it,*it2});

    for(pair<int,int> x : ans){
        cout << x.first + 1 << ' ' << x.second + 1 << '\n';
    }
    return 0;
}