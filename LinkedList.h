#include <iostream>
using namespace std;

class TwoDimBinaryTree;

struct Rectangle {
	int Top; // y coordinate of upper edge 
	int Left; // x coordinate of left edge 
	int Bottom; // y coordinate of bottom edge 
	int Right; // x coordinate of right edge
	Rectangle * next;
};

class myList {
private:
	Rectangle *head, *tail;

public:
	friend class TwoDimBinaryTree; //for the tree class can access list class' functions
	myList() //constructor
	{
		head = NULL;
		tail = NULL;
	}
	
	~myList(); //destructor of list
	void addNode(int top, int bot, int right, int left); //adding node
	void findRectangle(int x, int y, myList &storage, int &count); //finding the rectangles
	void displayList(); //displaying the list
};


