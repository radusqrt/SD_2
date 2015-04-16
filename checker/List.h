#include "Node.h"
#include <stdio.h>
#include <iostream>
#include <cstring>

using namespace std;

class List
{
	Node *pFirst, *pLast;
public:

	List()
	{
		pFirst = pLast = NULL;
	}

	~List()
	{
		Node *aux;
    		while (pFirst)
    		{
    			aux = pFirst->next;
    			delete pFirst;
    			pFirst = aux;
		}

    		pFirst = pLast = NULL;
	}

	bool isEmpty() { return pFirst == NULL; }

	string printList()
	{
		Node *aux = pFirst;
		string s ("");
		while ( aux != NULL )
		{
			s += aux->value;
			aux = aux->next;
		}
		return s;
	}

	void addFirst(string value)
	{
		if(isEmpty())
		{
			Node *aux = new Node(value);
			pFirst = aux;
			pLast = pFirst;
		}
		else
		{
			Node *aux = new Node(value);
			aux->next = pFirst;
			pFirst->prev = aux;
			pFirst = aux;
		}
	}

	void addLast(string value)
	{
		if(isEmpty())
		{
			pLast = new Node(value);
			pFirst = pLast;
		}
		else
		{
			Node *aux = new Node(value);
			aux->prev = pLast;
			pLast->next = aux;
			pLast = aux;
		}
	}

	void addIndex(string value, int index)
	{
		if(index == 0)
			addFirst(value);
		else
		{
			Node *aux = pFirst;
			
			while(index--)
				aux = aux->next;
			
			if(aux == NULL)
				addLast(value);
			else
			{
				Node *word = new Node(value);
				aux->prev->next = word;
				word->prev = aux->prev;
				word->next = aux;
				aux->prev = word;
			}
		}
	}

	string get(int index)
	{
		Node *aux = pFirst;
		while(index-- && aux != NULL)
			aux = aux->next;
		if(aux != NULL)
			return aux->value;
	}

	void removeFirst()
	{
		if(!isEmpty())
			if(pFirst == pLast)
			{
				delete pFirst;
				pFirst = pLast = NULL;
			}
			else
			{
				Node *aux = pFirst->next;
				delete pFirst;
				pFirst = aux;
				pFirst->prev = NULL;
			}
	}

	void removeLast()
	{
		if(!isEmpty())
			if(pFirst == pLast)
			{
				delete pFirst;	
				pFirst = pLast = NULL;
			}
			else
			{
				Node *aux = pLast->prev;
				delete pLast;
				pLast = aux;
				pLast->next = NULL;
			}
	}

	void removeIndex(int index)
	{
		Node *aux;
		aux = pFirst;
		int k = 0;
		if(index == 0)
			removeFirst();
		else
		{
			while(k != (index-1))
			{
				k++;
				aux = aux->next;
			}
			if(aux->next != pLast)
			{
				aux->next = aux->next->next;
				delete aux->next->prev;
				aux->next->prev = aux;
			}
			else
				removeLast();
		}
	}

	int searchIndex(int index, bool ok = true)
	{
		if(index <= 0)
			return 0;
		Node *aux = pFirst;
		int count = 0;
		while(aux != NULL && index > 0)
		{
			index -= aux->value.size();
			aux = aux->next;
			count++;
		}
		if(index < 0 && ok == false) count--;
		return count;
	}

	int size()
	{
		Node *aux = pFirst;
		if(aux == NULL) return 0;
		int k = 0;
		while(aux != NULL)
		{
			k++;
			aux = aux->next;
		}
		return k;
	}
};
