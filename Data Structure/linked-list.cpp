#include<iostream>

using namespace std;

class Node
{
public:
    int x;
    Node* next;

    Node(int y)
    {
        x=y;
        next = NULL;
    }
};

class List
{
public:
    Node* head;
    Node* tail;

    List()
    {
        head = NULL;
        tail = NULL;
    }

    void addToTail(int y)
    {
        Node* newNode = new Node(y);

        if(head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }

    }

    void printList()
    {
        cout<<"List :"<<endl;
        Node* tmp = head;

        while(tmp != NULL)
        {
            cout<<tmp->x<<endl;
            tmp = tmp->next;
        }
    }

    void addToHead(int y){
        Node* newNode = new Node(y);

        if(head == NULL){
            head = newNode;
            tail = newNode;
        }else{
            newNode->next = head;
            head = newNode;
        }
    }

    bool isEmpty(){
        return head == NULL;
    }

    ~List(){
        Node* tmp = head;
        while(head != tail){
            tmp = head;
            head = head->next;
            delete tmp;
        }
        delete tail;
    }

    // int findNode(){
        
    //     if (head==NULL)
    //     {
    //         return NULL;
    //     }
        
    //     Node *next_node=

    // };

};

int main()
{
    List l1;

    l1.addToTail(5);
    l1.addToTail(8);
    l1.addToTail(4);
    l1.addToTail(9);

    l1.printList();

    List newList;

    newList.addToTail(2);
    newList.addToTail(5);
    newList.printList();
    return 0;
}
