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
void rev(Node* &head, Node* curr, Node* prev){
    if(curr == NULL){
        head = prev;
        return ;
    }
    rev(head, curr -> next, curr);  
    curr -> next = prev; 
}
int main(){
    Node* newNode = new Node(10);
    Node* head = newNode;
    Node* tail = newNode;
    inserthead(head , 9);
    inserthead(head , 8);
    inserthead(head , 7);
    inserthead(head , 6);
    print(head);
    Node* prev = NULL;
    Node* curr = head;
    rev(head, curr, prev);
    print(head);
}