#include <iostream>
#include "BSNode.h"
int main()
{
	//Part A
	//BSNode<int>* bs = new BSNode<int>(6);
	//bs->insert(2);
	//bs->insert(8);
	//bs->insert(3);
	//bs->insert(5);
	//bs->insert(9);
	//bs->insert(6);
	//Part B
	int arrayOfInt[15] = { 22, 11, 55, 99, 100, 44, 33, 66, 77, 111, 20, 69, 420, 13, 8 };
	//Print not shorted array
	for (int i = 0; i < 15; i++)
	{
		std::cout << arrayOfInt[i] << " ";
	}
	std::cout << std::endl;
	//Create tree
	BSNode<int>* treeOfInt = new BSNode <int>(arrayOfInt[0]);
	for (int i = 1; i < 15; i++)
	{
		treeOfInt->insert(arrayOfInt[i]);
	}
	std::string arrayOfStrings[15] = { "a", "z", "d", "b", "h", "g", "c", "x", "e", "w", "q", "l", "s", "n", "m" };
	//Print not shorted array
	for (int i = 0; i < 15; i++)
	{
		std::cout << arrayOfStrings[i] << " ";
	}
	std::cout << std::endl;
	//create tree
	BSNode<std::string>* treeOfStrings = new BSNode <std::string>(arrayOfStrings[0]);
	for (int i = 1; i < 15; i++)
	{
		treeOfStrings->insert(arrayOfStrings[i]);
	}
	//Part C
	std::cout << "Sorted arrays: \n" << std::endl;
	treeOfInt->printNodes();
	std::cout << "\n" << std::endl;
	std::cout << "\n" << std::endl;
	std::cout << "\n" << std::endl;
	treeOfStrings->printNodes();
}