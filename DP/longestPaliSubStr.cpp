// longest palindrmoic substring
#include<bits/stdc++.h>
using namespace std;

int pali_substring(string& str,string& ans)
{
    if(str.length()==0)
    {
        ans="";
        return 0;
    }
    if(str.length()==1)
    {
        ans=str;
        return 1;
    }
    else
    {
        int i=0;
        int j=str.length()-1;

        int flag=1;
        while(i<j)
        {
            if(str[i]!=str[j])
            {
                flag=0;
                break;
            }
            i++;
            j--;

        }
        
        string ans2=" ";



        string ans1=" ";
        string t1=str.substr(1);
        string t2=str.substr(0,str.length()-1);
        int sma1=pali_substring(t1,ans1);
        int sma2=pali_substring(t2,ans2);
        if(flag==0)
        {
            ans=sma1>sma2?ans1:ans2;

            return max(sma1,sma2);
        }
        else
        {
            ans=str;
            return str.length();
        }
    }
}

string dp_lon_pali_string(string str)
{
    if(str.length()<=1)
    {
        return str;
    }
    else
    {
        int n=str.length();
        bool **ans=new bool*[n];
        for(int i=0;i<n;i++)
        {
            ans[i]=new bool[n];
            for(int j=0;j<n;j++)
            {
                ans[i][j]=false;
            }
            ans[i][i]=true;
        }
        int long_st=0;
        int long_len=1;
        for(int i=0;i<n;i++)
        {
            if(i+1<n)
            {
                if(str[i]==str[i+1])
                {
                    long_len=2;
                    long_st=i;
                }
            }
        }

        for(int len=3;len<=n;len++)
        {
            for(int i=0;i<n-len+1;i++)
            {
                int j=i+len-1;
                if(str[i]==str[j]&& ans[i+1][j-1])
                {
                    ans[i][j]=true;
                    if(len>long_len)
                    {
                        long_len=len;
                        long_st=i;
                    }
                }
                
            }

        }
        return str.substr(long_st,long_len);
    }
}
int main()
{
    string str;cin>>str;

   string ans="";

    int a=pali_substring(str,ans);

    cout<<ans<<endl;

    string dp_ans=dp_lon_pali_string(str);

    cout<<dp_ans<<endl;
}