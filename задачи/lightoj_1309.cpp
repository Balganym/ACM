#include <functional>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <sstream>
#include <numeric>
#include <string>
#include <vector>
#include <cstdio>
#include <bitset>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef pair<long long, long long> pll;

#define fname ""
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define sz(a) (int)a.size()
#define all(v) v.begin(), v.end()
#define forit(it,v) for(__typeof(v.begin()) it = v.begin(); it != v.end(); ++it)

const int inf = (int)1e9;
const ll INF = (ll)1e18;
const double eps = 1e-9;
const double pi = acos(-1.0);
const int N = 100100;

int T;

typedef struct { int a, b; char op; } Number;

bool isop(char ch) {
    return (ch == '+' || ch == '-' || ch == '*');
}

int priority(char ch) {
    if(ch == '*') return 2;
    return 1;
}

Number add(Number x, Number y) {
    return (Number){x.a+y.a, x.b+y.b, 0};
}

Number sub(Number x, Number y) {
    return (Number){x.a-y.a, x.b-y.b, 0};
}

Number mul(Number &x, Number &y) {
    if(!x.a) return (Number){y.a*x.b, y.b*x.b, 0};
    return (Number){x.a*y.b, x.b*y.b, 0};
}

Number getVal(string exp) {
    Number tmp, ta, tb, tc;
    stack <char> OP;
    stack <Number> EXP;
    vector<Number> v;
    for(int i = 0; i < sz(exp); i++) {
        if(exp[i] == '(') OP.push('(');
        else if(exp[i] == ')') {
            while(!OP.empty() && OP.top() != '(') {
                tmp = (Number){0, 0, OP.top()};
                v.push_back(tmp);
                OP.pop();
            }
            if(!OP.empty()) OP.pop();
        }
        else if(isop(exp[i])) {
            while(!OP.empty() && isop(OP.top()) && priority(OP.top()) >= priority(exp[i])) {
                tmp = (Number){0, 0, OP.top()};
                v.push_back(tmp);
                OP.pop();
            }
            OP.push(exp[i]);
        }
        else if(exp[i]=='x') {
            tmp = (Number){1, 0, 0};
            v.push_back(tmp);
        }
        else {
            int j, n;
            for(n = 0, j = i; j < sz(exp) && isdigit(exp[j]); j++) {
                n = n * 10 + exp[j] - '0';
            }
            tmp = (Number){0, n, 0};
            v.push_back(tmp);
            i = j-1;
        }
    }
    while(!OP.empty()) {
        tmp = (Number){0, 0, OP.top()};
        v.push_back(tmp);
        OP.pop();
    }
    int n = v.size();
    for(int i = 0; i < n; i++) {
        if(v[i].op) {
            tb = EXP.top(); EXP.pop();
            ta = EXP.top(); EXP.pop();
            switch(v[i].op) {
                case '+':
                    EXP.push(add(ta, tb));
                    break;
                case '-':
                    EXP.push(sub(ta, tb));
                    break;
                case '*':
                    EXP.push(mul(ta, tb));
                    break;
            }
        }
        else EXP.push(v[i]);
    }
    return EXP.top();
}

int gcd(int a, int b) {
    if(!b) return a;
    return gcd(b, a % b);
}

int main() {
    int T, cs, a, b, g;
    
    cin >> T;
    for(cs = 1; cs <= T; cs++) {
        string exp1, exp2, s;
        cin >> s;
        Number leq, req, res;
        
        int i;
        for(i = 0; i < sz(s); ++i){
            if(s[i] == '=') break;
            exp1 += s[i];
        }
        exp2 = s.substr(i+1, sz(s)-1);
        
        leq = getVal(exp1);
        req = getVal(exp2);
        res = sub(leq, req);
        
        printf("Case %d: ", cs);
        if(!res.a && !res.b) printf("infinitely many solutions\n");
        else if(!res.a && res.b) printf("no solution\n");
        else {
            a = res.a, b = -res.b;
            g = gcd(abs(a), abs(b));
            a /= g, b /= g;
            if(a < 0) a *= -1, b *= -1;
            if(a == 1) printf("%d\n", b);
            else printf("%d/%d\n", b, a);
        }
    }
    
    return 0;
}
