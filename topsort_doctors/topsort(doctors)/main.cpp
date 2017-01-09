#include <iostream>
#include <vector>

using namespace std;

int n, m, x,y;

int used[1000];
vector <int> v[1000];
vector <int> res;

void dfs (int k){
    
    used[k] = 1;
    
    for(int i=0; i<v[k].size(); i++){
        
        
        if(used[v[k][i]]==0){
            dfs(v[k][i]);
            res.push_back(v[k][i]);
            
        }
    }
}


int main(){
    
    cin>>n>>m;
    
    for(int i=0; i<m; i++){
    
        cin>>x>>y;
        v[x].push_back(y);
    }
    
    int f;
    cin>>f;
    
    dfs(f);
    res.push_back(f);
    
    for(int i=0; i<n; i++){
        
        if(used[i]==0){
        
            dfs(i);
            res.push_back(i);
            
        }
    }
    
    
    for(int i=0; i<n; i++){
        
        cout<<res[i]<<" ";
    
    }
    cout<<endl;

    return 0;

}
