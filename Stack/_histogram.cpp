#include <bits/stdc++.h>
using namespace std;
void print(stack<int> s){
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}
vector<int> prevsmall(vector<int> ques , int n){
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for(int i = 0; i < n ; i++){
        while(s.top()!= -1 && ques[s.top()] >=ques[i]){
            s.pop();
        }
        ans[i]= s.top();
        s.push(i);
    }
    return ans;
}
vector<int> nextsmall(vector<int> ques , int n){
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for(int i = n-1; i >= 0; i--){
        while(s.top() != -1 && ques[s.top()] >= ques[i]){
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }    
    return ans;
}
void printvec(vector<int> v){
    int size = v.size();
    for(int i = 0; i < size; i ++){
        cout << v[i] << " ";
    }
    cout << endl;
}
int main(){
    vector<int> height = {2,1,5,6,2,3};
    int n = height.size();
    vector<int> next(n);
    next = nextsmall(height, n);
    printvec(next);

    vector<int> prev(n);
    prev = prevsmall(height, n);
    printvec(prev);

    int area = INT_MIN;
    for(int i = 0; i < n; i++){
        int l = height[i];

        if(next[i] == -1){
            next[i] = n;
        }
        int b = next[i] - prev[i] - 1;
        int newarea = l*b;
        area = max(area, newarea);
    }
    cout <<"Maximum area of Histogram is : " <<area << endl;

    return 0;
}