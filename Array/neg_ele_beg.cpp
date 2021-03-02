//move all -neg elemenst to the beginning
#include<bits/stdc++.h>
using namespace std;
void sign_sort(int *a,int n)
{
    int st=0;
    for(int i=0;i<n;)
    {
        if(a[i]<0)
        {
            swap(a[i],a[st]);
            
                i++;
                st++;
            
        }
        else
        {
            i++;
        }
    }
}
int main()
{
    cout<<"Enter size of array :"<<endl;
    int n;cin>>n;
    int *a=new int[n];

    cout<<"Enter the elements of the array "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<endl;
    sign_sort(a,n);
   for(int i=0;i<n;i++)
    {
    
        cout<<a[i]<<" ";
    } 

}