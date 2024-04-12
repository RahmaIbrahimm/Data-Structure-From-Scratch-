#include <iostream>
using namespace std;

class SimpleQueue{
    int front;
    int rear;
    int qu[5];
    public:
    SimpleQueue(){front = rear = -1;}
    bool isEmpty(){return front == -1 && rear == -1 || front > rear; }
    bool isFull(){ return rear >= 5;}
    void enqueue(int value){
        if (isEmpty())
        {
            front = rear = 0;
            qu[rear] = value;
        }
        else{
            if (isFull())
            {
                cout<< "Overflow" <<endl;
            }
            else{
                rear++;
                qu[rear] = value;
            }
            
        }
    }
    void dequeue(){
        if (isEmpty())
        {
            cout<<"Empty queue."<<endl;
        }
        else{
            front++;
        }
        
    }
    int peek(){
        if (isEmpty())
        {
            cout<<"Empty queue"<<endl;
            return -1;
        }
        else{
            return qu[front];
        }
        
    }
    void display(){
        if (isEmpty())
        {
            cout<<"Empty queue."<<endl;
        }
        else{
            for (int i = front; i <=rear ; i++)
            {
                cout<<qu[i]<<" ";
            }
            cout<<endl;
        }
        
    }
};
class CircularQueue{
    int front;
    int rear;
    int qu[5];
    public:
    CircularQueue(){front = rear = -1;}
    bool isEmpty(){return front==-1 && rear == -1;}
    bool isFull(){return  front == rear + 1 || front == 0 && rear == 4; }

    void enqueue(int value){
        if (isFull())
        {
            cout<<"Full Queue."<<endl;
        }
        else if (isEmpty())
        {
            front = rear = 0;
            qu[rear]=value;
        }
        
        else{
            if (rear >= 4)
            {
                rear = 0;
                qu[rear] = value;
            }
            
            else{
                rear++;
                qu[rear] = value;
            }
        }
        
    }
    void dequeue(){
        if (isEmpty())
        {
            cout<<"Empty queue";
        }
        else{
            if (front==4)
            {
                front = 0;
            }
            else if (front == rear)
            {
            front = rear = -1;
            }
            
            else{
                front ++ ;
            }
            
        }
        
    }
    void display(){
        if (isEmpty())
        {
            cout<<"Empty queue."<<endl;
        }
        else{
            if (front==rear+1)
            {
                for (int i = front; i < 5; i++)
                {
                    cout<<qu[i]<<" ";
                }
                for (int i = 0; i <= rear; i++)
                {
                    cout<<qu[i]<<" ";
                }
                cout<<endl;
            }
            else{
                for (int i = front; i <= rear; i++)
                {
                    cout<<qu[i]<<" ";
                }
                    cout<<endl;
                
            }
            
        }
        
    }
};
int main(){
    cout<<"=======Simple Queue ========";
    SimpleQueue a;
    a.enqueue(5);
    a.enqueue(4);
    a.enqueue(3);
    a.enqueue(2);
    a.enqueue(1);
    cout<<"queue a: "<<endl;
    a.display();
    a.dequeue();
    a.dequeue();
    a.dequeue();
    a.dequeue();
    a.display();
    cout<<"=======Circular Queue ========"<<endl;
    CircularQueue b;
    b.enqueue(6);
    b.enqueue(5);
    b.enqueue(4);
    b.enqueue(3);
    b.enqueue(2);
    b.enqueue(1);
    cout<<"queue b: "<<endl;
    b.display();
    


}