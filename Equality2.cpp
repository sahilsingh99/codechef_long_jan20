#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,q,l,r;
	cin>>n>>q;
	int a[n];
	for(int i=0;i<n;i++)cin>>a[i];
	while(q--)
	{
		cin>>l>>r;

		l--;r--;

		bool inc1=a[l]<a[l+1];
		bool inc2=a[r-1]<a[r];
		if((inc1 and inc2) or !(inc1 or inc2) )cout<<"NO\n";
		else
			cout<<"YES\n";


	}
}
