#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};
void inserthead(Node* &head , int d){
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}
void inserttail(Node* &tail, int d){
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = temp;
}
void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout <<temp -> data << " ";
        temp = temp ->next;
    }
    cout << endl;
}
Node* revk(Node* &head, int k){
    if(head == NULL){
        return NULL;
    }
    Node* forw = NULL; 
    Node* curr = head;
    Node* prev = NULL; 
    int count = 0;
    while(curr!= NULL && count < k){
        forw = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forw;
        count ++;
    }
    if(forw!= NULL){
        head -> next = revk(forw, k);
    } 
    return prev;
}
int main(){
    Node* newNode = new Node(10);
    Node* head = newNode;
    Node* tail = newNode;
    inserthead(head , 9);
    inserthead(head , 8);
    inserthead(head , 7);
    inserthead(head , 6);
    inserthead(head , 5);
    print(head);
    int k = 2;
    Node* ans = revk(head, k);
    print(ans);
}    