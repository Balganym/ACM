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

int a[100100];
int d[4*100100];
int n;

void build(int v,int tl, int tr){
    
    if(tl==tr)
        d[v] = a[tl];
    else{
        int m = (tl+tr)>>1;
        build(2*v,tl,m);
        build(2*v+1, m+1, tr);
        d[v] = d[v*2]+d[v*2+1];
    }
}

int get(int v, int tl, int tr, int l, int r){
    
    if(l>tr || r < tl) return 0;
    if(l<=tl && r>=tr) return d[v];
    int m = (tl+tr)>>1;
    int sum1 = get(2*v,tl, m, l,r);
    int sum2 = get(2*v+1, m+1, tr, l, r);
    return sum1+sum2;

}

void upd(int v, int tl, int tr, int pos, int val){
    
    if(tl == tr)
        d[v] = val;
    else{
        int m = (tl+tr)>>1;
        if(pos<m)
            upd(v<<1, tl, m, pos, val);
        else
            upd((v<<1)+1, m+1, tr, pos, val);
        
        d[v] = d[v<<1] + d[(v<<1)+1];
    }
    
    
}

int main(){
    
    scanf("%d", &n);
    
    F(i, n) scanf("%d", a+i);

    build(1, 0, n-1);
    
    int q;
    scanf("%d", &q);
    F(i, q){
        int l, r;
        scanf("%d%d", &l,&r);
        l--; r--;
        int o = get(1, 0, n-1, l, r);
        printf("%d\n", o);
    }
    
    scanf("%d", &q);
    
    F(i, q){
        int p, v;
        scanf("%d%d", &p,&v);
        p--;
        upd(1, 0, n-1, p, v);
    }
    
    scanf("%d", &q);
    printf("new\n");
    F(i, q){
        int l, r;
        scanf("%d%d", &l,&r);
        l--; r--;
        int o = get(1, 0, n-1, l, r);
        printf("%d\n", o);
    }
    
    
      return 0;
}
