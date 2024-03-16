#include<iostream>
using namespace std;
bool pald(string& a, int i, int j){   
    if(i>j){
        return true;
    }
    if(a[i] == a[j]){
        pald(a,i+1,j-1);
    }
    else{
        return false;
    }
}
int main(){
    string c = ("abba");
    int l = c.length() - 1;
    bool ans = pald(c,0,l);
    if(ans){
        cout << "It is a Palindrom number"<< endl;
    }
    else{
        cout << "It is not a Palindrom number"<< endl;
        
    }

    cout << c << endl; 
}