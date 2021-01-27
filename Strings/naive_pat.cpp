#include<bits/stdc++.h>
using namespace std;


int main()
{
    string text,pat;cin>>text>>pat;


    for(int i=0;i<text.length()-pat.length()+1;i++)
    {
        if(text.substr(i,pat.length())==pat)
        {
            cout<<"Pattern found at "<<i<<endl;
        }

    }

    
}