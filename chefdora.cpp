#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n,m,y1,y2,x1,x2,ans=0;
    cin>>n>>m;int a[n][m];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)cin>>a[i][j];

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            int c=0;
            y1=y2=i;
            x1=x2=j;


            while( x1>=0 and x2<m and y1>=0 and y2<n and a[y1][j]==a[y2][j] and a[i][x1]==a[i][x2])
                c++,x1--,x2++,y1--,y2++;

            ans=ans+c;


        }
    cout<<ans<<"\n";


}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}
