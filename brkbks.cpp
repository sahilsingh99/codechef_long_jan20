#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;

   while(t--)
   {
      int s,w1,w2,w3;
    cin>>s>>w1>>w2>>w3;

    int cnt=0;

    if(w1+w2+w3<=s)
    {
        cout<<1<<endl;
    }
    else if(w1+w2<=s || w3+w2<=s)
    {
        cout<<2<<endl;
    }
    else
    {
        cout<<3<<endl;
    }
    

   }
 
}
