#include<iostream>
using namespace std;
int fact(int n){
    if(n == 1){
        return 1;
    }

    return n * fact(n-1);
}
int main(){
    int c;
    cout << "Enter number:"<< endl;
    cin >> c;
    cout << fact(c)<< endl;
    
    return 0;
}