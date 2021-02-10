#include<bits/stdc++.h>
using namespace std;

bool valid(string s1,string s2,string s3)
{
    if(s2.size()+s1.size()!=s3.size())
    {
        return false;
    }
    if(s1.size()==0 && s2.size()==0 &&s3.size()==0)
    {
        return true;
    }
    if(s1.size()==0&&s2.size()!=0)
    {
        if(s2[0]==s3[0])
        {
            return valid(s1,s2.substr(1),s3.substr(1));
        }
        else
        {
            return false;
        }
        
    }
    else if(s2.size()==0 &&s1.size()!=0)
    {
        if(s1[0]==s3[0])
        {
                return valid(s1.substr(1),s2,s3.substr(1));
        }
        return false;
    }
    else
    {
        bool b1{false} ,b2{false};
        if(s1[0]==s3[0])
        {
            b1=valid(s1.substr(1),s2,s3.substr(1));
        }
        if(s2[0]==s3[0])
        {
            b2=valid(s1,s2.substr(1),s3.substr(1));
        }
        return b1||b2;
        
    }
    
    
}

bool dp_valid(string A, string B, string C) 
{
    int n1=A.length();
    int n2=B.length();
    if(n1+n2!=C.size())
    {
        return false;
    }
    int ans[A.length()+1][B.length()+1];
    
   
    memset(ans,0,sizeof(ans));
    
    ans[0][0]=1;
    
    for(int i=1;i<=n2;i++)
    {
        if(B[i-1]==C[i-1])
        {
            ans[0][i]=ans[0][i-1];
        }
    }
    for(int i=1;i<=n1;i++)
    {
        if(A[i-1]==C[i-1])
        {
            ans[i][0]=ans[i-1][0];
        }
    }
    
    for(int i=1;i<=n1;i++)
    {
        for(int j=1;j<=n2;j++)
        {
            if(A[i-1]==C[i+j-1]  &&B[j-1]==C[i+j-1])
            {
                ans[i][j]=ans[i][j-1]||ans[i-1][j];
            }
            else if(A[i-1]==C[j+i-1])
            {
                ans[i][j]=ans[i-1][j];
            }
            else if(B[j-1]==C[j+i-1])
            {
                ans[i][j]=ans[i][j-1];
            }
        }
    }
    
    return ans[n1][n2];
    
}
int main()
{
    cout<<"Enter strings A , B and C :"<<endl;
    string s1,s2,s3;
    cin>>s1>>s2>>s3;


    cout<<valid(s1,s2,s3)<<endl;
    cout<<dp_valid(s1,s2,s3)<<endl;
}