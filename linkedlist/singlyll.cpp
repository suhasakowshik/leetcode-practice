#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;

        Node(int value):data(value),next(nullptr){}
    
};

class Linkedlist
{
    private:
        Node* head; //pointer for the head of the list

    public:
        //initialize empty list
        Linkedlist()
        {   
            head=nullptr;
        }

        Linkedlist(Node* nodeHead) 
        {
            head=nodeHead;
        }

        // to insert node at the end of the list
        void insertAtEnd(int value)
        {   
            Node* newNode=new Node(value);

            // If list is empty, make newNode the head
            if(head==nullptr)
            {
                head=newNode;
            }
            else
            {
                Node* temp=head;
                // Traverse to the last node
                while(temp->next!=nullptr)
                {
                    temp=temp->next;
                }
                // Link the last node to newNode
                temp->next=newNode;
            }
        }

        void deleteByValue(int value)
        {
            if(head==nullptr)
            {
                return;
            }
            if(head->data==value)
            {
                Node* temp=head;
                // Move head to the next node
                head=head->next;
                // Free memory of the deleted node
                delete temp;
                return;
            }
            Node* temp=head;
            while(temp->next && temp->next->data !=value)
            {   
                //traverse to find node to delete
                temp=temp->next;
            }

            if(temp->next)
            {
                Node* nodeToDelete=temp->next;
                temp->next=temp->next->next; // unlink the node
                delete nodeToDelete; // free memory
            }
        }

        void reverse()
        {
            Node* prevptr=nullptr;
            Node* currptr=head;
            Node* nextptr;

            while(currptr!=nullptr)
            {
                nextptr=currptr->next;
                currptr->next=prevptr;
                prevptr=currptr;
                currptr=nextptr;
            }
            head=prevptr;
        }


        void display()
        {
            Node* temp=head;
            while(temp!=nullptr)
            {
                cout<<temp->data<<"->";
                temp=temp->next;
            }
            cout <<"NULL"<<endl;
        }

        // //destructor
        // ~Linkedlist()
        // {
        //     Node* temp;
        //     while(head)
        //     {
        //         temp=head;
        //         head=head->next;
        //         delete temp;
        //     }
        // }

        Node* getHead() const { return head; }
};

// merge sorted linked lists
static Linkedlist merge(Linkedlist* l1,Linkedlist* l2)
{
    Node* dummy=new Node(0);
    Node* current=dummy;

    Node* p1=l1->getHead();
    Node* p2=l2->getHead();

    while(p1!=nullptr && p2!=nullptr)
    {
        if(p1->data < p2->data)
        {
            current->next=new Node(p1->data);
            p1=p1->next;
        }
        else
        {
            current->next=p2;
            p2=p2->next;
        }
        current=current->next;
    }

    // attaching remianing part
    if(p1!=nullptr)
    {
        current->next=p1;
    }
    else{
        current->next=p2;
    }

    return Linkedlist(dummy->next);
}

int main()
{
    Linkedlist list1,list2;

    list1.insertAtEnd(10);
    list1.insertAtEnd(20);
    list1.insertAtEnd(30);

    list2.insertAtEnd(5);
    list2.insertAtEnd(50);
    list2.insertAtEnd(65);

    Linkedlist mlist=merge(&list1, &list2);
    cout<<"merged list : ";
    mlist.display();

    cout<<"Linked list : ";
    list1.display();

    list1.deleteByValue(20);
    cout<<"After Deleting 20: ";
    list1.display();

    list1.reverse();
    cout<<"After Reversing: ";
    list1.display();

    return 0;
}
