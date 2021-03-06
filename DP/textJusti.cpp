#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"Enter the number of strings :"<<endl;
    int n;cin>>n;
    vector<string>v;

    for(int i=0;i<n;i++)
    {
        string temp;
        cin>>temp;
        v.push_back(temp);
    }

    cout<<"Enter the maximum width of the line :"<<endl;
    int k;cin>>k;

    int num_lines=0;
    int cur_space_left=0;


    int empty_space=0;
    vector<string>ans;
    string temp="";
    for(int i=0;i<v.size();i++)
    {
        int wordSize=v[i].length();
        cout<<v[i]<<" ";
        if(cur_space_left>=wordSize+1)
        {
            cur_space_left-=wordSize+1;
            
            temp+=" "+v[i];
            continue;
        }
        else
        {
            if(temp!="")
            {
              ans.push_back(temp);
            }
            temp="";

            empty_space+=cur_space_left;

            cur_space_left=k;
            num_lines++;

            cur_space_left-=v[i].length();
            temp+=v[i];

        }
    }
    ans.push_back(temp);
    empty_space+=k-temp.length();

    cout<<"Total Empty spaces : "<<empty_space<<endl;
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<endl;
    }
    cout<<endl;

}
