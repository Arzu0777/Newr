#include <bits/stdc++.h>
using namespace std;
int ans=0;
int fib(int n){
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }       
        ans= fib(n-1)+fib(n-2);
        return ans;
    }
int main(){
    int n=7;
    fib(n);
    cout << fib(n) << endl;
}