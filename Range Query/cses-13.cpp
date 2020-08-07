#include <bits/stdc++.h>
#define max(a,b) (a>b?a:b)
using namespace std;

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


vector<int> tree[4001];
vector<int> tree2[4001];
int treesize = 0;
void sizecalc(int i,int ss,int se){
    treesize = max(treesize,i);
    if(ss == se)
        return;
    int mid = ss + (se-ss)/2;
    sizecalc(i*2+1,ss,mid);
    sizecalc(i*2+2,mid+1,se);
}
void construct(int i,int ss,int se,vector<int>& arr,vector<int>& tree){
    if(ss == se){
        tree[i] = arr[ss];
        return;
    }
    int mid = ss + (se-ss)/2;
    construct(i*2+1,ss,mid,arr,tree);
    construct(i*2+2,mid+1,se,arr,tree);
    tree[i] = tree[i*2+1] + tree[i*2+2];
}
unordered_set<int> indexes;
int indexupdate(int i,int ss,int se,int index,vector<int>& tree)
{
    indexes.insert(i);
    if(ss == se){
        tree[i] = (tree[i] + 1) % 2;
        return tree[i];
    }
    int left,right;
    int mid = ss + (se-ss)/2;
    left = tree[i*2+1];
    right = tree[i*2+2];
    if(index <= mid){
        left = indexupdate(i*2+1,ss,mid,index,tree);
    }else{
        right = indexupdate(i*2+2,mid+1,se,index,tree);
    }
    tree[i] = left + right;
    return tree[i];
}

void construct2(int i,int ss,int se){
    if(ss == se){
        for(int j=0;j<treesize;j++){
            tree2[i][j] = tree[ss][j];
        }
        return; 
    }
    int mid = ss + (se-ss)/2;
    construct2(i*2+1,ss,mid);
    construct2(i*2+2,mid+1,se);
    for(int j=0;j<tree2[i*2+1].size();j++){
        tree2[i][j] = (tree2[i*2+1][j] + tree2[i*2+2][j]);
    }
}


void indexupdate2(int i,int ss,int se,int index){
    if(ss == se){
        for(int x : indexes){
            tree2[i][x] = tree[ss][x];
        }
        return; 
    }
    int mid = ss + (se-ss)/2;
    if(index <= mid){
        indexupdate2(i*2+1,ss,mid,index);
    }else{
        indexupdate2(i*2+2,mid+1,se,index);
    }
    for(int x : indexes){
        tree2[i][x] = tree2[i*2+1][x] + tree2[i*2+2][x];
    }
}


int getans(int i,int ss,int se,int rs,int re,vector<int>& tree){
    if(ss >=rs && se <= re){
        indexes.insert(i);
        return tree[i];
    }
    if(rs > se or re < ss){
        return 0;
    }
    int mid = ss + (se - ss)/2;
    return getans(i*2+1,ss,mid,rs,re,tree) + getans(i*2+2,mid+1,se,rs,re,tree);
}

int getans2(int i,int ss,int se,int rs,int re){
    
    if(rs > se or re < ss){
        return 0;
    }
    if(ss >=rs && se <= re){
        int sum = 0;
        for(int x : indexes){
            sum = sum + tree2[i][x];
        }
        return sum;
    }
    int mid = ss + (se - ss)/2;
    return getans2(i*2+1,ss,mid,rs,re) + getans2(i*2+2,mid+1,se,rs,re);
}

int main()
{
    #ifdef OFFLINE
        Timer t;
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    int q;
    cin >> n >> q;
    sizecalc(0,0,n-1);
    treesize = treesize + 1;
    vector<int> arr[n];
    for(int i=0;i<n;i++){
        arr[i].resize(n);
        tree[i].resize(treesize);
    }
    for(int i=0;i<treesize;i++){
        tree2[i].resize(treesize);
    }
    //input
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char abc;
            cin >> abc;
            if(abc == '.'){
                arr[i][j] = 0;
            }else{
                arr[i][j] = 1;
            }
        }
    }
    
    //construction
    for(int i=0;i<n;i++){
        construct(0,0,n-1,arr[i],tree[i]);
    }
    construct2(0,0,n-1);
    //query ans
    int type;
    while(q--){
        indexes.clear();
        cin >> type;
        if(type == 1){
            int a,b;
            cin >> a >> b;
            a--;b--;
            indexupdate(0,0,n-1,b,tree[a]);
            indexupdate2(0,0,n-1,a);
            continue;
        }
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        a--;b--;c--;d--;
        getans(0,0,n-1,b,d,tree[a]);
        cout << getans2(0,0,n-1,a,c) << '\n';
    }
    #ifdef OFFLINE 
        t.exec_time();
    #endif   
    
    return 0;
}