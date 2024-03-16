#include <bits/stdc++.h>
using namespace std;
void print(stack<int> s){
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}
void delmid(stack<int> &s, int count,int size){
    if(count == size/2){
        s.pop();
        return;
    }
    int num = s.top();
    s.pop();

    delmid(s, count + 1, size);

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
    delmid(s, 0, size);
    print(s);
}