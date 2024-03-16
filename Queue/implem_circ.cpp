#include <bits/stdc++.h>
using namespace std;
class CircularQueue{
    int *arr;
    int front;
    int rear;
    int size;

    public:
    CircularQueue(int n){
        front = rear = -1;
        size = n;
        arr = new int[size];
    }

    bool enqueue(int value){
        if((front == 0 && rear == size -1) || (rear = (front -1)% (size - 1))){
            cout << "Queue is full"<< endl;
            return false;
        }
        else if(front == -1){   // First Element of queue
            front = rear = 0;
            arr[rear] = value;
        }
        else if(rear == size -1 && front != 0){
            rear = 0;
            arr[rear] = value;
        }
        else{
            rear++ ;
            arr[rear] = value;
        }
        return true;
    }

    int dequeue(){
        if(front == -1){
            cout << "Queue is empty" << endl;
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;
        if(front == rear){   // First Element of Queue
            front = rear = -1;
        }
        else if(front == size -1){     // Last element
            front = 0;   
        }  
        else{
            front++;
        }
        return ans;
    }
};