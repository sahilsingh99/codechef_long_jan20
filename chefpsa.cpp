#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define ll long long
#define f first
#define s second
//ll mod=1e9+7;
#define pb push_back
const int mod=1e9+7;
const int MAX=1e5+10;
#define gc getchar_unlocked
//scanner for fast input
void scanint(ll &x)
{
    register ll c = gc();
    x = 0;
    ll neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}
//power function with modulo
ll power(ll x, ll y) 
{ 
    if (y == 0) 
        return 1; 
    ll p = power(x, y/2) % mod; 
    p = (p * p) % mod; 
  
    return (y%2 == 0)? p : (x * p) % mod; 
} 
ll fact[MAX];//array for storing factorial
ll infact[MAX];//array for stroring inverse of factorial
ll inverse(ll i) {
    return power(i,mod-2);
}
//function for calclating factorial and inverse of factorial
void cal()
{
    fact[0]=1;
	fact[1]=1;
	infact[1]=1;
	infact[0]=1;
    for(ll i=2 ; i <= 100000 ; i++)
    {
        infact[i]=(infact[i-1]*inverse(i))%mod;
        fact[i]=(fact[i-1]*i)%mod;
    }
}
int main()
{
    int t;
    cal();
    cin>>t;
    while(t--)
    {
		ll n;scanint(n);
        if(n==1)
        {
            ll xx,yy;
            scanint(xx);scanint(yy);//use of scanner
            if(xx==yy) printf("1\n");
            else  printf("0\n");
        }
        else{
        ll a[2*n],count=1,sum=0,same=0;
            map<ll,ll>Hash;//count occurance of each element using maps(stl)
            map<pair<ll,ll>,ll>mp;//counting pairs using maps(stl)
            for(ll i=0;i<2*n;i++)
            {
                scanint(a[i]);
                Hash[a[i]]++;
                sum=sum+a[i];
            }
		//if sum of sequence is not integer
            if((sum%(n+1))!=0)
                 printf("0\n");
            else{
            sum=sum/(n+1);
            if(Hash[sum]<2)
               printf("0\n");
            else
            {
                Hash[sum]-=2;int flag=0;ll same=0;
		//for loop for each value of Hash
                for(auto it:Hash)
                {
                    pair<ll,ll>pp;
                    if(it.s!=0)
                    {
                        //cout<<"hash1 "<<it.f;
                        //cout<<" hash2 "<<it.s<<endl;
                        ll fi=it.f;
                       ll se=sum-fi;
                        if(Hash[se]==0)
                        {flag=1;break;}
                        else
                        {
                            if(fi==se)
                                same+=it.s;
                            if(fi>se)
                            pp.f=se,pp.s=fi;
                            else
                            pp.f=fi,pp.s=se;
                            //cout<<" pairs "<<pp.f<<" "<<pp.s<<endl;
                            mp[pp]+=it.s;
                        }
                    }
                }
                if(flag==1)
                    printf("0\n");
                else{
                    ll ans=fact[n-1];
                    //cout<<"same"<<same/2<<endl;
                    ans=(ans*power(2,n-1-same/2))%mod;//cout<<"pow"<<ans<<endl;
                    for(auto all:mp)
                    {
                        //cout<<"all"<<all.s<<endl;
                        ans=(ans*infact[(all.s)/2])%mod;
                    }
                printf("%lld\n",ans);}
            }
        }}
    }
	return 0;
}
