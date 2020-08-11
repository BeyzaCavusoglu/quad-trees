#include "BinaryTree.h"


void TwoDimBinaryTree::deleteTree(SubTreeNode * node) //delete tree
{
	if (node != NULL)
	{
		//delete the lists
		node->vertical.~myList();
		node->horizontal.~myList();

		//for all subtrees
		deleteTree(node->bottomLeft);
		deleteTree(node->bottomRight);
		deleteTree(node->topLeft);
		deleteTree(node->topRight);
	}
}


void TwoDimBinaryTree::addRectangle(int top, int bot, int left, int right, SubTreeNode * node)
{
	if ((top <= node->horizontalLine) && (bot > node->horizontalLine)) //if the rectangle is on the horizontal line
		node->horizontal.addNode(top, bot, right, left);   //add to horizontal list

	else if ((left <= node->verticalLine) && (right > node->verticalLine)) //if the rectangle is on the vertical line
		node->vertical.addNode(top, bot, right, left);

	//******************************************************************************************************************************************************

	else if ((top > node->horizontalLine) && (left < node->verticalLine)) //if the rectangle is not on vertical or horizontal, if it is at bottomLeft subtree
	{
		if (node->bottomLeft == NULL) //if subtree is empty, create it
		{
			node->bottomLeft = new SubTreeNode;
			node->bottomLeft->Extent.Top = node->Extent.Bottom - (node->Extent.Bottom - node->Extent.Top) / 2;
			node->bottomLeft->Extent.Bottom = node->Extent.Bottom;
			node->bottomLeft->Extent.Left = node->Extent.Left;
			node->bottomLeft->Extent.Right = (node->Extent.Right + node->Extent.Left) / 2;
			node->bottomLeft->horizontalLine = (node->bottomLeft->Extent.Bottom + node->bottomLeft->Extent.Top) / 2;
			node->bottomLeft->verticalLine = (node->bottomLeft->Extent.Right + node->bottomLeft->Extent.Left) / 2;

			//pointers of subtree assigned to NULL
			node->bottomLeft->Extent.next = NULL;
			node->bottomLeft->topLeft = NULL;
			node->bottomLeft->bottomLeft = NULL;
			node->bottomLeft->topRight = NULL;
			node->bottomLeft->bottomRight = NULL;

			addRectangle(top, bot, left, right, node->bottomLeft); // check again with recursive function
		}
		else
		{
			addRectangle(top, bot, left, right, node->bottomLeft); // check again with recursive function
		}
	}

	//******************************************************************************************************************************************************

	else if ((top > node->horizontalLine) && (left > node->verticalLine)) //if the rectangle is not on vertical or horizontal, if it is at bottomRight subtree
	{
		if (node->bottomRight == NULL) //if the subtree is empty, then create it
		{
			node->bottomRight = new SubTreeNode;
			node->bottomRight->Extent.Top = node->Extent.Bottom - (node->Extent.Bottom - node->Extent.Top) / 2;
			node->bottomRight->Extent.Bottom = node->Extent.Bottom;
			node->bottomRight->Extent.Left = node->Extent.Right - (node->Extent.Right - node->Extent.Left) / 2;
			node->bottomRight->Extent.Right = node->Extent.Right;
			node->bottomRight->horizontalLine = (node->bottomRight->Extent.Bottom + node->bottomRight->Extent.Top) / 2;
			node->bottomRight->verticalLine = (node->bottomRight->Extent.Right + node->bottomRight->Extent.Left) / 2;

			//pointers of subtree assigned to NULL
			node->bottomRight->Extent.next = NULL;
			node->bottomRight->topLeft = NULL;
			node->bottomRight->bottomLeft = NULL;
			node->bottomRight->topRight = NULL;
			node->bottomRight->bottomRight = NULL;

			addRectangle(top, bot, left, right, node->bottomRight); // check again with recursive function
		}
		else
		{
			addRectangle(top, bot, left, right, node->bottomRight); // check again with recursive function
		}

		
	}

	//******************************************************************************************************************************************************

	else if ((top < node->horizontalLine) && (left < node->verticalLine)) //if the rectangle is not on vertical or horizontal, if it is at topLeft subtree
	{
		if (node->topLeft == NULL) //if subtree is empty, create it
		{
			node->topLeft = new SubTreeNode;
			node->topLeft->Extent.Top = node->Extent.Top;
			node->topLeft->Extent.Bottom = (node->Extent.Bottom + node->Extent.Top) / 2;
			node->topLeft->Extent.Left = node->Extent.Left;
			node->topLeft->Extent.Right = (node->Extent.Right + node->Extent.Left) / 2;
			node->topLeft->horizontalLine = (node->topLeft->Extent.Bottom + node->topLeft->Extent.Top) / 2;
			node->topLeft->verticalLine = (node->topLeft->Extent.Right + node->topLeft->Extent.Left) / 2;

			//pointers of subtree assigned to NULL
			node->topLeft->Extent.next = NULL;
			node->topLeft->topLeft = NULL;
			node->topLeft->bottomLeft = NULL;
			node->topLeft->topRight = NULL;
			node->topLeft->bottomRight = NULL;

			addRectangle(top, bot, left, right, node->topLeft); // check again with recursive function
		}
		else
		{
			addRectangle(top, bot, left, right, node->topLeft); // check again with recursive function
		}
	}

	//******************************************************************************************************************************************************

	else if ((top < node->horizontalLine) && (left > node->verticalLine)) //if the rectangle is not on vertical or horizontal, if it is at topRight subtree
	{
		if (node->topRight == NULL) //if subtree is empty, create it
		{
			node->topRight = new SubTreeNode;
			node->topRight->Extent.Top = (node->Extent.Top);
			node->topRight->Extent.Bottom = (node->Extent.Bottom + node->Extent.Top) / 2;
			node->topRight->Extent.Left = node->Extent.Right - (node->Extent.Right - node->Extent.Left) / 2;
			node->topRight->Extent.Right = node->Extent.Right;
			node->topRight->horizontalLine = (node->topRight->Extent.Bottom + node->topRight->Extent.Top) / 2;
			node->topRight->verticalLine = (node->topRight->Extent.Right + node->topRight->Extent.Left) / 2;

			//pointers of subtree assigned to NULL
			node->topRight->Extent.next = NULL;
			node->topRight->topLeft = NULL;
			node->topRight->bottomLeft = NULL;
			node->topRight->topRight = NULL;
			node->topRight->bottomRight = NULL;

			addRectangle(top, bot, left, right, node->topRight); // check again with recursive function
		}
		else
		{
			addRectangle(top, bot, left, right, node->topRight); // check again with recursive function
		}
	}
	
}

void TwoDimBinaryTree::findCoordinate(int x, int y, SubTreeNode * node, myList &storage, int &count)
{
	//check lines
	node->vertical.findRectangle(x, y, storage, count);
	node->horizontal.findRectangle(x, y, storage, count);


	//if not in lines, then check the subtrees
	if (x < node->verticalLine && y < node->horizontalLine && node->topLeft != NULL)
		findCoordinate(x, y, node->topLeft, storage, count);
	
	else if (x > node->verticalLine && y < node->horizontalLine && node->topRight != NULL)
		findCoordinate(x, y, node->topRight, storage, count);

	else if (x < node->verticalLine && y > node->horizontalLine && node->bottomLeft != NULL)
		findCoordinate(x, y, node->bottomLeft, storage, count);

	else if (x > node->verticalLine && y > node->horizontalLine && node->bottomRight != NULL)
		findCoordinate(x, y, node->bottomRight, storage, count);
}




