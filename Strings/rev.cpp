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
int main()
{
    string str;cin>>str;
    //rev
    rev(str);
    cout<<str<<endl;


}