#include<bits/stdc++.h>

using namespace std;
//recursive
int lcs_recursive(string s1,string s2,string &result)
{
    if(s1.length()==0||s2.length()==0)
    {
        return 0;
    }
    else
    {
        if(s1[0]==s2[0])
        {
            result=result+s1[0];
            return 1+lcs_recursive(s1.substr(1),s2.substr(1),result);
        }
        else
        {
            string res1,res2;
            int a=lcs_recursive(s1,s2.substr(1),res1);
            int b=lcs_recursive(s1.substr(1),s2,res2);



            if(a>b)
            {
                result=result+res1;
                return a;
            }
            else
            {
                 result=result+res2;
                return b;
            }
            
        }
    }
}

int main()
{
    string s1,s2;cin>>s1>>s2;
    string result;

    cout<<"RECURSIVE SOLUTION:-->"<<endl;
    cout<<lcs_recursive(s1,s2,result)<<endl;

    cout<<result<<endl<<"---------------"<<endl;

    int **a=new int*[s1.length()+1];

    for(int i=0;i<s1.length()+1;i++)
    {
        a[i]=new int[s2.length()+1];

        for(int j=0;j<s2.length()+1;j++)
        {
           
            
                a[i][j]=0;
            
        }
    }

    cout<<"DP "<<endl;
    

    for(int i=1;i<s1.length()+1;i++)
    {
        for(int j=1;j<s2.length()+1;j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                a[i][j]=1+a[i-1][j-1];
            }
            else
            {
                a[i][j]=max(a[i][j-1],a[i-1][j]);
            }
            
        }
    }


    cout<<a[s1.length()][s2.length()]<<endl;
    //cout<<result<<endl<<"---------------"<<endl;

for(int i=0;i<s1.length()+1;i++)
    {
        for(int j=0;j<s2.length()+1;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

}