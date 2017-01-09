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

char ch[30];
string s;
bool ok;
map <char, int> mpp;
int cnt;
int main(){
    
    scanf("%s", ch);
    s = ch;
    char cur;
    cur = ' ';
    for(int i=0; i<27; i++){
        mpp[s[i]]++;
        if(mpp[s[i]] == 2)
            cur = s[i];
    }
    
    for(int i=0; i<27; i++){
        if(s[i] == cur)
            ok = true;
        if(ok){
            cnt++;
        }
        if(ok && s[i]==cur)
            break;
    }
    
    if(cnt<13){
        cout<<"Impossible";
        return 0;
    }
    
    for(int i=0; i<27; i++){
        
        
    }

    // ABCDEFGHIJKLMNOPQRSGTUVWXYZ
    //
    //  YXWVUTGHIJKLM
    //  ZABCDEFSRQPON
    
    
    
    return 0;
}
