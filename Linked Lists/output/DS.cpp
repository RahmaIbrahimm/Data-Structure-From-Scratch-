#include<iostream>
#include<string>
using namespace std;
//Check if the list is Empty
// bool isEmpty();

// //Adding nodes

// //add to the end of the list
// void addToTail(string data);
// //addes a node the the wanted postition (c)
// void addNode(string data , int c)

// //Print the task list
// void printList();

// //count what's on the list
// int countTasks();

// //delete node at the wanted position
// void deleteTask(int position);


class Node{
   public:
    string data;
    Node*next;
    Node*prev;
};
class DoublyLinkedList{
    Node * head;
    public:
    DoublyLinkedList(){head=NULL;};
  
void addToTail(string data)
{
	Node* p= new Node;
	p->data=data;
	p->next=NULL;
	
	if(head!=NULL)
	{
		Node* q=head;
		while(q->next!=NULL)
			q=q->next;
		q->next=p;
		p->prev=q;
	}
	else
	{
		p->prev=NULL;
		head=p;
	}
	
}

void printList()
{
	if(head==NULL)
		return;
	Node *p=head;
	while(p!=0)
	{
	cout<<p->data<<" ";
		p=p->next;
	}	
	cout<<"\n";
}

int countTasks()
    {
        int counter=0;
        Node *temp=head;
        while(temp!=NULL){
            counter++;
            temp=temp->next;
        }
        return counter;
    }

    void addNode(string data , int c){
            Node*p=new Node;
            p->data=data;
            Node *ptr=head;
            //used to check that it's not more than the size of linked list elements
            if(countTasks() >=c)
            { //add to head
                    if(c==1)
                    {
                        if(head==NULL){ p->prev=NULL;
                        p->next=NULL;
                        head=p;}
                        else {
                            p->next=head;
                            head->prev=p;
                            p->prev=NULL;
                            head=p;
                        }
                        
                    } 
                    else{ for (int i=1;i<c-1;i++)
                    { ptr=ptr->next;  
                    }
                        p->prev=ptr;
                        p->next=ptr->next;
                        if(ptr->next!=NULL) ptr->next->prev=p;
                        ptr->next=p;
                    }
                    
            }
            else {cout<<"there's not that many nodes enter position from the list\n";}
    }


    bool isEmpty(){
        return head==NULL;
    }


    void deleteTask(int position) {
    // Check if the linked list is empty
    if (isEmpty()) {
        cout << "The To-do list is empty." << endl;
    }
    else{
    // Check if the position is valid
    int count = 1;
    Node* toDelete = head;
    while (toDelete != NULL && count < position) {
        toDelete = toDelete->next;
        count++;
    }
    if (toDelete == NULL) {
        cout << "Invalid position." << endl;
        return;
    }

    // Delete the node
    if (toDelete == head) {
        head = toDelete->next;
        if (head != NULL) {
            head->prev = NULL;
        }
    } else if (toDelete->next == NULL) {
        toDelete->prev->next = NULL;
    } else {
        toDelete->prev->next = toDelete->next;
        toDelete->next->prev = toDelete->prev;
    }
    delete toDelete;
    }
}


};
   
    
int main()
{ 

}
