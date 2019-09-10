#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
vector<int> prefix(string p,int n)
{   int i=1,j=0;
vector <int> lps(n);
lps[0]=0;
  while(i<n)
  { if(p[i]==p[j])
     {lps[i]=++j;
     i++;}
    else if(p[i]!=p[j])
    {
        if(j==0)
        {   lps[i]=0;
            i++;
        }
       else
        j=lps[j-1];
    }

  }
    return lps;

}


int main()
{
    string t,p;
    int i,j;
    cin>>t;
    cin>>p;
    vector<int> a=prefix(p,p.size());
    /*for(i=0;i<p.size();i++)
        cout<<a[i]<<" ";*/
    i=0,j=0;
    while(i<t.size())
    {
        if(t[i]==p[j])
        {   if(j==p.size()-1)
            {
                cout<<"Pattern found at "<<i-j<<endl;
                j=0;
            }
            else
            j++;i++;
        }
        else if(t[i]!=p[j])
        {   if(j==0)
            {
                i++;
            }
            else
            j=a[j-1];


    }
    }

    return 0;
}
