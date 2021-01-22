#include<bits/stdc++.h>
using namespace std;
bool rota(string s1,string s2)
{
    if(s1.length()!=s2.length())
    {
        return false;
    }
    else
    {
        for(int i=0;i<s1.length();i++)
        {
            s1=s1.substr(1)+s1[0];

            if(s1==s2)
            {
                return true;
            }
        }
        return false;
    }
    
}
int main()
{
    string s1,s2;cin>>s1>>s2;

    cout<<"Whether strings are rotations or not :"<<rota(s1,s2)<<endl;
    
}