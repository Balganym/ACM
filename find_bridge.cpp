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
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define F(i, n) for(int i=0; (int)i<n; ++i)

int n, m;
vector<int> v[100100];
bool u[100100];
int tin[100100], fup[100100], t;



void bridge(int a, int b){
    cout<<a+1<<" "<<b+1<<endl;
}

void dfs(int k, int p){
    
    u[k] = 1;
    tin[k] = fup[k] = t++;
    
    F(i, v[k].size()){
        int to = v[k][i];
        if(to == p)
            continue;
        if(u[to])
            fup[k] = min(fup[k], tin[to]);
        else{
            dfs(to, k);
            fup[k] = min(fup[k], tin[to]);
            if(fup[to]>tin[k])
                bridge(k, to);
        }
    }

}

void find(){
    
    F(i, n){
        if(!u[i])
            dfs(i, -1);
    }
}


int main(){
    
    scanf("%d%d", &n,&m);
    
    F(i, m){
        int a, b;
        scanf("%d%d", &a,&b);
        a--; b--;
        v[a].pb(b);
        v[b].pb(a);
    }
    
    find();
    
      return 0;
}
