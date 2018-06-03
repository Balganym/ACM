#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
typedef long long ll;
using namespace std;
ll n, a[1010], q, l, r;
ll two[1010], dp[13][1010], ex[18];

void precalc(){
    
    two[0] = -1;
    for(int i=1; i<1010; i++)two[i] = 1+two[i/2];
    
    ex[0] = 1;
    for(int i=1; i<18; i++) ex[i] = ex[i-1]*2;
    
    for(int i=0; i<n; i++) dp[0][i] = a[i];
    
    for(int lvl=1; ex[lvl]<=n; lvl++){
        for(int i=0; i+ex[lvl]<=n; i++){
            dp[lvl][i] = max(dp[lvl-1][i], dp[lvl-1][i+ex[lvl-1]]);
        }
    }
}

ll getmax(ll l, ll r){
    
    if(l>r) return -1e9;
    ll lvl = two[r-l+1];
    ll ans1 = dp[lvl][l];
    ll ans2 = dp[lvl][r-ex[lvl]+1];
    return max(ans1, ans2);
}

int main(){
    
    scanf("%lld", &n);
    
    for(int i=0; i<n; i++)
        scanf("%lld", a+i);
    
    precalc();
    
    scanf("%lld", &q);
    for(int i=0; i<q; i++){
        scanf("%lld%lld",&l, &r);
        l--; r--;
        printf("%lld\n", getmax(l, r));
    }
    
}
