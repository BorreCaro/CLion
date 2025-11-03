#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	unordered_map<int, int> map;
	vector<int> answ;
	cin>>n;
	for(int i=0; i<n*10; i++){
		for(int j=0; j<5; j++){
			int x; cin>>x;
			if(++map[x]==2*n+1){
				answ.push_back(x);
			}  
		}
	
	sort(answ.begin(), answ.end());
	}
	if(answ.empty()) {
        cout << -1;
    } else {
        for(size_t i = 0; i < answ.size(); i++) {
            cout << answ[i];
            if (i + 1 < answ.size()) cout<<" ";
        }
    }
    cout<<endl;
	
}
