#include <bits/stdc++.h>
using namespace std;
void print(stack<int> s){
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}
void putnum(stack<int> &s, int num){
    if(s.empty() || s.top() >= num){
        s.push(num);
        return;
    }
    int no = s.top();
    s.pop();

    putnum(s, num);

    s.push(no);
}
void sort(stack<int> &s){
    if(s.empty()){
        return;
    }
    int num = s.top();
    s.pop();

    sort(s);

    putnum(s, num);
}
int main(){
    stack<int> s;
    s.push(8);
    s.push(6);
    s.push(9);
    s.push(5);
    s.push(7);
    int size = s.size(); 
    cout << size << endl;
    print(s);
    sort(s);
    print(s);
}