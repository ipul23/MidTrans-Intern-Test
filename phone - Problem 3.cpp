#include <bits/stdc++.h>
using namespace std;
string phone_number,normalized_phone;
//Assume input from file name "inputf.in"
/*
sample cases :
-
0
62
(null)
+628121383
62812373
081192844
+1 (804) 244-3470
*083831383838
+1408-888-4919
*/

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ifstream iFile("inputf.in");  
	while (true){
		getline(iFile,phone_number);
		normalized_phone.clear();
		// erase un-important character that fit in any test case
		if (phone_number != "(null)" and phone_number!= "-"){
			phone_number.erase(remove(phone_number.begin(),phone_number.end(),','),phone_number.end());
			phone_number.erase(remove(phone_number.begin(),phone_number.end(),'/'),phone_number.end());
			phone_number.erase(remove(phone_number.begin(),phone_number.end(),' '),phone_number.end());
			phone_number.erase(remove(phone_number.begin(),phone_number.end(),'('),phone_number.end());
			phone_number.erase(remove(phone_number.begin(),phone_number.end(),')'),phone_number.end());
			phone_number.erase(remove(phone_number.begin(),phone_number.end(),'?'),phone_number.end());
			phone_number.erase(remove(phone_number.begin(),phone_number.end(),'+'),phone_number.end());
			phone_number.erase(remove(phone_number.begin(),phone_number.end(),'*'),phone_number.end());
			phone_number.erase(remove(phone_number.begin(),phone_number.end(),'-'),phone_number.end());
		}
		if (phone_number[0] == '6' and phone_number[1] == '2' and phone_number[3] == '8'){
			//Special case
			normalized_phone = "08";
			for (int i=3; i<phone_number.length(); i++){
				normalized_phone+=phone_number[i];
			}
		} else
		if (phone_number[0] == '0' and phone_number[1] == '1' and phone_number[2] == '2'){
			//Special Case
			normalized_phone = "6221";
			for (int i=3; i<phone_number.length(); i++){
				normalized_phone+=phone_number[i];
			}
		} else
		if (phone_number[0] == '0' and phone_number[1] == '8'){
			//Special Case
			normalized_phone = "628";
			for (int i=2; i<phone_number.length(); i++){
				normalized_phone+=phone_number[i];
			}
		}
		else{
			normalized_phone = phone_number;
		}
		cout<<normalized_phone<<"\n";
    	if( iFile.eof() ) break;
	}
}