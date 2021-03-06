#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node * next;
    Node(int data)
    {
        this->data=data;
        next=NULL;
    }

};
Node * takeinput()
{
    cout<<"Enter number of nodes :"<<endl;
    int n;cin>>n;

    cout<<" enter the values:"<<endl;
    Node* head=new Node(0);
    Node* tail=head;
    for(int i=0;i<n;i++)
    {
         int temp;cin>>temp;
        if(i==0)
        {
            head->data=temp;
        }
        else
        {
            Node* t=new Node(temp);
            tail->next=t;
            tail=t;

        }
        
    }
    return head;

}
void print(Node *head)
{
    if(head==NULL)
    {
        return ;
    }
    else
    {
        Node* temp=head;

        cout<<head->data<<" ";
        print(head->next);
    }

}
int len(Node *head)
{
    if(head==NULL)
    {
        return 0;
    }
    else
    {
        return 1+len(head->next);
    }
}
bool detectcycle(Node* head)
{
    if(head==NULL||head->next==NULL)
    {
        return false;
    }
    else
    {
        Node *fast=head;
        Node* slow=head;

        while(slow&&fast&&fast->next)
        {
            cout<<"Slow ptr at "<<slow->data<<"    Fast ptr at "<<fast->data<<" "<<endl;
            slow=slow->next;
            fast=fast->next->next;

            if(slow==fast)
            {
               // cout<<slow->data<<endl;
                cout<<"Cycle found at  ="<<slow->data<<endl;
                return true;
            }
        }

        return false;
    }
    
}
void remove_Duplicates(Node* head,Node *prev)
{
    if(head==NULL||(prev==NULL&&head==NULL))
    {
        return ;
        
    }
    
    if(prev==NULL)
    {
        if(head->next!=NULL)
        {
        remove_Duplicates(head->next,head);
        }
        return;
    }
    else
    {
        
        if(prev&&head&&prev->data==head->data)
        {
            prev->next=head->next;

            remove_Duplicates(prev->next,prev);
        }
        else
        {
            remove_Duplicates(head->next,head);
        }
        
    }
    

}
int main()
{
    Node* head=takeinput();

    print(head);
cout<<endl;
    int length=len(head);
    cout<<"Length of ll:="<<length<<endl;
    bool tr=detectcycle(head);

    if(tr==false)
    {
        cout<<"No cycle"<<endl;
    }
    
    

    //inducing loop
    Node *loop_head1=head;
    Node *loop_head2=head;
    for(int i=0;i<length;i++)
    {
        if(i==length/2)
        {
            cout<<loop_head1->data<<" loop head "<<endl;
        }
        else if(i>length/2)
        {
            loop_head2=loop_head2->next;
        }
        else
        {
           loop_head1=loop_head1->next;
            loop_head2=loop_head2->next;
        }
        
    }
    cout<<loop_head2->data<<" loop tail "<<endl;

    loop_head2->next=loop_head1;

    bool tr1=detectcycle(head);
    if(tr1==false)
    {
        cout<<"No cycle"<<endl;
    }


///// removing loop 


///algo

/*

    1) detect lloop
    2) count the length of loop==k
    3) make 2 ptrs one at (head) and other at (head +k)
    4) move them at same pace till ptr1==ptr2
    5) this give the head of the loop
    6) now find loop tail by ptr2->next!=ptr1

    now make ptr2->next=tail;

*/

int count=0;//to count loop length
loop_head2=loop_head1;
while(loop_head2->next!=loop_head1)
{
    count++;
    loop_head2=loop_head2->next;
}
count++;

cout<<"length of loop "<<count<<endl;

loop_head2=head;
loop_head1=head;

for(int i=0;i<count;i++ )
{
    loop_head2=loop_head2->next;
}
cout<<"head ptr "<<loop_head1->data<<endl;
cout<<" head+k ptr ="<<loop_head2->data<<endl<<endl;
while(loop_head2!=loop_head1)
{
    cout<<"ptr ="<<loop_head1->data<<"  ptr+k ="<<loop_head2->data<<endl;

    loop_head2=loop_head2->next;
    loop_head1=loop_head1->next;
}
cout<<"head of loop "<<loop_head1->data<<endl;


for(int i=0;i<count-1;i++)
{
loop_head2=loop_head2->next;    
}

loop_head2->next=NULL;

cout<<detectcycle(head);
}

