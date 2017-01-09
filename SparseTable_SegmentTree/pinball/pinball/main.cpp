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

int n, it;
bool l, r;
int cntl, cntr, cnt;
string s;
char ch[200200];


int main(){
    
    scanf("%d", &n);
    scanf("%s", ch);
    s = ch;
    
    if(s[0] == '<'){
        int i=0;
        while(s[i]!='>'){
            if(i==n)
                break;
            cnt++;
            i++;
        }
        
        if(i<n){
            int j = n-1;
            while(s[j]!='<'){
                if(j==0)
                    break;
                cnt++;
                j--;
            }
        }
    }
    else{
        int j=n-1;
        while(j>=0){
            if(s[j] == '<'){
                break;
            }
            cnt++;
            j--;
        }
    }
    
    
    cout<<cnt;
    return 0;
}

