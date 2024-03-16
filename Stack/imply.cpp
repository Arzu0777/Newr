#include <bits/stdc++.h>
using namespace std;
void print(stack<int> s){
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}
int main(){
    stack<int> s;
    s.push(8);
    s.push(9);
    s.push(6);
    s.push(5);
    s.push(7);
    int size = s.size(); 
    cout << size << endl;
    print(s);
    if(s.top() > 6){
        cout << "Greater " << endl;
    }
}