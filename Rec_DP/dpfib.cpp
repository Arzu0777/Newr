#include <bits/stdc++.h>
using namespace std;
int fib(int n, int dpar[]){
         if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }  
        if( dpar[n]!= -1){
            return dpar[n];
        }     
        dpar[n] = fib(n-1, dpar)+fib(n-2, dpar);
        return dpar[n];
    }
int main(){
    int n;
    cout << "Enter number:" << endl;
    cin >> n ;
    int dpar[n+1];
    for(int i =0 ; i <=n; i++){
        dpar[i] = -1;
    }
    fib(n, dpar);
    cout << fib(n, dpar) << endl;
}