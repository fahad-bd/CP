/*
input and output:
3
a b 4
1 2 3 4
c d 2
1 2
d f 3
2 3 4
*/


#include<bits/stdc++.h>
using namespace std;
int main()

{
	map<pair<string,string>,vector<int>> m;
	int t;
	cin>>t;
	while(t--){
		string fn, sn;
		int n;
		cin>>fn>>sn>>n;
		for(int j=0;j<n;j++){
			int x;
			cin>>x;
			m[{fn,sn}].push_back(x);
		}
	}

	//output
	for(auto &i : m){
		auto &full_name = i.first;
		auto &number_list = i.second;

		cout<<full_name.first<<" "<<full_name.second<<endl;
		for(auto &number : number_list){
			cout<<number<<" ";
		}
		cout<<endl;
	}
	return 0;
}