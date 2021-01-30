#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"Enter size of array :"<<endl;
    int n;cin>>n;
    int *a=new int[n];

    cout<<"Enter "<<n<<" elements of the array :"<<endl;

    for(int i=0;i<n;i++)cin>>a[i];

    int k;cin>>k;

    int *presum=new int[n];
    memset(presum,0,n);

    presum[0]=a[0];
    priority_queue<int, vector<int>, greater<int> > Q;
    for(int i=1;i<n;i++)
    {
        presum[i]=a[i]+presum[i-1];
    }

    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            int cur_sem=presum[j]-presum[i]+a[i];

            if(Q.size()<k)
            {
                Q.push(cur_sem);
            }
            else
            {
                if(Q.top()<cur_sem)
                {
                    Q.pop();
                    Q.push(cur_sem);
                }
            }
            
        }
    }
    cout<<Q.top()<<endl;



}