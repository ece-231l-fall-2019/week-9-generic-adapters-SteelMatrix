template<typename T>
class Queue
{
	protected:
	List<T> c;
	public:

	Queue()
	{
	}

	Queue(std::initializer_list<T> l): c(l)
	{
	}

	T& front()
	{
		return c.front();
	}

	const T& front() const
	{
		return c.front();
	}

	T& back()
	{
		return c.back();
	}

	const T& back() const
	{
		return c.back();
	}

	void push(const T& a)
	{
		c.push_back(a);
	}

	void pop()
	{
		c.pop_front();
	}

	size_t size() const
	{
		return c.size();
	}

	bool empty() const
	{
		return c.empty();
	}

	Queue<T>& operator=(const Queue<T>& other)
	{
		c = other.c;
		return *this;
	}

	void clear()
	{
		c.clear();
	}

	template<typename TT>
	friend bool operator==(const Queue<TT>&, const Queue<TT>&);
	template<typename TT>
	friend bool operator!=(const Queue<TT>&, const Queue<TT>&);
};

template<typename T>
bool operator==(const Queue<T>& a, const Queue<T>& b)
{
	return a.c == b.c;
}

template<typename T>
bool operator!=(const Queue<T>& a, const Queue<T>& b)
{
	return a.c != b.c;
}
