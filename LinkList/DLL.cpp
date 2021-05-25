#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node *prev;
    Node *next;

    Node()
    {
        data=INT_MIN;
        prev=NULL;
        next=NULL;

    }
    Node(int data)
    {
        this->data=data;
        prev=NULL;
        next=NULL;
    }
};

class linkList{
public:
    Node* root;
    Node* last;
    linkList()
    {
        root=NULL;
        last=NULL;
    }

void createLL()
    {
        cout<<" Enter the value of root "<<endl;

        int data;cin>>data;
        Node *nt=new Node(data);
        root=nt;

        Node *temp=new Node();
        temp=root;
        cout<<" Enter the number of nodes (including root node) "<<endl;
        int n;cin>>n;
        int k=n-1;
        while(k>0)
        {
            k--;
            cin>>data;
            Node *temp1=new Node(data);
            temp->next=temp1;

            temp1->prev=temp;
            temp=temp1;
            last=temp1;
        }
        
    }

    void printLL()
    {
        Node *temp=root;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    void revPrintLL()
    {
        Node *temp=last;

        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->prev;
        }
        cout<<endl;
    }
    void addToStack(int data)
    {
        if(last!=NULL)
        {
            Node *temp=new Node(data);

            last->next=temp;
            temp->prev=last;
            last=temp;
        }
        else{
            Node *temp=new Node(data);
            last=temp;
            root=temp;
            last->prev=root;
            root->next=last;
        }
    }
    int pop()
    {
        if(last==NULL)
        {
            cout<<"Empty"<<endl;
            return INT_MIN;
        }
        else
        {
            int ans=last->data;

            Node *temp=new Node();
            temp=last->prev;
            temp->next=NULL;
            last=temp;
            return ans;
        }
    }
    int getSize()
    {
        if(root==NULL)
        {
            return 0;
        }
        else{
            int n=0;
            Node *temp=new Node();
            temp=root;

            while(temp)
            {
                n++;
                temp=temp->next;
            }
            return n;
        }
    }
    int getMiddle()
    {
        int size=getSize();
        Node *temp=new Node();
        temp=root;
        for(int i=0;i<size/2;i++)
        {
            temp=temp->next;
        }
        return temp->data;
    }
};
int main()
{
    linkList *ll=new linkList();
    ll->createLL();
    ll->printLL();
    ll->revPrintLL();

    ll->addToStack(50);
    ll->printLL();
   int ans=ll->pop();
   cout<<ans;

    ll->printLL();

int middle=ll->getMiddle();
cout<<"Middle="<<middle<<endl;



}