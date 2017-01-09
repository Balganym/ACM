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
using namespace std;
ll two[100100], a[1010], n, ex[20], q, l, r;
ll dp[14][100100];

void precalc(){
    
    two[0] = -1;
    for(int i=1; i<1010; i++)
        two[i] = 1+two[i/2];
    
    ex[0]=1;
    for(int i=1; i<20; i++)
        ex[i] = ex[i-1] * 2;
    
    for(int i=0; i<n; ++i)
        dp[0][i] = a[i];
    
    for(int lvl=1; ex[lvl]<=n; lvl++){
        for(int i=0; i+ex[lvl]<=n; i++)
            dp[lvl][i] = min(dp[lvl-1][i], dp[lvl-1][i+ex[lvl-1]]);
    }
}

ll getmin(ll l, ll r){
    
    if(l>r) return 1e9;
    ll lvl = two[r-l+1];
    ll ans1 = dp[lvl][l];
    ll ans2 = dp[lvl][r-(ex[lvl])+1];
    return min(ans1, ans2);
    
}


int main(){
    
//    freopen("stupid_rmq.in", "r", stdin);
//    freopen("stupid_rmq.out", "w", stdout);
    scanf("%lld", &n);
    
    for(int i=0; i<n; i++){
        scanf("%lld", a+i);
    }
    
    precalc();
    
    int m, l, r;
    cin>>m;
    
    for(int i=0; i<m; i++){
        cin>>l>>r;
        l--, r--;
        cout<<getmin(l, r)<<endl;
    }
    
    
    return 0;
}
