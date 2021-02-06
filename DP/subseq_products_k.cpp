#include<bits/stdc++.h>
using namespace std;
int products(int *a,int k,int n)
{
    int **ans=new int*[n+1];

    for(int i=0;i<n+1;i++)
    {
        ans[i]=new int[k+1];
        for(int j=0;j<k+1;j++)
        {
            ans[i][j]=0;
        }
    }

    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<k+1;j++)
        {
            ans[i][j]=ans[i-1][j];

            if(a[i-1]<=j&& a[i]>0)
            {
                ans[i][j]+=ans[i-1][(j/a[i-1])]+1;
            }
        }
    }

    return ans[n][k];
}
int main()
{
    int n;cin>>n;
    int *a=new int[n];

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    int k;cin>>k;
    cout<<products(a,k,n)<<endl;   
}