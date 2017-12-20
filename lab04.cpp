#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>

/*
xir and fjg 7/2/2017
Lab 04
*/
using std::cin; using std::cout; using std::endl;
using std::string; using std::sort;

string abbreviate(string loc){
	string str = loc;
	
	sort(str.begin(), str.end());
	int i = 1;
	string new_str;
	new_str = str;
	
	while (str[i]){
	
		if (str.substr(i-1,1) == str.substr(i,1)){
			char a = str[i] + 1;
			new_str = str.substr(0,i-1);
			new_str.push_back(a);
			if (str[i+1]){
				new_str += str.substr(i+1);
			} //of if
			i = 1;
		} //of if
		else{
			i += 1;
		} //of else

	} //of while
	return new_str;
} //of abbreviate

long loc_to_dec(string loc){
	string abb = abbreviate(loc);
	string str = abb;
	long integer = 0;
	
	for (int i = 0; str[i]; i++){
		integer += pow(2,str[i] - 'a');
	} //of for
	
	return integer;
	
} //of loc_to_dec

string dec_to_loc(long dec){
	long integer = dec;
	string str;
	
	for (int i = 25; integer == 0; i--){
		if (integer/pow(2,i) == 1){
			str.push_back(static_cast<char>(i+97));
			integer -= pow(2,i);
		}
	} //of for
	return str;
} //of dec_to_loc

long add_loc(string loc1, string loc2){
	string str1 = loc1;
	string str2 = loc2;
	
	string str = str1 + str2;
	sort(str.begin(), str.end());
	
	string str_abb = abbreviate(str);
	
	long integer = loc_to_dec(str_abb);
	
	return integer;
} //of add_loc

int main(){
	string s1;
	int s2;
	
	cout << "Input a location string, then an integer." << endl;
	cin >> s1 >> s2;
	
	//cout << s1 << loc_to_dec(s1) << endl;
	//cout << s1 << abbreviate(s1) << endl;
	cout << s2 << dec_to_loc(s2) << endl;
	//cout << add_loc(s1,s1) << endl;
	
} //of main
