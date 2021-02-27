//
//  main.cpp
//  Max Min
//
//  Created by Jaideep Singh on 28/02/21.
//

#include <bits/stdc++.h>
using namespace std;
pair<int,int> min_max(int *a,int st,int end)
{
    if(st>end)
    {
        pair<int,int> p;
        p.first=INT_MIN;
        p.second=INT_MAX;
        return p;
    }
    else if(st==end)
    {
        pair<int,int> p;
        p.first=a[st];
        p.second=a[st];
        return p;
    }
    else if(end-st==1)
    {
        pair<int,int> p;
        
        p.first=a[st]>a[end]?a[st]:a[end];
        
        p.second=a[st]<a[end]?a[st]:a[end];
        
        return p;
    }
    else
    {
        int mid=st+end;
        mid/=2;
        pair<int,int> p1=min_max(a,st,mid);
        pair<int,int> p2=min_max(a, mid+1, end);
        
        pair<int, int>p;
    
        p.first= p1.first>p2.first ? p1.first:p1.first ;
        
        p.second=p1.second<p2.second ?p1.second :p2.second;
        
        return p;
    }
}
int main() {
    // insert code here...
    int n;cin>>n;
    int *a=new int[n];
    
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    
    pair<int,int>p=min_max(a, 0, n-1);
    
    cout<<p.first<<" "<<p.second<<endl;
    
    
    
    return 0;
}
