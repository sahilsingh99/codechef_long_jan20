#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
#define gc getchar_unlocked
// scanner for fast input 
void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n,m;scanint(n);scanint(m);//use of scanner
        int a[n+1][m+1];
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {int k;scanint(k);a[i][j]=k;}
        if(n*m<9)
            cout<<n*m<<endl;
        else
        {
            long long int ans=n*m;
            for(int i=2;i<=n-1;i++)
            {
             	   for(int j=2;j<=m-1;j++)
                   {
                       int up=i-1,down=i+1,left=j-1,right=j+1;
                       while(up>0&&down<=n&&left>0&&right<=m)
                       {
                       		if(a[up][j]==a[down][j]&&a[i][left]==a[i][right])
                                ans++;
                           else break;
                           up--,down++,left--,right++;
                       }
                   }
            }
            cout<<ans<<endl;
        }
    }
}
