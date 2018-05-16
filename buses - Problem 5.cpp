#include <bits/stdc++.h>
using namespace std;
int times[10000] = {0};
int hour_st,minute_st,hour_fn,minute_fn;
string time_question;
string s,temp;
//Assume input from file name "inputf.in"

/*Bus 1 A 10:00 D 10:05
Bus 2 A 10:05 D 10:15
Bus 3 A 10:05 D 10:30
Bus 4 A 09:00 D 10:05
Bus 5 A 08:05 D 10:45
Bus 6 A 07:05 D 13:30
Bus 7 A 10:00 D 10:05
Bus 8 A 10:05 D 10:15
Bus 9 A 10:05 D 10:30
Bus 10 A 09:00 D 10:05
Bus 11 A 11:05 D 12:45
Bus 12 A 07:05 D 13:40 // test-cases
10:10 // question minute-x
*/

/*
-Assume time is Inclusive
-Big O = O(n) precompute the data, O(1) answer question
-count the number of buses at xx::yy time in format hour*100+minutes, this is work because 
the number of minutes wont exceec 60 ( < 100). 
*/

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ifstream iFile("inputf.in");
	while (true) {
    	getline(iFile,s);
    	if (s[0]!='B') break;
    	stringstream str(s);
   		string w1,w2;
    	while (str >> w1 >> w2){
			if (w1 == "A"){
				temp.clear();
				temp+=w2[0];
				temp+=w2[1];
				hour_st = stoi(temp);
				temp.clear();
				temp+=w2[3];
				temp+=w2[4];
				minute_st = stoi(temp);
				//cout<<temp<<" "<<w2<<"\n";
			}
			if (w1 == "D"){
				temp.clear();
				temp+=w2[0];
				temp+=w2[1];
				hour_fn = stoi(temp);
				temp.clear();
				temp+=w2[3];
				temp+=w2[4];
				minute_fn = stoi(temp);	
			}	
    	}
    	while (true){
				times[hour_st*100+minute_st]++;
				//cout<<hour_st<<" "<<minute_st<<"\n";
				++minute_st;
				if (minute_st == 60){
					minute_st = 0;
					++hour_st;
				}
				if (minute_st == minute_fn and hour_st == hour_fn){
					times[hour_st*100+minute_st]++;
					break;
				}
		}
		//cout<<minute_st<<" "<<minute_fn<<" "<<hour_st<<" "<<hour_fn<<"\n";	    
    	if( iFile.eof() ) break;
	}
	temp.clear();
	temp+=s[0];
	temp+=s[1];
	int min = stoi(temp);
	temp.clear();
	temp+=s[3];
	temp+=s[4];
	int hour = stoi(temp);
	//cout<<hour<<" "<<min<<"\n";
	cout<<times[hour*100 + min]<<"\n";
}