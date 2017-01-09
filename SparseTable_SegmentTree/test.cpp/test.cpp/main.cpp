#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <sstream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define ll long long
#define pii pair < int, int >
#define pll pair < long long, long long>
#define ull unsigned long long
#define y1 stupid_cmath
#define left stupid_left
#define right stupid_right
#define vi vector <int>
#define sz(a) (int)a.size()
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it++)
#define all(a) a.begin(), a.end()
#define sqr(x) ((x) * (x))

const int inf = (int)1e9;


int n, a[100100];
int dp[17][100100];
int two[100100];
int ex[20];

void precalc() {
    two[0] = -1;
    for (int i = 1; i < 100100; i++) {
        two[i] = 1 + two[i / 2];
    }
    ex[0] = 1;
    for (int i = 1; i < 20; i++) ex[i] = 2 * ex[i - 1];
    for (int i = 0; i < n; i++) dp[0][i] = a[i];
    for (int lvl = 1; ex[lvl] <= n; lvl++) {
        for (int i = 0; i + ex[lvl] <= n; i++) {
            dp[lvl][i] = min(dp[lvl - 1][i],
                             dp[lvl - 1][i + ex[lvl-1]]);
        }
    }
}

int getmin(int l, int r) {
    if (l > r) return inf;
    int lvl = two[r - l + 1];
    int ans1 = dp[lvl][l];
    int ans2 = dp[lvl][r - (1 << lvl) + 1];
    return min(ans1, ans2);
}

int main(){
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
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
