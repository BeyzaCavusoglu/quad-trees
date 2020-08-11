#include <iostream>
#include <fstream>
#include <string>
#include "BinaryTree.h"

using namespace std;

int main()
{
	ifstream myFile("rectdb.txt"); //the txt file which includes the rectangles

	int top, left, bot, right; 
	myFile >> top >> left >> bot >> right; //we need to get the first rectangle and make it the extent rectangle
	TwoDimBinaryTree mainTree(top, left, bot, right);

	while (top != -1) //until the top of last input is -1
	{
		myFile >> top >> left >> bot >> right; //get the coordinate info
		if (top != -1) {
			mainTree.addRectangle(top, bot, left, right, mainTree.root); //add rectangle into binary tree
		}
	}

	int x = 0, y; //for coordinate searching

	while (x != -1)
	{
		cin >> x >> y;  //get the coordinates that will be searched
		myList temp; //a list for storing which rectangles are inclosing our coordinate
		int count = 0; //count is set to 0 for every new coordinate
		//cout << x << " " << y << endl;  //print input coordinates  **DEGISTI

		mainTree.findCoordinate(x, y, mainTree.root, temp, count); //finding the rectangles 
		cout << count << endl;
		if (count != 0) {  //if we can find the rectangles that includes our x and y points,
			temp.displayList();
		}
		temp.~myList(); //destroy list
	}

	myFile.close(); 
	mainTree.deleteTree(mainTree.root); //destroy tree

}