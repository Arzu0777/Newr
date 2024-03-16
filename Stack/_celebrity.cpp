#include <bits/stdc++.h>
using namespace std;
bool checkceleb(vector<vector<int>> &M, int ans, int n){
    int Zerocount = 0;
    // ROWS check , all zeros
    for(int i = 0; i < n; i++){
        if(M[ans][i] == 0){
            Zerocount++;
        }
    } 
    if(Zerocount != n){
        return false;
    }
    // COLUMN check , all 1 except himself
    Zerocount = 0;
    for(int i = 0; i < n; i++){
        if(M[i][ans] == 1){
            Zerocount++;
        }
    }
    if(Zerocount != n-1){
        return false;
    }
    return true;
}
int celebrity(vector<vector<int>> &M, int n){
    stack<int> s;
    for(int i = 0; i < n; i++){
        s.push(i);
    }
    while(s.size() > 1){
        int a = s.top();
        s.pop();

        int b = s.top();
        s.pop();
        // a knows b then he is not celebrity 
        if(M[a][b] == 1){
            s.push(b);
        }
        else{
            s.push(a);
        }
    }
    int ans = s.top();
    int c = checkceleb(M, ans, n);
    if(c){
        return ans;
    }
    else{
        return -1;
    }
}
int main(){
    vector<vector<int>> M(3, vector<int>(3, 0));
    int n = 3;
    cout << "Input 2-D matrix vector :" << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> M[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Celebrity is : " << endl;
    cout << celebrity(M, n) << endl;

    return 0;
}