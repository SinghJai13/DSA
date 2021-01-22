#include<bits/stdc++.h>
using namespace std;
void rev(string &s)
{
    int i=0,j=s.size()-1;
        
        while(i<j)
        {
            swap(s[i],s[j]);
            i++;
            j--;
        }
}
int isPali(string S)
{
	    // Your code goes here
	    if(S.length()==0||S.length()==1)return 1;
	    
        int i=0;
	    
        int j=S.length()-1;
	    
        int flag=0;
	    
        while(i<j  )
	    {
	        if(S[i]==S[j])
	        {
	            i++;
	            j--;
	        }
	        else
	        {
	            flag=1;
	            break;
	        }
	    }
	    
        if(flag==1)return 0;
	    
        return 1;
}
int main()
{
    string str;cin>>str;
    //rev
    rev(str);
    cout<<"reverse of the str :"<<str<<endl;
    
    cout<<"whether string is palindrome or not :"<<isPali(str)<<endl;


}
