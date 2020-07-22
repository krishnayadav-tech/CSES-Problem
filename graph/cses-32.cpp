#include <bits/stdc++.h>
#define max(a,b) (a>b?a:b)
using namespace std;
const int mod = 1e9+7;
const int INF = 1e9;
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
int cell[8][8];
void construct()
{
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            vector<int> x = {1,1,2,2,-1,-1,-2,-2};
            vector<int> y = {2,-2,1,-1,2,-2,1,-1};
            for(int k=0;k<8;k++){
                int x_,y_;
                x_ = i + x[k];
                y_ = j + y[k];
                if((x_ >= 0 and x_ < 8) and (y_ >= 0 and y_ < 8))
                    cell[i][j]++;
            }
        }
    }
}
int res[8][8];
int main()
{
    #ifdef OFFLINE
        Timer t;
        FILE* x = freopen("input.txt","r",stdin);
        FILE* y = freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    construct();
    int i,j;
    cin >> j >> i;
    j--;i--;
    int x_t = 0;
    while(true){
        x_t++;
        cell[i][j] = -1;
        res[i][j] = x_t;
        if(x_t >= 64){
            break;
        }
        int i_,j_;
        vector<int> x = {1,1,2,2,-1,-1,-2,-2};
        vector<int> y = {2,-2,1,-1,2,-2,1,-1};
        int maxe = INF;
        for(int k=0;k<8;k++){
            int x_,y_;
            x_ = i + x[k];
            y_ = j + y[k];
            if((x_ >= 0 and x_ < 8) and (y_ >= 0 and y_ < 8))
            {
                if(cell[x_][y_] > 0){
                    cell[x_][y_]--;
                }
                if(cell[x_][y_] >= 0 and cell[x_][y_] <= maxe){
                    maxe = cell[x_][y_];
                    i_ = x_;
                    j_ = y_;
                }
            }
        }
        
        i = i_;
        j = j_;
    }
 
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cout << res[i][j] << ' ';
        }
        cout << '\n';
    }
    #ifdef OFFLINE
        t.exec_time();
    #endif
    return 0;
}