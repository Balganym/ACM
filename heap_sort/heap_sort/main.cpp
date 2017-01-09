#include <iostream>

using namespace std;

int maxx, k;
int a[10000];

void heap_sort(int i, int n){
    
    int l = i; //на которую нужно менять
    maxx = a[i];
    
    if(2*i + 1 < n && a[2*i + 1] > maxx){
        
        maxx = a[2*i + 1];
        l = 2*i+1;
    }
    
    if(2*i + 2 < n && a[2*i + 2] > maxx){
        maxx = a[2*i+2];
        l = 2*i+2;
    }
    
    if(l!=i){
        swap(a[i],a[l]);
        heap_sort(l, n);
    }
    
}

void heapify(int n){
    
    for(int i=(n-1)/2; i>=0; i--)
        heap_sort(i, n);
    
    for(int i=n-1; i>=0; i--){
        swap(a[0], a[i]);
        heap_sort(0, i);
    }

}

int main() {
    int n;
    cin>>n;
    
    for(int i=0; i<n; i++)
        cin>>a[i];
    
    heapify(n);
    
    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
    

    return 0;
}
