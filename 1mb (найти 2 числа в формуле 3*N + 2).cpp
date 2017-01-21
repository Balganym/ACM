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
#define sz(a) a.size()
#define pb push_back
#define fo(i,k,n) for(size_t i=k; (int)i<n; ++i)
#define all(v) sort(v.begin(), v.end())
#define pii pair<int, int>
#define it ::iterator
#define forit(it, st) for(it = st.begin(); it!=st.end(); it++)
//int const inf = 1e9;

int t, n;
int a[32], cur[32], c[32], d[32];
int b[32][32];

void calc(int x){
    int cnt = 0;
    while(x){
        if(x % 2 == 0)
            a[cnt] += 0;
        else
            a[cnt] += 1;
        a[cnt] %= 3;
        x /= 2;
        cnt++;
    }
}

void de(int x){
    for(int i = 0; i < 32; ++i)
        cur[i] = 0;
    int cnt = 0;
    while(x){
        if(x % 2 == 0)
            cur[cnt] += 0;
        else
            cur[cnt] += 1;
        x /= 2;
        cnt++;
    }
    for(int i = 0; i < 32; ++i){
        for(int j = i + 1; j < 32; ++j){
            if(cur[i] == cur[j] && cur[j] == 1){
                b[i][j]++;
                b[j][i]++;
            }
            b[i][j] %= 3;
            b[j][i] %= 3;
        }
    }
}

int main(){
    //    freopen("input.txt", "r", stdin);
    //    freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i = 0; i < 32; ++i){
            a[i] = 0;
            for(int j = 0; j < 32; ++j){
                b[i][j] = 0;
            }
        }
        for(int i = 0; i < n; ++i){
            int x;
            scanf("%d", &x);
            calc(x);
            de(x);
        }
        int ind = -1;
        bool ok = 1;
        for(int i = 0; i < 32; ++i){
            if(ok && a[i] == 1){
                c[i] = 1;
                d[i] = 0;
                ok = 0;
                ind = i;
            }else if(!ok && a[i] == 1){
                if(b[ind][i] == 1){
                    c[i] = 1;
                    d[i] = 0;
                }else{
                    c[i] = 0;
                    d[i] = 1;
                }
            }else if(a[i] == 2){
                c[i] = 1;
                d[i] = 1;
            }
        }
        int deg = 1, ans1 = 0, ans2 = 0;
        for(int i = 0; i < 32; ++i){
            ans1 += c[i] * deg;
            ans2 += d[i] * deg;
            deg *= 2;
        }
        printf("%d %d\n", ans1, ans2);
    }
    return 0;
}


