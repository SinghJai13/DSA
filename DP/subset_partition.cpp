#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"Enter the size of array :"<<endl;
    int n;cin>>n;

    int *arr=new int[n];
    int sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    int wt=sum/2;
            sort(arr,arr+n);
            int ans[n+1][wt+1];
            
            memset(ans,0,sizeof(ans));
            
            //ans[0][0]=1;
            

            for(int i=1;i<=n+1;i++)
            {
                for(int j=1;j<=wt;j++)
                {
                    if(j<arr[i-1])
                    {
                        ans[i][j]=0;
                    }
                    else
                    {
                        ans[i][j]=ans[i-1][j-arr[i-1]];
                    }
                    
                }
            }
           for(int i=0;i<=n;i++)
            {
                for(int j=0;j<=wt;j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
            
}