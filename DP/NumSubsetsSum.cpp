#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;cin>>n;
    int *a=new int[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
   // for(int i=0;i<n;i++)cout<<a[i]<<" ";
    int target;cin>>target;
    
    int **dp=new int*[n+1];
    for(int i=0;i<=n;i++)
    {
        dp[i]=new int[target+1];  
        for(int j=0;j<=target;j++)    
        {
            dp[i][j]=0;
        }  
    }

    
    for(int i=0;i<=n;i++)
    {
        dp[i][0]=1;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=target;j++)
        {
            if(a[i-1]>j)
            {
                dp[i][j]=dp[i-1][j];
            }
            else
            {
                dp[i][j]=dp[i-1][j]+dp[i-1][j-a[i-1]];
            }
        }
    }
    cout<<dp[n][target]<<endl;
    
    delete(dp);
    delete(a);
}