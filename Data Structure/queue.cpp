#include <iostream>
using namespace std;

class SimpleQueue {
    int front;
    int rear;
    int qu[5];

    public:

    /// @brief constructor to initialize the front and rear to -1
    SimpleQueue(){
        front=-1;
        rear=-1;
    }
    bool isEmpty(){
        return rear==-1 && front==-1 || front>rear;
    }
    void enqueue(int value){
        if (front==-1 && rear==-1)
        {
            front++;
            rear++;
            qu[rear]=value;
        }
        else if (rear>=4)
        {
            cout<<"Full Queue";
        }
        
        else{
            rear++;
            qu[rear]=value;
        }

        
    }


    void dequeue(){
        if (isEmpty())
        {
            cout<<"Empty Queue";
        }
        else{
            front ++;
        }
        
    }

    int peek(){
        if (isEmpty())
        {
            cout<<"Empty Queue";
            return -1;
        }
        
        return qu[front];
    }
bool isFull(){
    return rear==5-1; 
}


    void display(){       
         if (front==-1 && rear==-1)
        {
            cout<<"Empty Queue";
            
        }
        else{
            for (int i = 0; i <= rear; i++)
            {
                cout<<qu[i]<<" ";
            }
            cout<<"\n";
        }
    }


};


class CircularQueue{
    int front;
    int rear;
    int size=5;
    int qu[5];
    public:
    CircularQueue(){
        front=-1;
        rear=-1;
    }
    bool isEmpty(){
        return front==-1 && rear==-1;
    }

    bool isFull(){
        return front==0 && rear==size-1 || rear==front-1;
    }

    void enqueue(int value){
        if (isEmpty())
        {
            front=rear=0;
            qu[rear]=value;
        }
        else if (isFull())
        {
            cout<<"Full Queue";
        }
        else{
            if (rear==size-1)
            {
                rear=0;
                qu[rear]=value;
            }
            else{
                rear++;
                qu[rear]=value;
            }
            
        }
        
        
    }

    /// @brief deletes an element off of the queue
    void dequeue(){
        if (isEmpty())
        {
            cout<<"Empty Queue";
        }
        else {
            if (front==rear)
            {
                front=rear=-1;
            }
            
            else if (front==size-1 )
            {
                front=0;
            }
            else{
                front++;
            }
        }
    }

    void display(){
        if (isEmpty())
        {
        cout<<"Empty Queue";
        }
        else{

            if (rear==front-1)
            {
                for (int i = front; i < size ; i++)
                {
                    cout << qu[i] << " " ;
                }
                for (int i = 0; i <=rear ; i++)
                {
                    cout << qu[i] << " " ;
                }
            }
            else
            {

                for (int i = front; i <= rear ; i++)
                {
                    cout << qu[i] << " " ;
                }
            }

        }
    }

    int peek(){
        if (isEmpty())
        {
            cout<<"Empty Queue";
            return -1;
        }
        
        return qu[front];
    }

};

class Node{
    public:
    Node *head;
    Node *next; 
    Node *front;
    Node *rear;
    int data;
};

class QueueLinkedList{
    Node *front;
    Node *rear;
    Node *next;
    public:
    QueueLinkedList(){front=NULL;rear=NULL ;next=NULL;}

    bool isEmpty(){
        return front==NULL;
    }
    void enqueue(int value){
        Node *new_node = new Node;
        new_node->data = value;
        new_node->next =NULL; 
        if (isEmpty())
        {
            rear=front=new_node;
        }
        else{
            rear->next=new_node;
            rear=new_node;
        }
        
    }
    void dequeue(){
        if (isEmpty())
        {
            cout<<"Empty Queue"<<"\n";
        }
        else if (front == rear)
        {
            Node*ptr =front;
            front = rear = NULL;
            delete ptr;
        }
        else{
            Node *p ;
            p=front;
            front=front->next;
            delete p;

            
        }
        
    }
    void display(){
        if (isEmpty())
        {
            cout<<"Empty List";
        }
        else{
            Node *p;
            p=front;
            while (p!=NULL)
            {
                cout<< p->data << " ";
                p=p->next;
            }
            cout<<"\n";
            
        }
        
    }
    int peek(){
        if (isEmpty())
        {   
            cout<<"Empty Queue";
            return NULL;
        }
        
        return front->data;
    }
    
    
};
int main(){
    QueueLinkedList ql;
    ql.enqueue(4);
    ql.enqueue(4);
    ql.enqueue(4);
    ql.enqueue(4);
    ql.enqueue(4);
    ql.enqueue(5);
    ql.display();
    cout<<"\n";
    ql.dequeue();
    ql.dequeue();
    ql.dequeue();
    ql.dequeue();
    ql.dequeue();
    ql.dequeue();
    ql.dequeue();
    ql.dequeue();
    ql.dequeue();
    ql.display();
    return 0;
}