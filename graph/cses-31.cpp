#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
struct Edges{
public:
    void push_back(int a){
        abc.push_back(a);
    }
    unsigned int size(){
        return abc.size();
    }
    int& operator[](int x){
        return abc[x];
    }
    vector<int> :: iterator begin(){
        return abc.begin();
    }
    vector<int> :: iterator end(){
        return abc.end();
    }
    int position  = 0;
private:
    vector<int> abc;
};
bool isSet(int num,int pos){
    return num & (1 << pos);
}
int setBit(int num,int pos){
    num = num | (1 << pos);
    return num;
}

int n;
int atFinal = 0;
int admatrix[20][20];
int ans[2 << 20][20];
bool done[2 << 20][20];
int dfs(int pos,int node,vector<Edges>& edge){
    if(pos == atFinal){
        return 1;
    }
    if(node == n-1)
        return 0;
    if(done[pos][node])
        return ans[pos][node];
    long long int value = 0;
    for(int x : edge[node]){
        if(isSet(pos,x) == true){
            continue;
        }       
        int new_p = setBit(pos,x);
        value = value + ((admatrix[node][x] * (long long int)dfs(new_p,x,edge)) % mod);    
        value = value % mod;   
    }
    done[pos][node] = true;
    return ans[pos][node] = value;
}

class Timer{
public:
    Timer(){
        start_t = chrono::high_resolution_clock::now();
    }

    ~Timer(){
        end_t = chrono::high_resolution_clock::now();
    }

    void exec_time()
    {
        end_t = chrono::high_resolution_clock::now();
        chrono::duration<double> diff = end_t - start_t;
        cout << fixed <<  diff.count() << endl;
    }

private:
    chrono::high_resolution_clock::time_point start_t;
    chrono::high_resolution_clock::time_point end_t;
    
};

int main()
{
    #ifdef OFFLINE
        Timer t;
        FILE* x = freopen("input.txt","r",stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m;
    cin >> n;
    cin >> m;
    atFinal = pow(2,n) - 1;
    vector<Edges> edge(n);
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        a--;b--;
        admatrix[a][b]++;
        if(admatrix[a][b] == 1){
            edge[a].push_back(b);
        }
    }
    
    int pos = 1;
    cout << dfs(pos,0,edge) << endl;
    #ifdef OFFLINE
        t.exec_time();
    #endif
    return 0;
}