#include <bits/stdc++.h>
using namespace std;
void reverse(queue<int> &q){
    stack<int> s;
    int n = q.size();
    for(int i = 0; i < n; i++){
        int top = q.front();
        s.push(top);
        q.pop();
    }
    while(!s.empty()){
        int top = s.top();
        q.push(top);
        s.pop();
    }
    queue<int> temp = q;
    while(!temp.empty()){
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;
}
int main(){
    queue<int> q;
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    cout << q.front() << endl;
    cout << q.back() << endl;
    reverse(q);
}