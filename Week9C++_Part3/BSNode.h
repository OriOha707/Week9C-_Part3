#ifndef BSNode_H
#define BSNode_H
#include <string>
#include <iostream>
template <class T>
class BSNode
{
public:
	BSNode(T data);
	BSNode(const BSNode& other);
	virtual ~BSNode();
	void insert(T value);
	BSNode& operator=(const BSNode& other);
	bool isLeaf() const;
	T getData() const;
	BSNode* getLeft() const;
	BSNode* getRight() const;
	bool search(T val) const;
	int getHeight() const;
	int getDepth(BSNode& root);
	void printNodes() const;
private:
	T _data;
	BSNode* _left;
	BSNode* _right;
	int _count; //to count replicates
	int getCurrNodeDistFromInputNode(BSNode* node); //auxiliary function for getDepth
};
template <class T>
BSNode<T>::BSNode(T data)
{
	this->_count = 1;
	this->_left = NULL;
	this->_right = NULL;
	this->_data = data;
}
/*
* Function copy one tree to other
*/
template <class T>
BSNode<T>::BSNode(const BSNode& other)
{
	this->_count = other._count;
	this->_data = other._data;
	if (other._right == NULL)
	{
		this->_right = NULL;
	}
	else
	{
		this->_right = new BSNode(*(other._right));
	}
	if (other._left == NULL)
	{
		this->_left = NULL;
	}
	else
	{
		this->_left = new BSNode(*(other._left));
	}
}
/*
* free memory
*/
template <class T>
BSNode<T>::~BSNode()
{
	if (this->_right != NULL)
	{
		delete this->_right;
	}
	if (this->_left != NULL)
	{
		delete this->_left;
	}
}
/*
* function insert value into the tree
*/
template <class T>
void BSNode<T>::insert(T value)
{
	if (this->_data == value)
	{
		this->_count++;
		return;
	}
	if (this->_data < value)
	{
		if (this->_right == NULL)
		{
			this->_right = new BSNode(value);
		}
		else
		{
			this->_right->insert(value);
		}
	}
	else
	{
		if (this->_left == NULL)
		{
			this->_left = new BSNode(value);
		}
		else
		{
			this->_left->insert(value);
		}
	}
}
/*
* Operator "=" for class BSNode
*/
template <class T>
BSNode<T>& BSNode<T>::operator=(const BSNode& other)
{
	if (&other == this) //If the trees are the same
		return *this;
	if (other._right)
		this->_right = new BSNode(*(other._right));
	if (other._left)
		this->_left = new BSNode(*(other._left));
	return *this;
}
/*
* Return true if leaf, false if not leaf
*/
template <class T>
bool BSNode<T>::isLeaf()const
{
	if (this->_left == NULL && this->_right == NULL)
		return true;
	return false;
}
/*
* Return the data
*/
template <class T>
T BSNode<T>::getData() const
{
	return this->_data;
}
/*
* Return thr left
*/
template <class T>
BSNode<T>* BSNode<T>::getLeft() const
{
	return this->_left;
}
/*
* return the right
*/
template <class T>
BSNode<T>* BSNode<T>::getRight() const
{
	return this->_right;
}
/*
* The function return true if the val is in the tree, false if not
*/
template <class T>
bool BSNode<T>::search(T val)const
{
	if (this->_data == val)
		return true;
	return ((this->_right == NULL ? false : this->_right->search(val)) || (this->_left == NULL ? false : this->_left->search(val)));
}
/*
* The function return the Hight of the tree
*/
template <class T>
int BSNode<T>::getHeight() const
{
	int hl = 0; // hight of the left side
	int hr = 0; // hight of the right side
	if (this->_left != NULL)
		hl = 1 + this->_left->getHeight();
	if (this->_right != NULL)
		hl = 1 + this->_right->getHeight();
	if (hl > hr)
		return hl;
	else
		return hr;
}
/*
* The function return the depth
*/
template <class T>
int BSNode<T>::getDepth(BSNode<T>& root)
{
	if (this == nullptr || !root.search(this->getData()))
	{
		return -1;
	}
	return this->getCurrNodeDistFromInputNode(&root);
}
/*
* The function print the nodes in alphabet order.
*/
template <class T>
void BSNode<T>::printNodes() const
{
	if (this != NULL)
	{
		if (this->_left != NULL)
		{
			this->_left->printNodes();
		}
		std::cout << this->_data << " " << this->_count << std::endl;
		if (this->_right != NULL)
		{
			this->_right->printNodes();
		}
	}
}
/*
* Function return the distance.
*/
template <class T>
int BSNode<T>::getCurrNodeDistFromInputNode(BSNode<T>* node)
{
	if (node == nullptr)
	{
		return -1;
	}
	if (node->search(this->_data) == false)
	{
		return -1;
	}
	if (this->_data != node->_data && node->_left != nullptr && this->_data < node->_data)
	{
		return getCurrNodeDistFromInputNode(node->_left) + 1;
	}
	if (this->_data != node->_data && node->_right != nullptr && this->_data > node->_data)
	{
		return getCurrNodeDistFromInputNode(node->_right) + 1;
	}
	return 0;
}
#endif