#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n;cin>>n;

    int *a=new int[n];

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    int max_sum=INT_MIN;

    int sum_here=0;

    int ans1=0;
    int ans2=0;
    for(int i=0;i<n;i++)
    {
        sum_here+=a[i];
        if(max_sum<sum_here)
        {
            max_sum=sum_here;
            if(ans1==0 &&ans2==0)
            {
                ans2=i;
            }
            else if(ans1==0&&ans2!=0)
            {
                ans1=ans2;
                ans2=i;
            }
            else
            {
                ans1=ans2;
                ans2=i;
            }            
        }
        if(sum_here<0)
        {
            sum_here=0;
        }
    }
 cout<<max_sum<<endl;   
 cout<<ans1<<" "<<ans2<<endl;

}