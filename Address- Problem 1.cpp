#include <bits/stdc++.h>
using namespace std;
typedef pair<string,int> ii;

string address_one,address_two;
map<string,pair<int,int> > m1,m2;
vector<ii> ans;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	getline(cin,address_one);
	getline(cin,address_two);
	//Normalize both addresses
	for (int i=0; i<address_one.size(); i++) address_one[i] = tolower(address_one[i]);
	for (int i=0; i<address_two.size(); i++) address_two[i] = tolower(address_two[i]);

	stringstream str1(address_one);
	stringstream str2(address_two);
	
	int dist = 0;
	string w;
	while (str1 >> w){
		m1[w].first++;
		m1[w].second = dist;
		dist++;
	}
	while (str2 >> w){
		m2[w].first++;
		m2[w].second = dist;
		dist++;
	}
	for (auto it = m1.begin(); it!=m1.end(); it++){
		if (it->second.first and m2[it->first].first){
			ans.push_back({it->first,abs(it->second.second-m2[it->first].second)});
		}
	}
	cout<<"There are "<<ans.size()<<" words in both addresses\n";
	for (int i=0; i<ans.size(); i++){
		cout<<i+1<<". "<<ans[i].first<<" contains in both addresses, the absolute distance between the two is "<<ans[i].second<<"\n";
	}
}