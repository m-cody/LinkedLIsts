/*I have neither given nor recieved any unauthurized aid on this work, nor have I presented someone else's work as my own.
Mary Cody
*/
#include "node.h"
#include <fstream>
#include <iostream>
#include <Windows.h>

using namespace std;
void loaddata(nodeType* &head); // Load the data into linked list, keep ascending order by ID
void Insert(nodeType* &head, nodeType nodeIn); // insert nodeIn into linked list and keep ascending order by ID
void traversal(nodeType* head); // visit every element in the list and print out some info
void clearlist(nodeType* &head); // delete the whole list (make it empty)
nodeType* searchList(nodeType* head, int searchID); // search the list by ID
void deleteNode(nodeType* &head, int IDin); //delete the node by ID
nodeType* GetMiddle(nodeType *head); // return the middle of list 
int main()
{
	int searchID, deleteID;
	char command;
	nodeType* item;
	nodeType nodeIn;
	//nodeType* head=new nodeType;
	nodeType* head = NULL;
	// Read from a file for other records
	loaddata(head);
	cout << "Linked list is created... ..." << endl << endl;


	// input command to call the function you want
	cout << "                      Functions you may use              " << endl;
	cout << "|---------------------------------------------------------------------|" << endl;
	cout << "|     'T'-- Traversal, 'M'--Middle of the list, 'I'-- Insert   |" << endl;
	cout << "|      'S'--Search , 'C'--Clear list, 'D'--Delete, 'E'--Exit   |" << endl;
	cout << "|---------------------------------------------------------------------|" << endl;
	cout << "Please input the command:";
	cin >> command;
	while (command != 'E')
	{
		switch (command){
		case 'T':
			traversal(head);
			break;
		case 'S':
			cout << "Please input the node ID to search: ";
			cin >> searchID;
			item = searchList(head, searchID);
			if (item != NULL)
				item->print();
			cout << endl;
			break;
		case 'M':
			item = GetMiddle(head);
			if (item == NULL)
				cout << "Middle item is empty ..." << endl;
			else
			{
				item->print();
				cout << endl;
			}
			break;
		case 'C':
			clearlist(head);
			cout << "The list is cleared!!" << endl;
			break;
		case 'I':
			cout << "First name: ";
			cin >> nodeIn.Fname;
			cout << "Last Name: ";
			cin >> nodeIn.Lname;
			cout << "ID: ";
			cin >> nodeIn.ID;
			Insert(head, nodeIn);
			break;
		case 'D':
			cout << "Please input the ID to delete: ";
			cin >> deleteID;
			deleteNode(head, deleteID);
			break;
		default:
			cout << "not a valid command, please input a new command!!" << endl;
			break;
		}
		cout << "Please input your command:";
		cin >> command;
	}

	return 0;
}

void loaddata(nodeType* &head)
// load the data from datafile, for each record, create an node and
// insert that node into the linked list
// Note: the data file name should be input by user, keep ID in ascending order

{
	cout << "Please input the file name." << endl;
	string fileName;
	cin >> fileName;
	cout << endl;
	ifstream input;
	input.open(fileName);
	if (input.fail())
	{
		cout << "The input file failed." << endl;
		system("pause");
		exit(1);
	}
	int empCount;
	nodeType *temp = new nodeType;
	nodeType *list = new nodeType;
	nodeType *prev = new nodeType;
	input >> empCount;
	for (int count = 0; count < empCount; count++)
	{
		temp = new nodeType();
		input >> temp->Fname >> temp->Lname >> temp->ID;
		temp->link = NULL;
		if (count == 0)
		{
			list = temp;
			head = temp;
		}
		else
		{
			for (int i = 0; i < count; i++)
			{
				if (temp->ID <= list->ID)
				{
					prev = list;
					temp->link = list;
					prev->link = temp;
					break;
				}
				else
				{
					list->link = temp;
				}
				list = list->link;
			}
		}
	}
	return;
}

void Insert(nodeType* &head, nodeType nodeIn)
// insert nodeIn into the linked list, keep ID in ascending order
{
	nodeType *list;
	list = head;
	nodeType *prev;
	prev = new nodeType;
	nodeType *temp;
	temp = new nodeType;
	temp = &nodeIn;
	while (list->link != NULL)
	{
		prev = list;
		if (temp->ID <= list->ID)
		{
			temp->link = list;
			prev->link = temp;
			break;
		}
		list = list->link;
	}
	return;
}

void traversal(nodeType* head)
// traveling the whole linked list from head to the end
// print out nthe data in each node on the screen
// If the list is empty, cout: The list is empty!
//Hint: you may call struct public member function: print
{
	nodeType *list;
	list = head;
	while (list->link != NULL)
	{
		(*list).print();
		list = list->link;
	}
	return;
}

void deleteNode(nodeType* &head, int IDin)
// If there is a node with ID = IDin, delete that node.
// If not, print out some error message.
{
	nodeType *list;
	list = head;
	nodeType *prev;
	prev = new nodeType;
	nodeType *temp;
	temp = new nodeType;
	while (list->link != NULL)
	{
		prev = list;
		if (IDin == list->ID)
		{
			temp = list;
			delete temp;
			temp = NULL;
			prev->link = list->link;
			break;
		}
		list = list->link;
	}
	return;
}

void clearlist(nodeType* &head)
// clear the whole list, free the dynamic memory 
// Hint: we use &head,  we want to pass by reference for head
// The reason is that we need to make head = NULL after you clear the list.
{
	nodeType *list;
	list = head;
	nodeType *prev;
	prev = new nodeType;
	nodeType *temp;
	temp = new nodeType;
	while (list->link != NULL)
	{
		prev = list;
		if (temp->ID <= list->ID)
		{
			temp->link = list;
			prev->link = temp;
			break;
		}
		list = list->link;
	}
	return;
}

nodeType* searchList(nodeType* head, int searchID)
// search the linked list for ID
// if there is a mathed node, return the adress of that node
// if not return NULL and print some information on the screen
{
	nodeType *list;
	list = new nodeType;
	while (list->link != NULL)
	{
		if (searchID <= list->ID)
		{
			return list->link;
		}
		list = list->link;
	}
	cout << "There was no record of an employee with ID number " << searchID << "found." << endl;
	return NULL;
}

nodeType* GetMiddle(nodeType *head)
//return the middle node of the list
// EX: if list contains 1 2 3 4 5, then return the node contains 3
//  If list contains 1 2 3 4, then return the node contains 3.
// If the list is empty, you return NULL.
{
	nodeType *list = head;
	int count = 0;
	while (list->link != NULL)
	{
		count++;
		list = list->link;
	}
	list = head;
	if (count == 0)
	{
		return NULL;
	}
	else
	{
		for (int i = 0; i < count / 2; i++)
		{
			list = list->link;
			if (i == count / 2)
			{
				return list;
			}
		}
	}
}