#include<bits/stdc++.h>
using namespace std;
void combo(vector<vector<string> >v,vector<string>& output,string &out,int m)
{
    if(m>=v.size())
    {
        return;
    }
    if(m==v.size()-1)
    {
        for(int i=0;i<v[m].size();i++)
        {
            output.push_back(out+" "+v[m][i]);
        }
        return ;
    }
    else
    {
        for(int i=0;i<v[m].size();i++)
        {
            string t=out+" " +v[m][i];
            combo(v,output,t,m+1);
        }
    }
}
int main()
{
    vector<vector<string> >v;
    
    vector<string> output;
    cout<<"Enter the number of distinct vector  string-;"<<endl;
    int n;cin>>n;

    for(int i=0;i<n;i++)
    {
        cout<<"Enter the number of strings for the "<<i+1<<"th vector "<<endl;
        
        int m;cin>>m;
        
        vector<string>temp;
        for(int j=0;j<m;j++)
        {
            
            string str;
            cin>>str;
            temp.push_back(str);
        }
        v.push_back(temp);
    }
    string temp;
    combo(v,output,temp,0);
    for(int i=0;i<output.size();i++)
    {
        cout<<output[i]<<endl;
    }

}