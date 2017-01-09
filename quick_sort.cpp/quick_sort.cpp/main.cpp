#include <iostream>
using namespace std;

int a[10000];

void quicks(int L, int R){

    int i = L;
    int j = R;
    int m = (a[(L+R)/2]);
    
    while(i<j){
    
        while (a[i] < m) i++;
        while (a[j] > m) j--;
        
        if(i<=j){
        
            swap(a[i], a[j]);
            i++;
            j--;
        }
        
    }
    if(L<j) quicks(L, j);
    if(R>i) quicks(i, R);
    
  
}

int main(){
    
    int n;
    cin>>n;
    
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    quicks(0, n-1);
    
    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";

    return 0;
}
