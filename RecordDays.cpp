#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;cin>>t;
    for(int k=1;k<=t;k++)
    {
        int n;cin>>n;
        int a[n];
        for(int i=0;i<n;i++)cin>>a[i];

        int ans=0;
        if(n==1)
        {
            ans=1;
        }
        else
        {
            stack<int> s;
            s.push(0);

            if(a[0]>a[1])
            {
                ans++;
            }

            for(int i=1;i<n;i++)
            {
                if(s.size()>0 && a[s.top()]>a[i])
                {
                    s.push(i);
                    continue;
                }
                else
                {
                    while(s.size() && a[s.top()]<=a[i])
                    {
                        s.pop();
                    }
                    if(s.size()==0)
                    {
                        if(i==n-1 && a[n-1]!=a[n-2])
                        {
                            ans++;
                        }
                        else if(a[i]>a[i+1])
                        {
                            ans++;
                        }

                    }
                    s.push(i);
                }
            }
          
        }
        cout<<"Case #"<<k<<": "<<ans<<endl;
        
    }
}