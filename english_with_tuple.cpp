#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define pb push_back
#define vll vector<ll>
#define sll set<ll>
#define mpll map<ll ,ll>
#define sortd(arr) sort(arr,arr+n,greater<ll>())
#define revs(str) reverse(str.begin(), str.end());
#define memset(arr) memset(arr,0,sizeof(arr));//array elements to 0
#define fr(i,a,b) for(ll i=a;i<=b;i++)
#define frr(i,a,b) for(ll i=a;i>=b;i--)
bool sortdesc(const tuple<ll, string,string>& a, 
      const tuple<ll, string,string>& b) 
{ 
  return (get<0>(a) > get<0>(b)); 
} 
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        vector<tuple<ll, string ,string> > vt;
        ll n;cin>>n;
        string s[n];
        bool vis[n]={false};vector<ll>v;
        map<string,ll> mp;
        fr(i,0,n-1)
        {cin>>s[i];
        mp[s[i]]++;
        }
        ll sum=0;
        vector<string> rem;
        for(auto x: mp)
        {
            
            if(x.second>=2)
            {
               string nw=x.first;
               ll t=(x.second)/2;
               if(x.second-(2*t)!=0)
               {
                   rem.pb(x.first);
               }
               sum+=pow(nw.length(),2)*t;
            }
            else
            rem.pb(x.first);
        }
        ll sz=rem.size();
        ll temp[sz];
        memset(temp);
        for(ll i=0;i<sz;i++)
        {
            ll pos=-1;
            for(ll j=0;j<sz;j++)
            {
                    string a=rem[i];
                    string b=rem[j];ll c=0;
                if(i!=j)
                {
                    ll l=0;
                    ll r1=a.length()-1;
                    ll r2=b.length()-1;
                    ll t=min(r1,r2);ll r=t;
                    while(l<=t && r>=0 && a[r1]==b[r2] && a[l]==b[l])
                    {
                        c++;
                        l++;r1--;r2--;r--;
                    }
                }
                if(c>0)
                vt.push_back(make_tuple(c,rem[i], rem[j]));
            }
        }

        sort(vt.begin(), vt.end(), sortdesc); 

        // for(int i=0;i<vt.size();i++)
        // {
        //     cout << (get<0>(vt[i])) << "\n";
        // }
        
        set<string >st;
        vll vnew;
        ll tim=sz/2;ll c=0;
        // cout << "init sum: " << sum << "\n";    
        for(auto i=0;i<vt.size();i++)
        {
            if(st.find(get<1>(vt[i]))==st.end() && st.find(get<2>(vt[i]))==st.end())
            {
            sum+=pow(get<0>(vt[i]),2);
            st.insert(get<1>(vt[i]));
            st.insert(get<2>(vt[i]));
            }
        }
        
        cout<<sum<<endl;
        
    }
        
    return 0;
}
