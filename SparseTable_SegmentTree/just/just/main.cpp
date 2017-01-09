#include <iostream>
#include <vector>
using namespace std;

int n, cnt, m;
vector <int> v[110];
int a, b;
int gr[110][110];
int main(){
    
    scanf("%d%d", &n, &m);
    
    for(int i=0; i<m; i++){
        cin>>a>>b;
        a--; b--;
        gr[a][b] = 1;
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cout<<gr[i][j]<<" ";
        cout<<endl;
    }
    
    return 0;
}
