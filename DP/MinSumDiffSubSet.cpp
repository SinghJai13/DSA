#include<bits/stdc++.h>
using namespace std;
int minDiffernce(int a[], int n) 
	{ 
	    // Your code goes here
	    int sum=0;
	    for(int i=0;i<n;i++)
	    {
	        sum+=a[i];
	    }
	    sort(a,a+n);
	    
	    bool dp[n+1][sum+1];
	    memset(dp,false,sizeof(dp));
	    
	    for(int i=0;i<n+1;i++)
	    {
	        dp[i][0]=true;
	    }
	  
	    
	    int ans=sum;
	    
	    for(int i=1;i<=n;i++)
	    {
	        for(int j=1;j<=sum;j++)
	        {
	            if(a[i-1]>j)
	            {
	                dp[i][j]=dp[i-1][j];
	            }
	            else
	            {
	                dp[i][j]=dp[i-1][j] or dp[i-1][j-a[i-1]];
	            }
	        }
	        
	    }
	    
	    
	    for(int i=0;i<=sum/2;i++)
	    {
	        if(dp[n][i]==1)
	        {
	            int s1=i;
	            int s2=sum-i;
	            
	            if(ans>abs(s2-s1))
	            {
	                ans=abs(s2-s1);
	            }
	        }
	    }
	    
	    return ans;
	} 
int main()
{
    int n;cin>>n;
    int *a=new int[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<minDiffernce(a,n)<<endl;
}
