#include <string>
#include <iostream>
using namespace std;

struct nodeType{
	// public members of the node	
	string Fname; //First name
	string Lname; //Last name
	int ID; // ID number 
	nodeType *link; //pointer pointing to next node

	// we also define some public functions
	void print(); // print out the info for node
	nodeType(); // default constructor
};

void nodeType::print()
// public member function for nodeType struct
// print the info on the node as "Fname Lname, ID"
{
	cout << "(" << Fname << " " << Lname << ", " << ID << ")";
}

nodeType::nodeType()
// default constructor for nodeType struct
{
	Fname = "";
	Lname = "";
	ID = 0;
	link = NULL;
}



