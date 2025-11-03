#include <bits/stdc++.h>
using namespace std;
int main(){
	
	int n,r,c;
	cin>>n; cin>>r; cin>>c;
	int dist = max((n+1)/2-r,(n+1)/2-c);
	int res = 100 - dist*10;
	cout<<res<<endl;
	
}
