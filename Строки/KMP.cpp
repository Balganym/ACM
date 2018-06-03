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

string s;
char ch[50100];


int main(){
    
    scanf("%s", ch);
    s = ch;
    
    
    int n = (int)s.size();
    vector<int> p(n);
    p[0] = 0;
    
    for(int i=1; i<n; i++){
        int j = p[i-1];
        
        while(j>0 && s[j]!=s[i])
            j = p[j-1];
        
        if(s[i] == s[j]) j++;
        p[i] = j;
    }
    
    
    cout<<n - p[n-1];
    return 0;
}
