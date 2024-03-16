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
    cout << temp -> data << " ";
    temp = temp -> next;
    while(temp != NULL){
        if(temp != head){
            cout <<temp -> data << " ";
            temp = temp ->next;
        }
        else{
            cout << "--> This is a cyclic linked list."<< endl;
            break;
        }   
    }
    cout << endl;
}
bool detectLoop(Node* head){
    if(head == NULL){
        return false;
    }
    Node* temp = head;
    map<Node*, bool> visited;
    while(temp!= NULL){
        if(visited[temp] == true){
            cout << "Present on elment : "<< temp -> data << endl;
            return true;
        }
        visited[temp] = true;
        temp = temp -> next;
    }
    return false; 
}
int main(){
    Node* newNode = new Node(10);
    Node* head = newNode;
    Node* tail = newNode;   
    cout << head->data << endl;
    inserthead(head , 9);
    print(head);
    inserttail(tail, 5);
    inserttail(tail, 6);
    inserttail(tail, 7);
    tail -> next = head ;
    print(head);
    cout <<"head : " << head -> data << ",   "<< "head pointer : "<< head << endl;
    cout <<"tail : " << tail ->data <<",   "<<" tail point to : "<< tail -> next << endl;
    bool ans = detectLoop(head);
    if(ans){
        cout << "Loop is present "<< endl;
    }
    else{
        cout << "Loop is not present"<< endl;
    }
}