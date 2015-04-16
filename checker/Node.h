#include <cstddef>
#include <string>

class Node
{

public:
	Node *prev, *next;
	std::string value;

	Node()
	{
		next = prev = NULL;
	}
	
	Node(std::string value)
	{
		this->value = value;
		next = prev = NULL;
	}
	
	~Node()
	{
		next = prev = NULL;
	}
};
