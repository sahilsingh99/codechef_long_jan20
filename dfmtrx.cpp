#include <bits/stdc++.h>
using namespace std;
int main()
{
//fast input
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n==2)
        {
            cout << "Hooray\n";
            cout << "1 3\n";
            cout << "2 1\n";
        }
        else if (n%2==0)
        {
            int j,i,var;
            int a[n][n];
            int list[n-1];
            for(i=0;i<n-1;i++)
            {
                list[i] = i+1;
            }
            int index = 1;
            //filling first row
            for(i=1;i<n;i++)
                a[0][i] = list[i-1];
                
            for(i=1;i<n;i++)
            {
                var = index;
                a[i][n-1] = list[var];
                if (var!=n-2)
                    var ++;
                else
                    var = 0;
                for(j=i+1;j<n-1;j++)
                {
                    a[i][j] = list[var];
                    if (var!=n-2)
                        var ++;
                    else
                        var = 0;
                }
                if (index==n-3)
                    index = 0;
                else if(index==n-2)
                    index = 1;
                else
                    index += 2;
            }
		//filling diagonals
            for (i=0;i<n;i++)
            {
                for (j=0;j<i+1;j++)
                {
                    if (i==j)
                    {
                        a[i][j] = 2*n-1;
                    }
                    else
                        a[i][j] = a[j][i] -1 + n;
                }
            }
            cout << "Hooray\n";
            for (i=0;i<n;i++)
            {
                for (j=0;j<n;j++)
                    cout << a[i][j] << " ";
                cout << "\n";
            }
        }
        else if (n==1)
        {
            cout << "Hooray\n";
            cout << "1\n";
        }
        else
        {
            cout << "Boo\n";
        }
    }
    return 0;
}

