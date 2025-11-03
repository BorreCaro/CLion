#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin>>n;
    vector<int> jumps(n);
    for(int i=0; i<n; i++){
    	cin>>jumps[i];
	}
    int j1 = jumps[0]/3, j3=jumps[n-1]/3;
    int j2 = jumps[n-2] - j3*2;
    
    cout<<j1<<" "<<j2<<" "<<j3<<endl;
    
    return 0;
}
