#include<bits/stdc++.h>
using namespace std;
int sum(int a, int size, int i, int n, int k){
    if(i > n - 1){
        return 0;
    }
    if( k == 0){
        return  1;
    }
    if(k < 0){
        return -1;
    }
    int size1 = 1 + sum(a,size + 1,i + 1,n, k - a[i]);
    int size2 = 0 + sum(a,size,i + 1,n, k);
    
    return size = max(size1, size2);
}
int main(){
    int a[7] = (1,2,3,1,1,1,1);
    int k = 3;
    int n = 7;
    int ans = sum(a,0,0,n, k);
    cout << ans << endl;
}
