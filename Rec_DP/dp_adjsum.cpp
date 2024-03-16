#include <bits/stdc++.h>
using namespace std;
int sum(int i, int n, int arr[],int dp[]){
    if(i > n-1){
        return 0;
    }
    if(i == n-1){
        return arr[n-1];

    }
    if(dp[i]!= -1){
        return dp[i];
    }
        int include = sum(i+2, n, arr, dp) + arr[i];
        int exclude = sum(i+1, n, arr, dp);
        dp[i] = max(include, exclude);     
    return dp[i];
    
}
int main(){
    int arr[] = {1,2,3,4,5,6,7};
    int dp[] = {-1,-1,-1,-1,-1,-1,-1};
    int ans = sum(0,7,arr,dp);
    cout << "Maximum sum :" << endl;
    cout << ans << endl; 
}