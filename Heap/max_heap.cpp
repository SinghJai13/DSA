#include<iostream>
using namespace std;

void heapify(int *a,int n,int index)
{
    if(index<0)
    {
        return ;
    }
    
    
    else
    {
        int largest=index;

        int left=2*index+1;
        int right=2*index+2;
        if(left<n)
        {
            if(a[largest]<a[left])
            {
                largest=left;
            }
            if(right<n)
            {
                if(a[largest]<a[right])
                {
                    largest=right;
                }
            }
        }
        if(largest==index)
        {
            heapify(a,n,index-1);
        return ;
        }
        else
        {
            swap(a[index],a[largest]);
            heapify(a,n,largest);
            return ;
        }
        
    }
    
}
int main()
{
    cout<<"Enter the size of array :"<<endl;
    int n;cin>>n;

    int *a=new int[n];

    cout<<"Enter the elements of the array :"<<endl;

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    heapify(a,n,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
    
}