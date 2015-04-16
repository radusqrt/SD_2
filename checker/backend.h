#ifndef BACKEND_H_
#define BACKEND_H_

#include "List.h"


class Backend {
public:	// TODO: Add your data here
	List l, clip;

	// Constructor
	Backend()
	{}	

	// Destructor
	~Backend(){}

	// Cuts all the words from the start to the stop index
	void Cut(const int start, const int stop)
	{
		clip.~List();
		int x = l.searchIndex(start);
		int y = l.searchIndex(stop, false);
		//cout << x << " " << y << "\n";
		for(int i = x; i < y; ++i)
		{
			clip.addLast(l.get(x));
			l.removeIndex(x);
		}
	}

	// Saves all the words from the start to the stop index to the clipboard
	void Copy(const int start, const int stop)
	{	
		clip.~List();
		int x = l.searchIndex(start);
		int y = l.searchIndex(stop, false);
		//cout << x << " " << y << "\n";
		for(int i = x; i < y; ++i)
			clip.addLast(l.get(i));
	}

	// Pastes all the words in the clipboard at the start index
	void Paste(const int start)
	{
		int x = l.searchIndex(start);
		for(int i = 0; i < clip.size(); ++i)
			l.addIndex(clip.get(i), x++);
	}

	// Undoes the last operation
	void Undo(void){}

	// Redoes the last undone operation
	void Redo(void){}

	// Adds the string held by "word" to the text at position "index"
	void Add(const int index, const char *word)
	{
		string word2(word);
		word2 += " ";
		l.addIndex(word2, l.searchIndex(index));
	}

	// Rebuilds and returns the whole text held by the backend
	char* GetText()
	{
		string s = l.printList();
		string s2 = clip.printList();
		//s += " | ";
		//s += s2;
		char* str = new char[s.size() + 1];
		strcpy(str, s.c_str());
		return str;
	}

};

#endif
