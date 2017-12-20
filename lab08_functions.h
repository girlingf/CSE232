#ifndef functions_h
#define	functions_h

#include<string>
using std::string;
#include<vector>
using std::vector;
#include<utility>
using std::pair; using std::make_pair;
#include<map>
using std::map;

long collatz (long);
string pair_to_string (const pair<long, vector<long>>&);
void fill_vector (map<long, vector<long>>&, vector<long>&, long);

#endif	/* functions_h */
