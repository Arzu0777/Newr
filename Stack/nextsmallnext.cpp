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
    int ques[] ={2,3,1};
    stack<int> s;
    s.push(-1);
    int ans[] = {-1,-1,-1};
    int n = 3;
    for(int i = n-1; i >= 0; i--){
        if(!s.empty()){
            if(ques[i] >= s.top()){
                ans[i] = s.top();
                s.push(ques[i]);
            }
            else{
               s.pop();
            }
        }
    }    
    cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;
    return 0;
}