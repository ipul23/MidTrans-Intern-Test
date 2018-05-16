#include <bits/stdc++.h>
using namespace std;

struct transaction_str{
	int id;
	string email,phone,card;
};

struct transaction_group{
	vector<int> id;
	vector<string> email,phone,card;
};

transaction_group ans[1000000];
transaction_str transaction[1000000];
bool f[1000000] = {0};
/* test case = 
transactions = [
	{id: 1, email: 'e1', phone: 'p1', card: 'c1'},
	{id: 2, email: 'e2', phone: 'p3', card: 'c2'},
	{id: 3, email: 'e1', phone: 'p3', card: 'c3'},
	{id: 4, email: 'e4', phone: 'p4', card: 'c4'},
	{id: 5, email: 'e2', phone: 'p4', card: 'c5'},
	{id: 6, email: 'e3', phone: 'p3', card: 'c1'},
	{id: 7, email: 'e5', phone: 'p7', card: 'c2'},
	{id: 8, email: 'e6', phone: 'p4', card: 'c5'},
]
*/
int main(){
	//Assume input from file name "inputf.in"
	ifstream iFile("inputf.in");  
	string s;
	int cnt = 0,idx = 0;
	while (true) {
    	getline(iFile,s);
    	//cout<<s<<"\n";
    	string w1,w2;
    	if (s == "transaction") continue;
    	//Parsing input
    	s.erase(remove(s.begin(),s.end(),','),s.end());
    	s.erase(remove(s.begin(),s.end(),'{'),s.end());
    	s.erase(remove(s.begin(),s.end(),'}'),s.end());
    	s.erase(remove(s.begin(),s.end(),'\''),s.end());
    	s.erase(remove(s.begin(),s.end(),':'),s.end());
    	s.erase(remove(s.begin(),s.end(),'('),s.end());
    	s.erase(remove(s.begin(),s.end(),')'),s.end());
    	s.erase(remove(s.begin(),s.end(),'='),s.end());
    	s.erase(remove(s.begin(),s.end(),'['),s.end());
    	s.erase(remove(s.begin(),s.end(),']'),s.end());
    	stringstream str(s);
    	//cout<<s<<"\n";
    	++cnt;
    	while (str >> w1 >> w2){
    		if (w1 == "id") transaction[cnt].id = stoi(w2);
    		//cout<<w1<<" "<<w1<<"\n";
    		if (w1 == "email") transaction[cnt].email = w2;
    		if (w1 == "phone") transaction[cnt].phone = w2;
    		if (w1 == "card") transaction[cnt].card = w2;
    	}
    	//cout<<s<<'\n';
    	if( iFile.eof() ) break;
	}
	for (int i=1; i<=cnt; i++){
		if (!f[i]){
			++idx;
			for (int j=i; j<=cnt; j++){
				if (!f[j] and (transaction[j].email == transaction[i].email or transaction[j].phone == transaction[i].phone or transaction[j].card == transaction[i].card)){
					f[j]  = true;
					ans[idx].id.push_back(transaction[j].id);
					ans[idx].email.push_back(transaction[j].email);
					ans[idx].phone.push_back(transaction[j].phone);
					ans[idx].card.push_back(transaction[j].card);
				}
			}
		}
	}
	for (int i=1; i<=idx; i++){
		cout<<"customer"<<i<<":\n";
		cout<<"transactions:[";
		for (int j=0; j<ans[i].id.size(); j++){
			if (j == 0) cout<<ans[i].id[j];
			else cout<<','<<ans[i].id[j];
		}
		cout<<"],\n";
		cout<<"email:[";
		for (int j=0; j<ans[i].email.size(); j++){
			if (j == 0) cout<<ans[i].email[j];
			else cout<<','<<ans[i].email[j];
		}
		cout<<"],\n";
		cout<<"phone:[";
		for (int j=0; j<ans[i].phone.size(); j++){
			if (j == 0) cout<<ans[i].phone[j];
			else cout<<','<<ans[i].phone[j];
		}
		cout<<"],\n";
		cout<<"cards:[";
		for (int j=0; j<ans[i].card.size(); j++){
			if (j == 0) cout<<ans[i].card[j];
			else cout<<','<<ans[i].card[j];
		}
		cout<<"]\n";
	}
}