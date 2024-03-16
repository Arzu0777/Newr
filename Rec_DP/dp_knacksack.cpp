#include <bits/stdc++.h>
using namespace std;
int knackSack(int W ,int wt[],int val[],int n){
   
    if(W < wt[n]){
        return 0;
    }
    if( n == 0){
        if(W > wt[0]){
            return val[0];
        }
        else{
            return 0;
        }
    }
    int incl = knackSack(W - wt[n] , wt, val, n - 1) + val[n];
    int excl = knackSack(W , wt, val, n - 1) + 0;
    return max(incl,excl);
}
int knackSackdp(int W ,int wt[],int val[],int n , vector<vector<int>> &dp){
   
    if(W < wt[n]){
        return 0;
    }
    if( n == 0){
        if(W > wt[0]){
            return val[0];
        }
        else{
            return 0;
        }
    }
    if(dp[n][W]!= -1){
        return dp[n][W];
    }
    int incl = 0;
    if( W > wt[n]){
         incl = knackSackdp(W - wt[n] , wt, val, n - 1, dp) + val[n];
    }   
    int excl = knackSackdp(W , wt, val, n - 1, dp) + 0;
    dp[n][W] = max(incl,excl);
    return dp[n][W];
}
int knackSackTb(int W ,int wt[],int val[],int n){
    vector<vector<int>> dp(n + 1 , vector<int> (W + 1, -1));
    for(int k = wt[0]; k <= W; k++){
        if(W > wt[0]){
            dp[0][W] = val[0];
        }
        else{
            dp[0][W] = 0;
        }
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <=W; j++){
            int incl = 0;
            if(wt[i] <= W){
                 incl = dp[i - 1][j - wt[i]] + val[i]; 
            }
            int excl = dp[i - 1][j];
            dp[i][j] = max(incl,excl);
        }
    }
    
    return dp[n][W];
}
int main(){
    int val[] = {1,2,3};
    int wt[] = {4,5,1};
    int W = 4;
    int n = 3;
    vector<vector<int>> dp(n + 1, vector<int> (W + 1, -1));
    cout << "Maximum value :" << endl;
    cout << knackSack(W , wt, val, n - 1) << endl;
    cout << knackSackdp(W , wt, val, n - 1, dp) << endl;
    cout << knackSackTb(W , wt, val, n - 1) << endl;
}