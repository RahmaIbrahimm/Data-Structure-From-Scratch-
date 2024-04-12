#include <iostream>
using namespace std;

class sNode{
    public:
    int data;
    sNode *next;
};


class stack{
    sNode *top;
    public:
    stack(){ top = NULL;}
    bool isEmpty(){
        return top == NULL;
    }
    void push(int value){
        sNode *new_node = new sNode;
        new_node->data = value;
        new_node->next = top;
        top = new_node;
        
    }
    int pop(){
        if (isEmpty())
        {
            cout<<"Empty Stack."<<endl;
            return -1;
        }
        else{
            sNode *temp;
            temp = top;
            top = top->next;
            int value = temp->data;
            delete temp;
            return value;
        }
        
    }
    void display(){

        if (isEmpty())
        {
            cout<< "Stack underflow"<<endl;
        }
        else{
            sNode *temp;
            temp=top;
            while (temp!=NULL)
            {
                cout<<temp->data<<" ";
                temp=temp->next;
            }
            cout<<endl;
            
        }
        
    }
    int peek(){
        if (isEmpty())
        {
            cout<<"Stack underflow."<<endl;
            return -1;
        }
        else{
            return top->data;
        }
        
    }
};

int main(){
    stack a;
    cout<<"Stack a :"<<endl;
    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);
    a.push(5);
    a.display();
    a.pop();
    a.pop();
    a.display();
    cout<<"Peek: "<<a.peek();
}