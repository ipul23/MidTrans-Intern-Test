#include <bits/stdc++.h>
using namespace std;
string string1,string2;
int ans = 0;
int main(){
	/*Sort the data, determine the last prefix that doesnt have the same character*/
	/*Complexity O(N log N)*/
	cin>>string1;
	cin>>string2;
	sort(string1.begin(),string1.end());
	sort(string2.begin(),string2.end());
	for (int i=0; i<max(string1.length(),string2.length()); i++){
		if (i > string1.length()-1){
			ans++;
		} else
		if (i > string2.length()-1){
			ans++;
		} else
		if (string1[i] != string2[i]){
			ans+=2;
		}
	}
	cout<<ans<<"\n";
}