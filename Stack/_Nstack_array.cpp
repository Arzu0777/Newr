#include <bits/stdc++.h>
using namespace std;
class Nstack{
    private:
    int n;
    int s;
    int *arr;
    int *top;
    int *next;
    int freespot;

    public:
    Nstack(int N, int S){
        // S = size of array , N is no of array
        n = N;
        s = S;
        arr = new int[s];
        top = new int[n];
        next = new int[s];
        
        for(int i = 0; i < s; i++){
            top[i] = -1;
        }
        for(int i = 0; i < s; i++){
            next[i] = i + 1;
        }
        // last index value of next
        next[s - 1] = -1;
        // initialise freespot
        freespot = 0;

    }
    // Pushes "X" into Mth stack. Return true if it gets pushed into stack.
    bool push(int x, int m){
        if(freespot == -1){
            return false;
        }
        int index = freespot;
        freespot = next[index];  // If freespot = 0 , next[0] = 1
        arr[index] = x;
        next[index] = top[m - 1];
        top[m - 1] = index;
        return true;
    }  
    // Pop from Mth stack
    int pop(int m){
        if(top[m - 1] == -1){
            return -1;
        }
        // Writting reverse of above push
        int index = top[m - 1];
        top[m - 1] = next[index];
        next[index] = freespot;
        freespot = index;
        return arr[index];

    }
};
int main(){
    Nstack ans(4, 20);
    ans.push(5, 2);
    cout << ans.pop(1) << endl;
    cout << ans.pop(2) << endl;

    return 0;
}