#include "LinkedList.h"

myList::~myList() //destructor
{
	Rectangle * tmp = head; //new pointer for deleting list
	while (tmp != NULL)  
	{
		tmp = head->next;  
		delete head;      
		head = tmp;
	}
}

void myList::displayList() //in main.cpp,if given x,y coordinates are in any rectangles, use this for displaying the coordinates of that rectangle.
{
	Rectangle * tmp = head;
	while (tmp != NULL)
	{
		cout << tmp->Top << " " << tmp->Left << " " << tmp->Bottom << " " << tmp->Right << endl; //print coordinates
		tmp = tmp->next;
	}
}

void myList::addNode(int top, int bot, int right, int left) //for adding a new node to the binary tree
{
	Rectangle *tmp = new Rectangle; //creating a new rectangle
	tmp->Top = top;
	tmp->Bottom = bot;
	tmp->Right = right;
	tmp->Left = left;
	tmp->next = NULL;

	if (head == NULL) //if list is empty
	{
		head = tmp;
		tail = tmp;
	}
	else //if list is not empty
	{
		tail->next = tmp;   //add node to the end
		tail = tail->next;
	}
}

void myList::findRectangle(int x, int y, myList &storage, int &count) //used for finding if there is any rectangle that includes the user's input: x,y coordinates.
{
	if (head != NULL) // if list is not empty
	{
		Rectangle * tmp = head;
		while (tmp != NULL)
		{
			if (y >= tmp->Top && y < tmp->Bottom && x < tmp->Right && x >= tmp->Left) { //check if the coordinate is inside of the rectangle //DEGISTI*****
				count++; //increase count for each rectangle we found
				storage.addNode(tmp->Top, tmp->Bottom, tmp->Right, tmp->Left);
			} //add corresponding rectangle to memory list
			tmp = tmp->next;
		}
	}
}



