#include <iostream>
using namespace std;
class Node{
    public:
    Node *next;
    int data;
};

class CircularList{
    private:
    Node *head;
    public:
    // consturctor (initalize the head and next to NULL)
    CircularList(){
        head=NULL;
    };
    // Distructor (delete the list entirely)
    ~CircularList(){
        Node *p = head;
        while (p!=NULL)
        {
            p=head->next;
            delete head;
            head=p;
        }
            
        };
        //checks if the list is empty or not
        bool isEmpty(){
            return head==NULL;
        }
        
        // add a new node at the start of the circular linked list
        void addToHead(int data){
            Node *p = new Node; 
 
            p->data=data;
            p->next=head;
            if (isEmpty())
            {
                head=p;
                head->next=head;
            }
            else{
                Node *temp=head;
                while (temp->next!=head)
                {
                    temp = temp->next;
                }
                head=p;
                temp->next=head;
                
            }
            
        };
        //Add a new node at the end of the list
        void addToTail(int data){
            Node * new_node= new Node;
            new_node->data=data;
            new_node->next=head;
            if (isEmpty())
            {
                head=new_node;
                head->next=new_node;
            }
            else{
            Node *curr=head;
            while (curr->next!=head)
            {
                curr=curr->next;
            }
            curr->next=new_node;

            }
        };
        //deletes the first node in the list
        void deleteFromHead(){
            if (!isEmpty())
            {
                if (head->next==head)
                {
                    delete head;
                }
                else{
                    Node *p=head,*temp=head;
                    while (p->next!=head)
                    {
                        p=p->next;
                    }
                    p->next=head->next;
                    head=head->next;
                    delete temp;

                }
                    
            }
            
            
        }
        //deletes the last node
        void deleteFromTail(){
            if (!isEmpty())
            {

                if (head->next==head)
                {
                    delete head;
                    head=NULL;
                }
                else{
                    Node *curr=head , *p;
                    while (curr->next!=head)
                    {   
                        p=curr;
                        curr=curr->next;
                    };
                    delete curr;
                    p->next=head;
                }
            }
            
        };
        //deletes all the nodes in the list
        void deleteAllNodes(){
            
            if (!isEmpty())
            {
                if (head->next==head)
                {
                    delete head;
                    head=NULL;
                }
                else{
                    Node *curr=head->next ,*p;
                    while (curr!=head)
                    {
                        p=curr;
                        curr=curr->next;
                        delete p;
                    }
                    delete curr;
                    head=NULL;
                }
                
            }
            
        }
        // Print all the data in the nodes
        void printList(){
            if (isEmpty())
            {
                cout<<"Empty list"<<"\n";
            }
            else
            {
                Node *temp;
                temp=head;
                while (temp->next!=head)
                {
                    cout<<temp->data<<" ";
                    temp=temp->next;
                }
                cout<<temp->data<<"\n";
            }
            
        }


};

int main(){
    CircularList c ;

    c.addToTail(98);



    c.deleteAllNodes();
    c.printList();

    return 0;
}