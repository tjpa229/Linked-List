// implementation of linked list
// author: Tirth Patel
// cs 216
#include<iostream>
#include<string>
#include<fstream>
#include"LinkedList.h"

using namespace std;


LinkedList::LinkedList() //default constructor
{
	Head = new Node();
	Head->next = NULL;	
}
void LinkedList::Insert(int n, string i)   //this function adds to the list at any position

{
	

	
	
	Node* prev = new Node;  //we make two new nodes 
	Node* curr = new Node;   //two nodes will help us break a link while maintaining it with another node
	Node* newNode = new Node;
	newNode -> line = i;
	int tempPos = 0;
	curr = Head;
	if(Head != NULL) 
	{
		while(curr->next != NULL && tempPos != n)
		{
			prev = curr;
        		curr = curr->next;
        		tempPos++;
		}
		prev->next = newNode;
        	newNode->next = curr;
        	cout <<"Your input has been added!"<< endl;
	}
}

void LinkedList::Delete(int n)  //this function deletes a node from the linkedlist
{
	Node* temp1 = Head;  //temporary node
	temp1 = temp1->next;
	int i;
	if (n == 1)
	{
		Head = temp1->next;
		delete temp1;    
		return;
	}
	
	for (i = n-2; i <  n-1 ; i++)
	{
		
		Node* temp2 = temp1->next;
		temp1->next = temp2->next;
		delete temp2;
	}

	/*
	if (Head!=NULL)
	{
		if(Head==Tail && n == Head->line)
		{
			delete Head;
			Head = Tail = NULL;
		}
		else if(n == head
	}
	*/
}

void LinkedList::Print()   //this function prints out the whole list
{
	Node* temp = Head;  //temp node is created here
	 
	for(int counter=0 ; temp != NULL ; counter++) //checking if list is empty
	{
		
		cout << counter<<">"<< temp->line << endl;   //printing stuff out
		temp = temp->next;
		
	}
}

void LinkedList::Help()   //this function will display menu options again
{
	cout << "To insert text at the end of the file type I followed by the text" << endl;
	cout << "To insert text at a certain line, type I followed by a space and the line number" << endl;
	cout << "To delete a line type D followed by a space and the line number" << endl;
	cout << "To print all the lines type L and press enter" << endl;
	cout << "To save the current content type S and press enter" << endl;
	cout << "To display these options type H and press enter" << endl;
	cout << "To copy a line into clipboard, type 'C' followed by a space and the line number."<<endl;
	cout << "To paste a line, type 'P' followed by a space and the line number."<<endl;
 	cout <<	"A text line which has been copied into clipboard recently is the line to be pasted"<<endl;
	cout << "To Undo, type 'U' and press enter."<<endl;
	cout << "To quit press Q and press enter" << endl;
	
}

void LinkedList::SaveList() //this function will overwrite the linked list to the file
{
	
	
}

LinkedList::~LinkedList() //destructor
{

}

void LinkedList::InsertEnd(string data) //we use this function at the start to insert each 
{
	
	Node* temp = new Node;    //a temp node is created here
	temp->line = data;
	temp->next = NULL;

	Node *ptr = Head;

	if (Head == NULL)       //checking if the list is empty.
	{
		Head = temp;
		return;
	}
	while (ptr->next != NULL) 
	{
		ptr = ptr->next; //to find the last element
	} 
	ptr->next = temp;
}


void LinkedList::Quit()
{
	cout<<"Do you want to save the change? (Y-yes N-no)"<<endl;
	string choice;
	cin>>choice;
	cout<<"Thank you for using myEditor."<<endl;

}




string LinkedList::Copy(int n) //this function will help us copy the line that the user wants
	
{
	string str;
	Node* temp3 = Head;
	int count = 0;
	while(temp3 != NULL)   //traversing through the list here
	{
		if (count == n)
		
		{
			
			str = temp3->line;
			
		}
		count++;
		temp3 = temp3->next;	
	}
	return str;   //returning the copied string
	

}


int LinkedList::Count()  //this function will help us calculate the total number of lines, we will use this function in copy/paste
{
	int count = 0;  //counter int
	Node* temp4  = Head;   //creating a temp node
	while(temp4 != NULL)
	{
		count++;		
		temp4 = temp4->next;
	}
	return count;
}


