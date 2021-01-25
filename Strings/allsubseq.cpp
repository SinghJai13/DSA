//all sub sequences
#include<bits/stdc++.h>
using namespace std;
set<string> subseq(string str)
{
    if(str.size()==0)
    {
        set<string> ans;
        return ans;
    }
    if(str.size()==1)
    {
        set<string> ans;
        ans.insert(str);
        return ans;
    }
    else
    {
        set<string> ans1=subseq(str.substr(1));
       set<string> ans;
        set<string>::iterator i;
        string temp=str.substr(0,1);
        ans.insert(temp);
        for(i=ans1.begin();i!=ans1.end();i++)
        {
            ans.insert(*i);
            ans.insert(temp+*i);
        }

        return ans;


    }
}
int main()
{
    string str; 
    cin>>str;
    set<string>ans =subseq(str);
    set<string>::iterator i;
    cout<<ans.size()<<endl;
    int max=INT_MIN;
    string a;
    for( i=ans.begin();i!=ans.end();i++)
    {
        string temp=string(*i);
        if(temp.length()>=max)
        {
            max=temp.length();
            a=temp;
            cout<<temp<<endl;
        }

       // cout<<*i<<" ";
    }
    cout<<a<<endl;
}