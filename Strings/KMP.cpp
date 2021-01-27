#include<bits/stdc++.h>
using namespace std;


int main()
{
    string text,pat;cin>>text>>pat;

    int *lps=new int[pat.length()];
    lps[0]=0;

    int i=1;
    int len=0;

    while(i<pat.length())
    {
        if(pat[i]==pat[len])
        {
            len++;
            lps[i]=len;
            i++;
        }
        else
        {
            if(len!=0)
            {
                len=lps[len-1];
            }
            else
            {
                lps[i]=0;
                i++;
            }
            
        }
        
    }
//ptr on text
    int itr=0;
//ptr on pat
    int j=0;

    while(itr<text.length())
    {
        if(text[itr]==pat[j])
        {
            itr++;
            j++;

            
        }
        if(j==pat.length())
            {
                cout<<"Patern found at "<<itr-pat.length()<<endl;
                j=lps[j-1];
            }
        else if(i<text.length()&&text[itr]!=pat[j])
        {
            if(j!=0)
            {
                j=lps[j-1];
            }
            else
            {
                itr++;
            }
            
        }
    }
    
}