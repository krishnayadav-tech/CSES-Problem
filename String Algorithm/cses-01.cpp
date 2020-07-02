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
struct Trie{
    bool end = false;
    unordered_map<char,Trie*> abc;
};
 
    
bool search(Trie* root,string key)
{
    Trie* curr = root;
    for(int i=0;i<key.size();i++)
    {
        if(curr->abc.find(key[i]) == curr->abc.end())
            return false;
        curr = curr->abc[key[i]];
    }
    return curr->end;
}
 
void insert(Trie* root,string key){
    Trie* curr = root;
    for(int i=0;i<key.size();i++)
    {
        if(curr->abc.find(key[i]) == curr->abc.end())
            curr->abc.insert({key[i],new Trie()});
        curr  = curr->abc[key[i]];
    }
    curr->end = true;
}
 
 
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
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);   
    vector<int> edge[5001];
    int indegree[5001] = {0};
    Trie* root = new Trie();
    string word;
    cin >> word;
    int n;
    cin >> n;
    
    for(int i=0;i<n;i++){
        string temp;
        cin >> temp;
        insert(root,temp);  
    }
    Trie* curr = root;
    for(int i=0;i<word.size();i++){
        curr = root;
        for(int j=i;j<=word.size();j++){
            
            if(curr != root && curr->end == true){
                edge[i].push_back(j);
                indegree[j]++;
            }
            if(j==word.size())
                break;
            if(curr->abc.find(word[j]) == curr->abc.end())
                break;
            curr = curr->abc[word[j]];
        }
        
    }
 
    
    ll ans[5001] = {0};
    queue<int> abc;
    ans[0] = 1;
    for(int i=0;i<word.size();i++){
        if(indegree[i] == 0){
            abc.push(i);
        }
    }
    while(abc.size() > 0){
        int x  = abc.front();
        for(int y : edge[x]){
            indegree[y]--;
            ans[y] = ans[y] + ans[x];
            ans[y] = ans[y] % mod;
            if(indegree[y] == 0){
                abc.push(y);
            }
        }       
        abc.pop();
    }
    cout << ans[word.size()] << '\n';
    return 0;   
}