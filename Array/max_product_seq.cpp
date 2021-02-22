#include<bits/stdc++.h>
using namespace std;

// brute force 

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
    int num_0=0;
    int num_neg=0;
    int num_pos=0;
    int product=1;
    int max_neg=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(a[i]>0)
        {
            num_pos++;
            product*=a[i];
        }
        else if(a[i]==0)
        {
            num_0++;
        }
        else
        {
            num_neg++;
            product*=a[i];
            if(max_neg<a[i])
            {
                max_neg=a[i];
            }
        }
    }
    if(num_0==n)
    {
        product=0;
    }
    else
    {
        if(num_neg%2==1)
        {
            product/=max_neg;
        }
    }
    

    cout<<"max product :"<<product<<endl;

}