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
Node* getmid(Node* &head){
    Node* slow = head;
    Node* fast = head -> next;
    if(head == NULL || head -> next == NULL){
        return head;
    }
    while(fast != NULL){
        fast = fast -> next;
        slow = slow -> next;
        if(fast != NULL){
            fast = fast -> next;
        }
    }
    return slow;
}
Node* reverse(Node* &node){
    if(node == NULL || node -> next == NULL){
        return node;
    }
    Node* prev = NULL;
    Node* temp = node;
    Node* forw = NULL;
    while(temp != NULL){
        forw = temp -> next;
        temp -> next = prev;
        prev = temp;
        temp = forw;
    } 
    return prev;
}
bool palindrome(Node* &head){
    if(head == NULL || head -> next == NULL){
        return true;
    }
    Node* start = head;
    Node* mid = getmid(head);
    Node* midstart = reverse(mid -> next);
    while(start != mid && midstart == NULL){
        if( start -> data == midstart -> data){
            start = start -> next;
            midstart = midstart -> next;
        }
        else{
            return false;
        }
    }
    return true;
}
int main(){
    Node* newNode = new Node(10);
    Node* head = newNode;
    Node* tail = newNode;   
    cout << head->data << endl;
    inserthead(head , 9);
    inserthead(head , 8);
    print(head);
    inserttail(tail, 8);
    inserttail(tail, 9);
    inserttail(tail, 10);
    print(head);
    cout <<"head : " << head -> data << " "<< "head pointer : "<< head << endl;
    cout <<"tail : " << tail ->data <<" "<<" tail point to : "<< tail -> next << endl;
    palindrome(head);
    Node* ans = getmid(head);
    cout << "midle element is : " <<  ans -> data << endl;
    bool answer = palindrome(head);
    if(answer){
        cout << "It is a palindrome number " << endl;
    }
    else{
        cout << "It is not a palindrome number " << endl;
    }
}