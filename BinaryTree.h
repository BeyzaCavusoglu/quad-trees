#include <iostream>
#include "LinkedList.h"


struct SubTreeNode
{
	Rectangle Extent; //borders of our biggest rectangle
	SubTreeNode * topLeft;
	SubTreeNode * bottomLeft;
	SubTreeNode * topRight;
	SubTreeNode * bottomRight;
	myList vertical, horizontal; //two different lists for two lines, for example vertical keeps the list of rectangles which intersect the vertical line.
	int verticalLine, horizontalLine; //two lines
};

class TwoDimBinaryTree
{

public:
	SubTreeNode * root; 
	TwoDimBinaryTree(int top, int left, int bottom, int right) //constructor
	{
		root = new SubTreeNode;
		root->Extent.Top = top;
		root->Extent.Bottom = bottom;
		root->Extent.Left = left;
		root->Extent.Right = right;

		//setting pointers of pointer to null
		root->Extent.next = NULL;
		root->bottomLeft = NULL;
		root->bottomRight = NULL;
		root->topLeft = NULL;
		root->topRight = NULL;

		//lines of the root
		root->horizontalLine = (root->Extent.Bottom + root->Extent.Top) / 2;
		root->verticalLine = (root->Extent.Right + root->Extent.Left) / 2;
	}


	void addRectangle(int top, int bot, int left, int right, SubTreeNode * node); //add new rectangle to tree
	void findCoordinate(int x, int y, SubTreeNode * node, myList &storage, int &count); //find all the rectangles in that coordinate
	void deleteTree(SubTreeNode * node); //delete tree
};


