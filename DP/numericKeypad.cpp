#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"Enter N :"<<endl;
    int N;cin>>N;
        map<int,vector<int> >m;
		m[0].push_back(8);
	    m[1].push_back(2);
	    m[1].push_back(4);
	    //m[1].push_back(2); 
	   
        m[2].push_back(1);
	    m[2].push_back(3);
	    m[2].push_back(5);
	    
    
	    m[3].push_back(2);
	    m[3].push_back(6);
	    
	    m[4].push_back(1);
	    m[4].push_back(5);
	    m[4].push_back(7);
	    
	    m[5].push_back(8);
	    m[5].push_back(2);
	    m[5].push_back(4);
	    m[5].push_back(6);
	    
	    m[6].push_back(3);
	    m[6].push_back(5);
	    m[6].push_back(9);
	    
	    m[7].push_back(8);
	    m[7].push_back(4);
	    
	    m[8].push_back(5);
	    m[8].push_back(7);
	    m[8].push_back(9);
	    m[8].push_back(0);
	    
	    m[9].push_back(8);
	    m[9].push_back(6);
	    
		
		int n=10;
		long long **dp=new long long*[N+1];
		for(int i=0;i<N+1;i++)
		{
		    dp[i]=new long long[n];
            for(int j=0;j<n;j++)
            {
                dp[i][j]=0;
            }
		   
		}
		
		int ans=0;
		for(int i=0;i<n;i++)
		{
        
		    dp[1][i]=1;
            m[i].push_back(i);
		}
		
		for(int i=2;i<=N;i++)
		{
		    for(int j=0;j<n;j++)
		    {
		        long long  sum=0;
		        
		        for(int k=0;k<m[j].size();k++)
		        {
		            sum+=dp[i-1][m[j][k]];
		        }
		        //sum+=dp[i-1][j];
		        dp[i][j]=sum;
                
                if(i==N)
                ans+=dp[i][j];


		    }
		
		}
        
        for(int i=0;i<=N;i++)
        {
            cout<<i<<"--> ";

            for(int j=0;j<10;j++)
            {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
     
     cout<<endl<<endl<<ans;
}
        