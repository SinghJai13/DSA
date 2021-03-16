#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"Enter the size of array :"<<endl;
    int n;cin>>n;

    int *a=new int[n];

    cout<<"em\nther the elements of the array :"<<endl;

    for(int i=0;i<n;i++)cin>>a[i];


    sort(a,a+n);

    cout<<endl;
    int pt_insertion=1;
    for(int i=n-1;i>n/2 && pt_insertion<n;i--)
    {
        int last=a[n-1];


        for(int j=n-2;j>=pt_insertion;j--)
        {
            a[j+1]=a[j];
        }
        a[pt_insertion]=last;

        pt_insertion+=2;
    }
    cout<<"New array is "<<endl;
    for(int i=0;i<n;i++)cout<<a[i]<<" ";
    cout<<endl;
    int abs_dif_sum=0;
    for(int i=0;i<n-1;i++)
    {
        abs_dif_sum+=abs(a[i+1]-a[i]);

    }

    cout<<"Maximum sum of absolute difference is"<<endl;
    cout<<abs_dif_sum<<endl;


}
