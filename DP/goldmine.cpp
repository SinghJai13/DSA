#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"Enter number of rows and columns :"<<endl;
    int n,m;
    cin>>n>>m;
    cout<<"Enter the elements of the array :"<<endl;
    int **gold=new int*[n];
    int **ans=new int*[n];
    for(int i=0;i<n;i++)
    {
        ans[i]=new int[m];

       gold[i]=new int[m];
        for(int j=0;j<m;j++)
        {
            cin>>gold[i][j];

            ans[i][j]=gold[i][j];
        }
    }
        for(int i=1;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int p1{0},p2{0},p3{0};

                if(i-1>=0)
                {
                    p1=ans[j][i-1];

                    if(j-1>=0)
                    {
                        p2=ans[j-1][i-1];
                    }
                    if(j+1<n)
                    {
                        p3=ans[j+1][i-1];
                    }

                }
                ans[j][i]+=max(p1,max(p2,p3));
            }
        }
        int max=ans[0][m-1];
        for(int i=0;i<n;i++)
        {
            if(max<ans[i][m-1])
            {
                max=ans[i][m-1];
            }
        }

        cout<<"ANs "<<max<<endl;

    }
    

