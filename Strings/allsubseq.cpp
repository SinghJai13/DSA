//print all subsequences

#include<bits/stdc++.h>
using namespace std;
bool cmp(string a,string b)
{
    return a.length()<b.length();
}
int  printSubSeq(string str,vector<string> &ans)
{
    if(str.length()==0)
    {
        return 0;
    }
    else if(str.length()==0)
    {
        ans.push_back(str);
        return 1;   
    }
    else{
        vector<string>s;
        int sma=printSubSeq(str.substr(1),s);
        ans.push_back(str.substr(0,1));
        for(int i=0;i<sma;i++)
        {
            ans.push_back(s[i]);
            ans.push_back(str[0]+s[i]);
        }
       // sort(ans.begin(),ans.end(),cmp);
        return ans.size();
        

    }
}
int main()
{
    string str;cin>>str;

    vector<string>ans;
    int a=printSubSeq(str,ans);
    sort(ans.begin(),ans.end(),cmp);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<endl;
    }
}
