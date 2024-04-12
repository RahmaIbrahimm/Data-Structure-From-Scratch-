#include <iostream>

using namespace std;

class node{
    public:
    int data ;
    node * next;
};
class dNode{
    public: 
    int data;
    dNode *next;
    dNode *prev;
};

class LinkedList{

    node *head;
    public:
    LinkedList(){ head=NULL; }
    ~LinkedList(){}

    bool isEmpty(){
        return head==NULL;
    }
    void addToHead(int value){
        node * new_node = new node;
        new_node->data = value;          
        if (isEmpty())
        {
            head = new_node ;   
            head->next=NULL;
        }
        else{
            new_node->next = head;
            head = new_node;
        }

    }
    void addToTail(int value){
        node *new_node = new node;
        new_node->data = value;
        new_node->next = NULL;

        if (isEmpty())
        {
            head=new_node;
        }
        else{
            node *temp;
            temp=head;
            while (temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=new_node;
            
        }
        
    }
    void printList(){
        //if empty print Empty list
        if (isEmpty())
        {
            cout<<"Empty list"<<"\n";
        }
        //other than that: pass through each node and print the data in it
        else{
            node *temp;
            temp = head;
            while (temp!=NULL)
            {
                cout<<temp->data<<" ";
                temp = temp->next;
            }
        }
        cout<<"\n";

    }
    void clearList(){
        if (isEmpty())
        {
            cout<<"Empty List";
        }
        else{


            node *temp = head->next;
            node *beforeTemp = head->next;
            while (temp!=NULL)
            {
                temp=temp->next;
                delete beforeTemp;
                beforeTemp=temp;
            }
            head=NULL;
            cout<<"List has been cleared."<<"\n";
           
        }
        
    }
};
class DoublyList{
    dNode *head;
    public:
    DoublyList(){head = NULL;}
    bool isEmpty(){
        return head == NULL;
    }

    void addToHead(int value){
        dNode *new_node = new dNode;
        new_node->data=value;
        new_node->prev=NULL;
        if (isEmpty())
        {
            head=new_node;
            head->next=NULL;
        }
        else{
            new_node->next=head;
            head=new_node;
        }
    }
    void addToTail(int value){
        dNode *new_node = new dNode;
        new_node->data=value;
        new_node->next=NULL;
        if (isEmpty())
        {
            head=new_node;
            head->prev=NULL;
        }
        else{
           
            dNode *temp;
            temp=head;
            while (temp->next!=NULL)
            {
                temp=temp->next;     
            }
            new_node->prev =temp;
            temp->next=new_node;
            
        }        
    }
    void printList(){
        if (isEmpty())
        {
            cout<<"Empty List.";
        }
        else{    
            dNode *temp;
            temp=head;
            while (temp!=NULL)
            {
                cout<< temp->data<<" ";
                temp=temp->next;
            }
        }
        cout<<"\n";
    }

    int findNode(int value){
        if (isEmpty())
        {
            cout<<"Empty List."<<"\n";
            return -1;
        }
        
        dNode *temp;
        temp = head;
        int count = 1;
        while (temp!=NULL)
        {
            if (temp->data == value)
            {
                return count;
            }
            temp=temp->next;
            count++;
        }
        cout<<"Doesn't exist"<<"\n";
        return -1;
        
    }

    void deleteFromHead(){
        if (isEmpty())
        {
            cout<<"Empty List."<<endl;
        }
        else{
          if (head->next == NULL)
          {
            head=NULL;
          }
          else{
            dNode *temp;
            temp=head;
            head=head->next;
            head->prev=NULL;
            delete temp;
          }
          
            
        }
        
    }
    void deleteFromTail(){
         if (isEmpty())
        {
            cout<<"Empty List."<<endl;
        }
        else{
          if (head->next == NULL)
          {
            head=NULL;
          }
          else{
            dNode *temp;
            temp=head;
            while (temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->prev->next=NULL;
            delete temp;
          }
          
            
        }
    }
    void deleteFrom(int position){
        dNode *temp;
        if (isEmpty())
        {
            cout<<"Empty List."<<endl;
            return; 
        }
        
        else if (position==1)
        {
            deleteFromHead();
        }
        else{
            int count = 1;
 
            temp = head;
            while (temp!=NULL)
            {
                if (count == position)
                {
                    break;
                }
                temp = temp->next;
                count++;
                
            }
            if (temp == NULL)
            {
                cout<<"Invalid position."<<endl;
                return;
            }
            
        }

        if (temp->next == NULL)
        {
            temp->prev->next = NULL;
            
        }
        else
        {
            temp->prev->next = temp->next; 
            temp->next->prev = temp->prev; 
        }
        delete temp;
        
        
    }; 


};
class CircularList{
    node *head;
    public:
    CircularList(){head=NULL;}
    bool isEmpty(){
        return head==NULL;
    }
    void addToHead(int value){
        node *new_node = new node;
        new_node->data=value;
        if (isEmpty())
        {
            head=new_node;
            head->next=NULL;
        }
        else{
            new_node->next=head;
            head=new_node;
            
        }
        
    }
    void addToTail(int value){
        node *new_node = new node;
        new_node->data=value;
        new_node->next=head;
        if (isEmpty())
        {
            head=new_node;
        }
        else{
            node *temp = head;
            while (temp->next!=head)
            {
                temp=temp->next;
            }
            
            temp->next=new_node;

        }
        
    }
    void printList(){
        if (isEmpty())
        {
            cout<<"Empty List."<<endl;
        }
        else{
            node * temp = head;
            while (temp->next!=head)
            {
                cout<<temp->data<<" ";
                temp=temp->next;
            }
            cout<<temp->data;
            cout<<endl;    
        }
        
    }
};

int main(){
    cout<<"======== Single Linked List ========="<<"\n";
    LinkedList l ;
    l.printList();
    l.addToHead(4);
    l.addToHead(3);
    l.addToHead(2);
    l.addToHead(1);
    cout<<"List l:"<<"\n";
    l.printList();
    
    LinkedList a;
    a.addToHead(0);
    a.addToHead(1);
    a.addToHead(10);
    a.addToTail(11);
    cout<<"List a: "<<"\n";
    a.printList();

    LinkedList b;
    b.addToHead(5);
    b.addToHead(4);
    b.addToTail(6);
    b.addToTail(7);
    cout<<"List b: "<<"\n";
    b.printList();
    b.clearList();
    b.printList();
    cout<<"======== Doubly Linked List ========="<<"\n";
    DoublyList c;
    c.addToHead(4);
    c.addToHead(3);
    c.addToHead(2);
    c.addToHead(1);
    c.addToTail(5);
    c.addToTail(6);
    c.addToTail(7);
    c.addToTail(8);
    cout<<"List c: "<<"\n";
    c.printList();

    DoublyList d;
    d.addToHead(11);
    d.addToHead(12);
    d.addToHead(13);
    d.addToHead(14);
    d.addToHead(15);
    d.addToTail(10);
    d.addToTail(9);
    d.addToTail(8);
    d.addToTail(7);
    d.addToTail(6);
    d.addToTail(5);
    d.addToTail(4);
    cout<<"List d: "<<"\n";
    d.printList();
    cout<<"find node: "<<"\n";
    cout<<d.findNode(4)<<"\n"<<d.findNode(0)<<"\n";
    // d.deleteFromHead();
    // d.deleteFromTail();
    // d.deleteFrom(5);
    d.printList();
    cout<<"======== Circular Linked List ========="<<"\n";

    CircularList e;
    e.addToHead(5) ;
    e.addToHead(4) ;
    e.addToHead(3) ;
    e.addToHead(2) ;
    e.addToHead(1);
    e.addToTail(0) ;
    e.addToTail(-1) ;
    e.addToTail(-2); 
    e.addToTail(-3); 
    e.addToTail(-4); 
    e.addToTail(-5); 
    e.printList();


}