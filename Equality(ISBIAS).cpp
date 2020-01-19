#include <iostream>
using namespace std;
int main() {
	    long long int n,q,i;
	    cin>>n>>q;
	    long long int a[n];
	    for(i=0;i<n;i++)
	    cin>>a[i];
	    while(q--)
	    {
	        long long int l,r;
	        cin>>l>>r;
	        if((a[l-1]>a[l]&&a[r-1]>a[r-2])||((a[l-1]<a[l]&&a[r-1]<a[r-2])))
	        cout<<"YES"<<endl;
	        else
	        cout<<"NO"<<endl;
	    }
	return 0;
}
