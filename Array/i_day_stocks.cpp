#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int>&p1, pair<int,int>&p2)
{
    if(p1.first<p2.first)
    {
        return true;
    }
    else if(p1.first==p2.first)
    {
        return p1.second<p2.second;
    }
    else
    {
        return false;
    }
}
int main()
{
    int t;cin>>t;
    while(t--)
    {
        cout<<"Enter the number of the days:"<<endl;

        int n;cin>>n;

        int *a=new int[n];
        cout<<"Enter the prices of the stocks for "<<n<<" days :"<<endl;

        for(int i=0;i<n;i++)cin>>a[i];
        vector<pair<int,int> >v;
        //price of stock ,ith day
        for(int i=0;i<n;i++)
        {
            v.push_back(make_pair(a[i],i+1));
        }
        sort(v.begin(),v.end(),cmp);
        
        for(int i=0;i<n;i++)
        {
            cout<<v[i].first<<" "<<v[i].second<<endl;
        }

        cout<<"Enter total money :"<<endl;
        int k;cin>>k;

        int ans=0;
        int mon_left=k;
        for(int i=0;i<n;i++)
        {
            pair<int,int>temp=v[i];

            if(temp.first *temp.second<=mon_left)
            {
                ans+=temp.second;
                mon_left-=temp.first*temp.second;
                continue;
            }
            else if(mon_left>=temp.first)
            {
                ans+=(mon_left/temp.first);
                mon_left-=temp.first*(mon_left/temp.first);
            }
            else{
                break;
            }
        }
        
        cout<<"Money left "<<mon_left<<" total stocks bought "<<ans;
        
    }
}
