#include <bits/stdc++.h>
using namespace std;
int sum(int i, int n, int arr[], vector<int> &dp){
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
int tabsum1(int n, int arr[]){
    
    vector<int> dp(7, 0);
    dp[n-1] = arr[n-1];
    dp[n+1] = 0 ;
    for(int i = n-2 ; i >=0 ; i--){
        int include = dp[i+2] + arr[i];
        int exclude = dp[i+1] + 0;
        dp[i] = max(include, exclude);
    }
    return dp[0];
}
int tabsum2(int n, int arr[]){
    
    vector<int> dp(7, 0);
    dp[0] = arr[0];
    dp[-1] = 0 ;
    for(int i = 1 ; i < n ; i++){
        int include = dp[i-2] + arr[i];
        int exclude = dp[i-1] + 0;
        dp[i] = max(include, exclude);
    }
    return dp[n-1];
}
int space(int n, int arr[]){
    int prev1 = arr[0];
    int prev2 = 0;
    for(int i = 1; i < n; i++){
        int include = prev2 + arr[i];
        int exclude = prev1;
        int curr = max(include, exclude);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
int main(){
    int arr[] = {1,2,3,4,5,6,7};
    int ans = tabsum1(7,arr);
    cout << "Maximum sum :" << endl;
    cout << ans << " " << arr[0] << endl; 
}