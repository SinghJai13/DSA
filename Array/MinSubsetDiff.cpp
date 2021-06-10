#include<bits/stdc++.h>
using namespace std;
void MaxDiff(vector<int> v,int i,int &ans,int s1,int s2)
{
    if(i==v.size())
    {
        ans=min(ans,abs(s1-s2));
        return ;
    }
    else
    {
        MaxDiff(v,i+1,ans,s1+v[i],s2);
        MaxDiff(v,i+1,ans,s1,s2+v[i]);

        return;
    }
}

int main()
{
    vector<int> v(6);
    for(int i=0;i<6;i++)
    {
        cin>>v[i];
    }
    int ans=INT_MAX;

    MaxDiff(v,0,ans,0,0);

    cout<<ans<<endl;

}