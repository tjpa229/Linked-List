// Author: Tirth Patel
// course: CS 216
// Instructor: Dr. Yi Pike
// Purpose: the purpose of this program is to build a simple line editor
// the line editor is built upon a linked list, with each node of the linked list containing a line
// 
// Educational purpose: to understand the concept of nodes, linkedlists, etc and to use object orientated programming to build a linkedlist
// the declaration of my linked list is in linkedlist.h  and the implementation is in linkedList.cpp
// the functions insert and delete may have a few bugs as i was having trouble with dealing with user input
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "LinkedList.h"

using namespace std;


int main(int argc, char** argv) 
{
	ifstream in_file;
     // 
	// Check whether the user types the command correctly
	// 
	if (argc != 2)		// if the number of command line arguments is not two
	{
		cout << "Invalid command!" << endl;
		cout << "Usage: " << argv[0] << " filename" << endl;
		return 1;
        }
        
        in_file.open(argv[1]);
        if (!in_file.good())
        {
            cout << "Failure in opening file: " << argv[1] << endl;	
            return 2;
        }

	// 
	// Read the original file content if the file exists
	// 
	fstream in_file1;
	in_file1.open(argv[1], ios::in);		// open the specified file for reading. 
                                                // file name is provided by command line argument argv[1]
	LinkedList myList;
	LinkedList backup;
	if (!in_file1.fail())			// if the file exits and is opened successfully
        {
		string str;
		
		
		for(int pos=0; !in_file1.eof(); pos++)			// read every line from the file until the end
		{
			getline(in_file1, str);
			myList.InsertEnd(str);
			
			
		}
	}
	in_file1.close();  //close the file
	
	string option;  //this will be the menu option the user chooses 
		
		
		// displaying menu options below
	cout <<"Welcome to my text editor"<<endl;
	cout <<"To insert text at the end of the file type I followed by the text" <<endl;
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
        cout <<""<<endl;
	string input; 
	cin >>option;
	string str;
	bool flag = true;
	while (flag = true)
        {
          
           	backup = myList;
		if(option == "I")
            	{
			backup = myList;
			int n;
		
			cin>>n;
			if(n>0)
			{
				cout<<"Enter your input"<<endl;
				cin>>input;
				
				myList.Insert(n, input);
				
			}
		else
		{
			cout<<"Invalid line number"<<endl;
		}
               
		}
		else if(option == "S")
            	{
			

	    	}
		
                
            
		else if(option == "H")
            	{
		
                	myList.Help();
            	}
		else if(option == "L")
            	{
		
                	myList.Print();
            	}
		
		else if(option == "D")
	    	{
			int d;
			cin>>d;
			if(d>0)
			{
				myList.Delete(d);
			}
	    		else
			{
				cout<<"Invalid line number"<<endl;
			}
	  	}
		
		else if(option == "C")
		{
			
			int n;
			cin>>n;
			if(n>myList.Count()|| n<0)
			{
				cout<<"Cant copy a non existent line!"<<endl;
			}
			else
			{	
				str = myList.Copy(n);
				cout<<"Line has been copied to clipboard!"<<endl;
			}
		}
		else if(option == "P")
		{
			int n;
			cin>>n;
			if(str=="")
			{
				cout<<"Clipboard is empty!"<<endl;
			}
			else
			{
				myList.Insert(n, str);
				cout<<"The line has been pasted!"<<endl;
			}
		}
		else if(option == "Q")
	   	{
			myList.Quit();
	   	}			
				
	  	else if(option == "U")
		{
			myList = backup;
		
		}

		cin >> option;
		
        }
    return 0;
}
