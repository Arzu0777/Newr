#include <bits/stdc++.h>
using namespace std;
int sum(int n , int arr[]){
    if(n < 0){
        return 0;
    }
    if(n == 0){
        return arr[0];

    }
        int include = sum( n-2, arr) + arr[n];
        int exclude = sum( n-1, arr);
          
    return max(include, exclude);
    
}
int main(){
    int arr[] = {1,2,3,4,5,6};
    int ans = sum(5,arr);
    cout << "Maximum sum :" << endl;
    cout << ans << endl; 
}