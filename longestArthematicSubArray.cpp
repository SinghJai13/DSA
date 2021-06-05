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

        int ans=2;
        int cur_len=2;
        int pd=a[1]-a[0];
        int j=2;

        while(j<n)
        {
            if(a[j]-a[j-1]==pd)
            {
                cur_len++;

            }
            else{
                cur_len=2;
                pd=a[j]-a[j-1];
            }
            ans=max(ans,cur_len);
            j++;
        }
        cout<<"Case #"<<k<<": "<<ans<<endl;
    }
}