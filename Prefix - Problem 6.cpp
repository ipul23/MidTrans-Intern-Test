#include <bits/stdc++.h>
using namespace std;
string temp,s,operation;
int n;
map<string,int> m;
/*Put all possible prefix into map, then output the number of prefix in the map*/
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for (int i=0; i<n; i++){
		cin>>operation;
		if (operation == "add"){
			cin>>s;
			temp.clear();
			for (int j=0; j<s.length(); j++){
				temp+=s[j];
				m[temp]++;
			}
		} else{
			cin>>s;
			cout<<m[s]<<'\n';
		}
	}
}