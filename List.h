#ifndef __EE231_List_h__
#define __EE231_List_h__

#include <cstddef>

template<typename T>
class List
{
	private:

	typedef struct llist {
		T val;
		struct llist *next;
		struct llist *prev;
	} llist;

	llist *_front;
	llist *_back;
	size_t _size;

	// private recursive copy so elements
	// end up in the same order.
	void reccopy(const llist *ptr)
	{
		if (ptr)
		{
			reccopy(ptr->next);
			push_front(ptr->val);
		}
	}

	public:

	// default constructor
	List()
	{
		_front = 0;
		_back = 0;
		_size = 0;
	}

	// copy constructor
	List(const List& other)
	{
		_front = 0;
		_back = 0;
		_size = 0;
		reccopy(other._front);
	}

	// destructor
	~List()
	{
		clear();
	}

	// copy operator
	List& operator=(const List& other)
	{
		clear();
		reccopy(other._front);
		return *this;
	}

/*
	void printData(bool addr = 0)
	{
		std::cout << "Object at Address " << this << ":\n";
		llist *ptr = new llist;
		for(ptr = _front; ptr != 0; ptr = ptr->next)
		{
			if(!addr)
			{
				if(ptr->val != "")
					std::cout << ptr->val << std::endl;
				else
					std::cout << "-" << std::endl;
			}
			else
			{
				if(ptr->val != "")
					std::cout << "At address " << ptr << ": " << ptr->val << std::endl;
				else
					std::cout << "-" << std::endl;
			}
		}
		std::cout << std::endl;
		delete ptr;
	}
*/
	void clear()
	{
		while(!empty())
			pop_front();
	}

	T& front()
	{
		return _front->val;
	}

	const T& front() const
	{
		return _front->val;
	}

	T& back()
	{
		return _back->val;
	}

	const T& back() const
	{
		return _back->val;
	}

	void push_front(const T& val)
	{
		llist *newItem = new llist;
		newItem->val = val;
		newItem->next = _front;
		newItem->prev = 0;
		if(_front)
			_front->prev = newItem;
		if(_back == 0)
			_back = newItem;
		_front = newItem;
		_size++;
	}

	void push_back(const T& val)
	{
		llist *newItem = new llist;
		newItem->val = val;
		newItem->prev = _back;
		newItem->next = 0;
		if(_back)
			_back->next = newItem;
		if(_front == 0)
			_front = newItem;
		_back = newItem;
		_size++;
	}

	void pop_front()
	{
		llist *newFront = _front;
		if (newFront)
		{
			_front = newFront->next;
			delete newFront;
//			_size--;
		}
		else
			_back = 0;
		_size--;
	}

	void pop_back()
	{
		llist *newBack = _back;
		if (newBack)
		{
			_back = newBack->prev;
			delete newBack;
//			_size--;
		}
		else
			_front = 0;
		_size--;

	}

	bool empty() const
	{
		return (_front == 0)||(_back == 0);
	}

	size_t size() const
	{
		return _size;
	}
};

#endif // __EE231_List_h__
