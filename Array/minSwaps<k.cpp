//minimum number of swaps reqd to bring elements less than k together
#include<bits/stdc++.h>
using namespace std;
int minSwap(int *arr, int n, int k) {
    // Complet the function
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<=k)cnt++;
    }
    
    if(cnt==n)
    {
        return 0;
    }
    else
    {
        int itr1=0;
        int itr2=0;
        int temp=0;
        int max=0;
        for(int i=0;i<cnt;i++)
        {
            if(arr[i]<=k)
            {
                temp++;
            }
        }
        itr2=cnt-1;
        
        max=temp;
        while(itr2+1<n)
        {
            if(arr[itr1]<=k)
            {
                temp--;
            }
            if(arr[itr2+1]<=k)
            {
                temp++;
            }
            if(max<temp)
            {
                max=temp;
            }
            itr1++;
            itr2++;
            
        }
        
        return cnt-max;
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

    cout<<"enter the threshold value:"<<endl;
    int k;cin>>k;
    cout<<"Minimum number of swaps reqd to bring elements <="<<k<<" are -: "<<minSwap(a,n,k)<<endl

}