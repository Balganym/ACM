#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
typedef long long ll;
using namespace std;
long long n, m, a,b,w,cnt, minn = 1e9, inx;
bool used[100010];
vector <pair<ll, ll>> v[100010];
vector <long long> d(100010, 1e9);
long long par[100010];
vector <long long> path;

void dei(long long u){

    used[u] = true;
    
    for(size_t i=0; i<v[u].size(); i++){
        d[v[u][i].first] = min(d[u]+v[u][i].second,d[v[u][i].first]);
        if(d[v[u][i].first] == d[u] + v[u][i].second)
            par[v[u][i].first] = u;
    }
}


int main(){

    cin>>n>>m;
    
    d[0] = 0;
    for(int i=0; i<m; i++){
        cin>>a>>b>>w;
        a--;
        b--;
        
        v[a].push_back(make_pair(b,w));
        v[b].push_back(make_pair(a,w));
        
    }
    
    for (size_t i=0; i<n; i++){
        for(size_t j=0; j<n; j++){
            if(!used[j]){
                minn = min(minn, d[j]);
                if(minn == d[j])
                    inx = j;
                
                if(minn == 1e9 && j == n-1){
                    cout<<-1;
                    return 0;
                }
            }
        }
        
        dei(inx);
        minn = 1e9;
        
    }
    
    
    for(size_t i=n-1; i!=0; i=par[i])
        path.push_back (i);
    path.push_back (0);
    reverse (path.begin(), path.end());
    
    
    
    for(int i=0; i<path.size(); i++){
        cout<<path[i]+1<<" ";
    }
    
    return 0;
}
