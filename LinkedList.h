/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LinkedList.h
 * Author: mrt
 *
 * Created on October 3, 2016, 12:11 PM
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include<iostream>
#include<string>
#include<fstream>

using namespace std;


class LinkedList


{
	private:

		struct Node
		{
			string line;
			Node *next;

		};

	 public:
		LinkedList(); //constructor
		~LinkedList(void); //deconstructor
		void Insert(int n, string i);// insert function
		void Delete(int n);  //delete function
		void SaveList();  //save content to file function
		void Help();  //reprints the menu options
		void Print(); //prints the whole file
		void InsertEnd(string line);
		void Quit();
		string Copy(int n);
		int Count();
        
	
	Node *Head;  //pointer to head node
	Node *Tail;  //pointer to tale node
};

#endif /* LINKEDLIST_H */

