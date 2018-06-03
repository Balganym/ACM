#include <iostream>
#include <stack>
#include <deque>
#include <queue>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstdio>
#include <map>
#include <set>
typedef long long ll;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
using namespace std;
const int inf = 1e9;
const ll INF = 1e18;
int n, m, a, b;
vector <int> v[100100];
vector<int> comp[100100];
int cnt;
bool u[100100];

void dfs(int k){
    
    u[k] = true;
    comp[cnt-1].pb(k);
    for(int i=0; i<v[k].size(); i++){
        if(!u[v[k][i]]){
            dfs(v[k][i]);
        }
    }
}

int main(){
    
    scanf("%d%d", &n,&m);
    
    for(int i=0; i<m; i++){
        cin>>a>>b;
        a--; b--;
        v[a].pb(b);
        v[b].pb(a);
    }
    
    for(int i=0; i<n; i++){
        
        if(!u[i]){
            cnt++;
            dfs(i);
        }
            
    }
    
    cout<<cnt<<endl;
    
    for(int i=0; i<cnt; i++){
        cout<<comp[i].size()<<endl;
        for(int j=0; j<comp[i].size(); j++){
            cout<<comp[i][j]+1<<" ";
        }
        cout<<endl;
    }
    return 0;
}
