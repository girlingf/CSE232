#include<iostream>
using std::cout; using std::cin; using std::endl; using std::boolalpha;
#include<string>
using std::string; using std::stoi; using std::to_string;
#include<sstream>
using std::ostringstream; using std::istringstream;
#include<iterator>
using std::distance; using std::back_inserter;
#include<algorithm>
using std::transform;
#include<cctype>
#include<vector>
using std::vector;

/*
CSE232 Section 001
2/26/17
Project 05
*/


/*
The purpose of this function is to make all of the input string's letters
lowercase, and remove any non-alpha characters, as well as spaces. It returns
the modified string.
*/
string lower_and_strip(string s){

	string str;
	
	for (int i = 0; s[i]; ++i){
		if (isalpha(s[i])){
			int c = s[i];
			putchar (tolower(c));
		} //of if
	} //of for

	return str;
} //of lower_and_strip

/*
The purpose of this function is to split a string at every space and place
each item into a vector. The function returns nothing because it takes a 
reference vector that is changed in the function is it defined in.
*/
void split(string &s, vector<string> &v, char delim = ' '){
	string::size_type start = 0;
	v.clear();
	
	auto pos = s.find(delim, start);
	
	while (pos != string::npos){
		v.push_back(s.substr(start, pos - start));
		start = pos + 1;
		pos = s.find(delim, start);
	} //of while
	if (start != s.size())
		v.push_back(s.substr(start));
} //of split

/*
The purpose of this function is to take a character and change it into a number
based on a given starting index of a given key. The function returns an integer
that represents the input character.
*/
int return_encoded_char(string key, string::size_type &start, char C){
	
	int distance;
	
	if (isalpha(C)){
		if (key.find(C)){
			distance = key.find(C,start);
		
			if (key.find(C, start) > key.size()+1 && isalpha(C)){
				int temp = key.size() - start;
				start = key.find(C);
				distance = temp + key.find(C);
			} //of if
			else
				start = distance;
		} //of if

		else{
			distance = key.size() + 1;
			start = 0;
		} //of else
	} //of if
	
	else{
		distance = key.size() + 1;
		start = 0;
	} //of else
	return distance;
} //of return_encoded_char

/*
The purpose of this function is to encode an input string. The function calls 
the lower_and_strip function to remove unwanted characters, then calls the
return_encoded_char function for each character in the altered string to convert
the whole string into numbers. It returns the string of numbers.
*/
string encode(string message, string key){

	string str = lower_and_strip(message);
	string encoded = "";
	int x;
	string::size_type start = 0;
	string result;
	ostringstream convert;
	cout << str << endl;
	
	for (unsigned int i = 0; i <= str.length(); ++i){
		char b = str[i];
		x = return_encoded_char(key, start, b);
		cout << x << endl;
		convert << x;
		result = convert.str();
		encoded += result + " ";
		result = "";

	} //of for
	
	return encoded;
} //of encode

/*
The purpose of this function is to take a number and change it into a character
based on a given starting index of a given key. The function returns a character
that represents the input integer.
*/
char return_decoded_char(string key, string::size_type &start, int num){

	char decoded;
	int count = num + start;
	int check = key.size();

	if (num < check+1){
		if (count > check){
			if (count > check){
				count = count - check;
				decoded = key[count];
				start = key.find(decoded);
			} //of if
			else{
				count = count - check;
				decoded = key[count+start];
				start = key.find(decoded);
			} //of else
		} //of if
		else{
			decoded = key[num+start];
			start = key.find(decoded);
		} //of else
	} //of if
	else{
		decoded = '_';
		start = 0;
	} //of else
		
	return decoded;
} //of return_decoded_char

/*
The purpose of this function is to decode an input string. The function calls
the return_decoded_char function for each number in the altered string to
convert the whole string into characters. It returns the string of characters.
*/
string decode(string encoded_text, string key){

	char C;
	string::size_type start = 0;
	vector<string> v;
	string s = encoded_text;
	char delim = ' ';
	string decoder = "";
	
	split(s, v, delim);
	
	for (unsigned int i = 0; i < v.size(); ++i){
		int x = stoi(v[i]);
		C = return_decoded_char(key, start, x);
		decoder += C;
	} //of for	
	
	return decoder;
} //of decode

int main (){
  cout << boolalpha;

  int test_case;
  cin >> test_case;

  switch (test_case){

  case 1 : {
    string line;
    cin.ignore(20, '\n');
    getline(cin, line);
    cout << lower_and_strip(line) << endl;
    break;
  } // of case 1

  case 2 : {
    string key;
    char C;
    int num;
    string::size_type start;
    cin.ignore(20, '\n');
    getline(cin, key);
    cin >> C;
    cin >> start;
    num = return_encoded_char (key, start, C);
    cout << num << " " << start << endl;
    break;
  } // of case 2

  case 3 : {
    string key, line;
    string::size_type start=0;
    cin.ignore(20, '\n');
    getline(cin, key);
    getline(cin, line);
    cout << encode(line, key) << endl;
    break;
  } // of case 3   

  case 4 : {
    int num;    
    string key;
    char C;
    string::size_type start;
    cin.ignore(20, '\n');
    getline(cin, key);
    cin >> num;
    cin >> start;
    C = return_decoded_char (key, start, num);
    cout << C << " "<<start << endl;
    break;
  } // of case 4

  case 5 : {
    string key, line;
    string::size_type start=0;    
    cin.ignore(20, '\n');
    getline(cin, key);
    getline(cin, line);
    cout << decode(line, key) << endl;
    break;
  } // of case 5
    
  } // of switch

} // of main
