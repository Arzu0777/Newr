#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;

    node(int data){
        this -> data = data;
        this -> left = NULL;
        this -> right = NULL;
    }
};    
node* buildtree(node* root){
    cout << "Enter the data" << endl;
    int d;
    cin >> d;
    root = new node(d);
    if(d == -1){
        return NULL;
    }

    cout << "Enter the data for inserting in left" << endl;
    root -> left = buildtree(root -> left);
    cout << "Enter the data for inserting in right" << endl;
    root -> right = buildtree(root -> right);
    return root;
}
void LevelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        if(temp == NULL){
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout << temp -> data <<" " ;
            if(temp -> left){
                q.push(temp -> left);
            }
            if(temp -> right){
                q.push(temp -> right);
            }
        }
        
    }
    cout << endl << endl;
}    
void ReverseLevelOrderTraversal(node* root){
    queue<node*> q;
    stack<node*> s;
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        s.push(temp);
        if(temp -> left){
            q.push(temp -> left);
        }
        if(temp -> right){
            q.push(temp -> right);
        }
        
    }
    while(!s.empty()){
        node* temp = s.top();
        cout << temp -> data <<" " ;
        s.pop();
    }
}    
int main(){
    node* root = NULL;
    root = buildtree(root);
    ReverseLevelOrderTraversal(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 -1
    return 0;
}