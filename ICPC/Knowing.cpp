#include <bits/stdc++.h>
using namespace std;
int main(){
	int h, m, correct;
	cin>>h;
	cin>>m;
	correct = (h*12)%360;
	cout<<((correct==m) ? "yes": "no")<<endl;
}
