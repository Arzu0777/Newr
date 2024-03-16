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
int main(){
    int nsteps;
    cout << "Enter no of steps:" << endl;
    cin >> nsteps;
    int dp[nsteps + 1] ;
    for(int i = 0; i <=nsteps; i++){
        dp[i] = -1 ;
    }
    cout << climbing(nsteps,0 ,dp) << endl;
    return 0;
}
