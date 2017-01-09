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
int n, a[100100];
int t[4*100100];

void build(int v, int tl, int tr){
    
    if(tl==tr)
        t[v] = a[tl];
    else{
        int mid = (tl+tr)>>1;
        build(2*v, tl, mid);
        build(2*v+1, mid+1, tr);
        t[v] = t[2*v]+t[2*v+1];
    }
    
}

void upd(int v, int tl, int tr, int pos, int val){
    
    if(tl==tr)
        t[v] = val;
    else{
        int mid = (tl+tr)>>1;
        if(pos<mid)
            upd(2*v, tl, mid, pos, val);
        else
            upd(2*v+1, mid+1, tr, pos, val);
        
        t[v] = t[2*v] + t[2*v+1];
    }
}

int getsum(int v, int tl, int tr, int l, int r){
    
    if(tl>r || l>tr)
        return 0;
    if(tl>=l && r>=tr)
        return t[v];
    int mid = (tl+tr)>>1;
    int ans1 = getsum(2*v, tl, mid, l, r);
    int ans2 = getsum(2*v+1, mid+1, tr, l, r);
    return ans1+ans2;

}


int main(){
    
    scanf("%d", &n);
    
    for(int i=0; i<n; i++)
        scanf("%d", a+i);
    
    
    build(1, 0, n-1);
    
    int q;
    scanf("%d", &q);
    
    for(int i=0; i<q; i++){
        int l, r;
        
        scanf("%d%d", &l,&r);
        l--;r--;
        printf("%d\n", getsum(1, 0, n-1,l, r));
    }
    
    
    return 0;
}












