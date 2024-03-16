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
Node* sort(Node* first, Node* sec){
    if(first -> next == NULL){
        first -> next = sec;
        return first;
    }
    Node* curr = first;
    Node* forw = first -> next;
    Node* curr2 = sec;
    while(forw != NULL && curr2 != NULL){
        if((curr2 -> data >= curr -> data)&&(curr2 -> data <= forw -> data)){
        Node* forw2 = curr2 -> next;
        curr -> next = curr2;
        curr2 -> next = forw;
        curr = curr2;
        curr2 = forw2;
        }
         else{
            curr = forw;
            forw = forw -> next;
            if(forw == NULL){
              curr -> next = curr2;
              return first;
            }
        }
    }
    return first;
}
int main(){
    Node* newNode1 = new Node(10);
    Node* head1 = newNode1;
    Node* tail1 = newNode1;   
    cout << head1 -> data << endl;
    inserthead(head1 , 7);
    print(head1);
    inserthead(head1, 5);
    print(head1);
    cout <<"head1 : " << head1 -> data << " "<< "head1 pointer : "<< head1 << endl;
    cout <<"tail1 : " << tail1 ->data <<" "<<" tail1 point to : "<< tail1 -> next << endl;
    Node* newNode2 = new Node(11);
    Node* head2 = newNode2;
    Node* tail2 = newNode2;   
    cout << head2 -> data << endl;
    inserthead(head2 , 9);
    print(head2);
    inserthead(head2, 6);
    print(head2);
    cout <<"head2 : " << head2 -> data << " "<< "head2 pointer : "<< head2 << endl;
    cout <<"tail2 : " << tail2 ->data <<" "<<" tail2 point to : "<< tail2 -> next << endl;

    Node* ans = NULL;
    if(head1 -> data > head2 -> data){
        ans = sort(head2, head1);
    }
    else{
        ans = sort(head1, head2);
    }
    print(ans);
}