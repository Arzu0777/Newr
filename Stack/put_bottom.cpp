#include <bits/stdc++.h>
using namespace std;
void print(stack<int> s){
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}
void PutAtBottom(stack<int> &s, int x){
    if(s.empty()){
        s.push(x);
        return;
    }
    int num = s.top();
    s.pop();

    PutAtBottom(s, x);

    s.push(num);
}
int main(){
    stack<int> s;
    s.push(9);
    s.push(8);
    s.push(7);
    s.push(6);
    s.push(5);
    int size = s.size(); 
    cout << size << endl;
    print(s);
    PutAtBottom(s, 10);
    print(s);
}