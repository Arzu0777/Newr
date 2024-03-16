#include<iostream>
#include<stack>
using namespace std;
void PrintStack(stack<int> s)
{
    // If stack is empty then return
    if (s.empty())
        return ;
     
 
    int x = s.top();
 
    // Pop the top element of the stack
    s.pop();
    // Recursively call the function PrintStack
    PrintStack(s);
 
    // Print the stack element starting
    // from the bottom
     cout << x << " ";
 
    // Push the same element onto the stack
    // to preserve the order
    s.push(x);
}
void solve(stack<int>&inputStack, int count, int size) {
    //base case
    if(count == size/2) {
        inputStack.pop();
        PrintStack(inputStack);
        cout << "-" << count << endl;
        return ;
    }
     int num = inputStack.top();
    inputStack.pop();
    PrintStack(inputStack);
    cout << "-" << count << endl;
	//RECURSIVE CALL
    solve(inputStack, count+1, size);
    PrintStack(inputStack);
    cout << "-" << count << endl;

    inputStack.push(num);

}

int main(){
    
    stack<int> inputStack;
    inputStack.push(1);
    inputStack.push(2);
    inputStack.push(3);
    inputStack.push(4);
    inputStack.push(5);
    int N=5;
   
    
  	int count = 0;
    solve(inputStack, count, N);
    cout << endl;
     PrintStack(inputStack);
    cout << "-" << count << endl;
   

}