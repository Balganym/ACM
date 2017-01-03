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

string s, t;
char ch[50100], tch[501000];
ll h[50100], pp[50100], th, h1;

int main(){
    
    int p = 53;
    
    scanf("%s%s", ch, tch);
    t = ch;
    s = tch;
    
    vector<long long> pp(max (s.length(), t.length()));
    pp[0] = 1;
    for (size_t i=1; i<pp.size(); ++i)
        pp[i] = pp[i-1] * p;
    
    
    vector<long long> h (t.length());
    for (size_t i=0; i<t.length(); ++i)
    {
        h[i] = (t[i] - 'a' + 1) * pp[i];
        if (i)  h[i] += h[i-1];
    }
    
    long long h_s = 0;
    for (size_t i=0; i<s.length(); ++i)
        h_s += (s[i] - 'a' + 1) * pp[i];
    
    for (size_t i = 0; i + s.length() - 1 < t.length(); ++i)
    {
        long long cur_h = h[i+s.length()-1];
        if (i)  cur_h -= h[i-1];
        
        
        if (cur_h == h_s * pp[i])
            cout << i << " ";
    }
    
    
    
    return 0;
}
