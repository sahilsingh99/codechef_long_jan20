#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll t;cin>>t;
    while(t--)
    {
        ll n;cin>>n;fflush(stdout);
        ll perfect=pow(10,n);//maximum value 
        ll sum=2*perfect;// value that we can handle 
        ll get,gap;
        cin>>get;fflush(stdout);
        gap=get;//first number given by chef
        sum+=get;
        cout<<sum<<endl;//ans given by me
        cin>>get;fflush(stdout);//second number given by chef
        gap+=get;
        cout<<sum-perfect-gap<<endl;//third number given by me to handle number two
        cin>>get;fflush(stdout);//fourth number given by chef
        cout<<perfect-get<<endl;//fifth number given by me to handle fourth number
        ll ans;
        cin>>ans;fflush(stdout);
        if(ans==-1)//condition if my ans is wrong
            break;
    }
    return 0;
}
