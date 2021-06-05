#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;cin>>n;
    int a[n];
   set<int> s;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        s.insert(a[i]);
    }
    sort(a,a+n);

    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int diff=a[j]-a[i];

            if(s.find(a[j]+diff)!=s.end() )
            {
                cout<<a[i]<<" "<<a[j]<<" "<<a[j]+diff<<endl;
            }
        }
    }


}