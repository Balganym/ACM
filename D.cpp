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

int dp[35][35][55];
int nn, mm, kk, t;

int main(){
    
    for(int n=1; n<=30; n++){
        for(int m=1; m<=30; m++){
            for(int k=0; k<=50; k++){
                int &ans = dp[n][m][k];
                ans = inf;
                if(k == 0 || k == n*m)
                    ans = 0;
                else{
                    for(int i=1; i<m; i++){
                        for(int k1 = 0; k1<=k; k1++){
                            int k2 = k - k1;
                            ans = min(ans, n*n + dp[n][i][k1] + dp[n][m-i][k2]);
                        }
                    }
                    
                    for(int i=1; i<n; i++){
                        for(int k1 = 0; k1<=k; k1++){
                            int k2 = k - k1;
                            ans = min(ans, m*m + dp[i][m][k1] + dp[n-i][m][k2]);
                        }
                    }
                    
                }
            }
        }
    }
    
    scanf("%d", &t);
    
    while(t>0){
        
        scanf("%d%d%d", &nn,&mm, &kk);
        printf("%d\n", dp[nn][mm][kk]);
        t--;
    }
    
    return 0;
}
