#include <bits/stdc++.h>
using namespace std;
int climbing(int nsteps,int in, int dp[]){
    if(in == nsteps){
        return 1;
    }
    if(in > nsteps){
        return 0;
    }
    if(dp[in]!= -1){
        return dp[in];
    }
    dp[in] = climbing(nsteps,in +1,dp) + climbing(nsteps,in +2,dp);
    return(dp[in]);
}
int climbing2(int nsteps,int in, int dp[]){
    dp[0] = 1;
    dp[1] = 1;
    for(int i =2; i<=nsteps; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[nsteps];
}
int climbing3(int nsteps,int in){
    int prev1 = 1;
    int prev2 = 1;
    int curr;
    for(int i =2; i<=nsteps; i++){
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}
int main(){
    int nsteps;
    cout << "Enter no of steps:" << endl;
    cin >> nsteps;
    int dp[nsteps + 1] ;
    for(int i = 0; i <=nsteps; i++){
        dp[i] = -1 ;
    }
    cout << climbing2(nsteps,0 ,dp) << endl;
    return 0;
}
