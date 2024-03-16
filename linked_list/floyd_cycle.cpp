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
bool floydcycle(Node* head){
    Node* slow = head;
    Node* fast = head;
    if(head == NULL){
        return false;
    }
    while(fast != NULL){
        slow = slow -> next;
        fast = fast -> next;
        if(fast -> next!= NULL){
            fast = fast -> next;
        } 
        if(fast == slow){
            return true;
        }
    }
    return false;
}
Node* floyddetectioncycle(Node* head){
    Node* slow = head;
    Node* fast = head;
    if(head == NULL){
        return NULL;
    }
    while(fast != NULL){
        slow = slow -> next;
        fast = fast -> next;
        if(fast -> next!= NULL){
            fast = fast -> next;
        } 
        if(fast == slow){
            return slow;
        }
    }
    return NULL;
}
void element(Node* head){
    Node* slow = head;
    Node* fast = head;
    fast = floyddetectioncycle(head);
    while(slow != fast){
        slow = slow -> next;
        fast = fast -> next;
    } 
    cout << "Element is : "<< slow -> data << endl;
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
    tail -> next = head -> next;
    bool ans = floydcycle(head);
    if(ans){
        cout << "Loop is present "<< endl;
    }
    else{
        cout << "Loop is not present"<< endl;
    }
    element(head);
}