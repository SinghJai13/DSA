#include<bits/stdc++.h>
using namespace std;
void  heapify(int *a,int n,int index)
{


    if(index<0)
    {
       
        return;
    }
    else
    {
        int right=(2*index)+2;
        int left=right-1;

        int smallest=index;
        if(left<n)
        {
\
            if(a[left]<a[smallest])
            {
                smallest=left;
            }


        }
        if(right<n)
        {
           
            if(a[right]<a[smallest])
            {
            smallest=right;
            }
        }
        if(smallest==index)
        {
           
            heapify(a,n,index-1);
            return ;
        }
        else
        {
            swap(a[smallest],a[index]);

            heapify(a,n,smallest);
            return ;
        }
        
    }
}
int extract_min(int *a,int& red_size,int full_size)
{
    if(red_size>0)
    {
        int ans=a[0];

        swap(a[0],a[red_size-1]);

        red_size--;

        heapify(a,red_size,red_size-1);

        return ans;
    }
    else
    {
        return INT_MIN;
    }
    
}
int main()
{
    cout<<"Enter size of array :"<<endl;
    int n;cin>>n;
    int *a=new int[n];

    cout<<"Enter "<<n<<" elements of the array :"<<endl;

    for(int i=0;i<n;i++)cin>>a[i];

    heapify(a,n,n-1);

    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<"enter k :"<<endl;
    int k;cin>>k;

    int size=n;
    for(int i=0;i<k;i++)
    {
        int ans=extract_min(a,size,n);

        if(i==k-1)
        {
            cout<<ans<<endl;
        }
    }
}