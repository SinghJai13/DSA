#include<bits/stdc++.h>

using namespace std;

bool valid_shuffle(string s1,string s2,string s)
{
    if(s1.size()+s2.size()!=s.size())
    {
        return false;
    }

    int i=0;
    int j=0;

    int itr=0;
    int flag=1;

    while(i<s1.length()&&j<s2.length()&&itr<s.length()&&flag)
    {
        if(s[itr]==s1[i])
        {
            i++;
            itr++;
        }
        else if(s[itr]==s2[j])
        {
            j++;
            itr++;
        }
        else
        {
            flag=0;
        }
    }

    if(flag==0)
    {
        return false;
    }
    else
    {
        if(i==s1.size())
        {
            if(s2.size()-j==s.size()-itr)
            {
                for(int k=j;k<s2.size()&&flag;k++)
                {
                    if(s2[k]==s[itr])
                    {
                        itr++;
                    }
                    else
                    {
                        flag=0;
                        return false;
                    }
                }
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            if(s1.size()-1==s.size()-itr)
            {
                for(int k=i;k<s1.size()&&flag;k++)
                {
                    if(s1[k]==s[itr])
                    {
                        itr++;
                    }
                    else
                    {
                        flag=0;
                        return false;
                    }
                }
                return true;
            }
            else
            {
                return false;
            }
        }
    }
}
int main()
{
    cout<<"enter the 2 sub strings :"<<endl;
    string s1,s2;

    cin>>s1>>s2;

    string s3;

    cout<<"Enter the proposed shuffle :"<<endl;
    cin>>s3;



    cout<<"Whether valid shuffle or not: "<<valid_shuffle(s1,s2,s3)<<endl;
}