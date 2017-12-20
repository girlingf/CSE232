#include <iostream>
#include <iomanip>
using std::setprecision;
#include <vector>
using std::cout;using std::cin;using std::endl;
using std::vector; using std::stoi;
#include<string>
using std::string;
#include<algorithm>
using std::remove; using std::set_intersection; using std::sort;
using std::transform; using std::count;
#include<sstream>
using std::stringstream; using std::istringstream;
#include<map>
using std::map;
#include<utility>
using std::pair; using std::make_pair;
#include<iterator>
using std::ostream_iterator;
#include<locale>
using std::locale; using std::tolower;
#include<fstream>
using std::ifstream;
#include<math.h> 
#include "proj08_functions.h"

/*
CSE232 Section 001
3/24/17
Project 08
*/

/*
The purpose of this function is to print a given node to a string. The string 
prints with the label first, followed by the x and y coordinate as an ordered
pair. The string is returned.
*/
string Node::to_string() const{

	string ret;
	
	ret = label + ":(" + std::to_string(x) + "," + std::to_string(y) + ")";
	
	return ret;
	
} //of to_string

/*
The purpose of this function is to calculate the distance between two nodes.
The distance is found using the euclidean distance formula. The function returns
the distance as a double.
*/
double Node::distance(const Node &n) const{
	double dist;
	
	dist = sqrt(pow(n.x-x,2)+pow(n.y-y,2));
	
	return dist;
	
} //of distance

/*
The purpose of this function is to determine if two nodes are equal or not. This
is determined by their label. If the labels are the same, the function returns
the boolean true. Otherwise, it returns the boolean false.
*/
bool Node::equal_nodes(const Node &n){

	if (n.label == label){
		return true;
	} //of if
	
	else{
		return false;
	} //of else
	
} //of equal_nodes

/*
This is the constructor for the Network structor. It creates the string, map, 
and vector needed to initialize a Network by reading each line of text from a 
given file.
*/
Network::Network (ifstream &in){
	
	while (!in.fail()){
	
		string str;
		int x, y;
		string nodelabel;
		
		getline(in, str, '\n');
		istringstream ss(str);
		ss >> x >> y >> nodelabel;
		
		if (nodelabel.length() > 0){
		
			Node n(x, y, nodelabel);
			nodes[nodelabel] = n;
			route.push_back(nodelabel);
			
		} // of if
	} //of while
} //of Network constructor

/*
The purpose of this function is to create a string of all of the nodes that are
in a network. The map in the network is iterated through and each nodes is
printed to a string and added the the returned string. The function returns the
string containing all nodes.
*/
string Network::to_string() const{

	string str;
	
	for (auto s : nodes){
	
		str.append(s.second.Node::to_string());
		str.append(", ");
		
	} //of for
	
	str = str.substr(0, str.length()-2);
	
	return str;
	
} //of to_string

/*
The purpose of this function is to determine if a node exists in the network. 
If the node is not found, an out of range error is thrown. If the node is found,
the function returns that node.
*/
Node Network::get_node(string s){

	Node get;
	map<string, Node>::iterator it;
	
	string str = "Node not found:" + s;
	
	if (nodes.find(s) == nodes.end()){
	
		throw std::out_of_range(str);
		
	} //of if
	
	else{
	
		it = nodes.find(s);
		get = it->second;
		
	} //of else
	
	return get;
	
} //of get_node

/*
The purpose of this function is to put a node into the network. As long as the 
node has a label of length > 1, it is placed into the network. If the node 
already exists, it replaces the old one. There is no return.
*/
void Network::put_node(Node n){

	if (n.label.length() > 0){
	
		nodes[n.label] = n;
		
	} //of if
} //of put_node

/*
The purpose of this function is to determine if a node is already present in the 
network. If it is present, the function returns the boolean true. Otherwise, it
returns the boolean false.
*/
bool Network::in_route(const Node &node){
	
	for (auto s : route){
	
		if (s == node.label){
			return true;
		} //of if
		
		else{
			return false;
		} //of else
	} //of for
	
	return false;
	
} //of in_route

/*
The purpose of this function is to determine the closest node to a given node in
the network. The map nodes is iterated through and the distance is calculated
for each node. If the distance is < the previous, it replaces the node that gets
returned. The lowest distance node is returned.
*/
Node Network::closest(Node &n){
	
	Node close;
	double differ = 1000000;
	
	for (auto s : nodes){
		if (n.distance(s.second) != 0){
			if (n.distance(s.second) < differ){
			
				differ = n.distance(s.second);
				close  = s.second;
				
			} //of if
		} //of if
		
	} //of for
	
	return close;
	
} //of closest

/*
The purpose of this function is to determine the total distance from start to
finish of the nodes in a network. The distance is placed in a string, followed
by the labels of all of the nodes present in the network. The function returns
the string.
*/
string Network::calculate_route(const Node &start, const Node &finish){

	string str;
	double dist;
	stringstream stream;

	dist = finish.distance(start);
	stream << std::fixed << setprecision(5) << dist;
	
	str = stream.str();
	str.append(": ");
	
	for (auto s : nodes){
	
		str.append(s.first);
		str.append(",");
		
	} //of for
	
	str = str.substr(0, str.length()-1);
	
	return str;
	
} //of calculate_route
