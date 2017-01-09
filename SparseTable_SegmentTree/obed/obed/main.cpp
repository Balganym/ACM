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

ll n;
char ch;
int t[6] = {4, 5, 6, 3, 2, 1};

int main()
{
    
    cin >> n >> ch;
    n--;
    cout << (n/4)*16 + (n%2)*7 + t[ch-'a'] << endl;
    
}
