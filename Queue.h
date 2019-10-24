template<typename T>
class Queue
{
  protected:
    List<T> c;
  public:

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
      c.pop_back();
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
      c = other;
    }
};

template<typename T>
bool operator==(const Queue<T>& a, const Queue<T>& b)
{
  return true; //a.c == b.c;
}

template<typename T>
bool operator!=(const Queue<T>& a, const Queue<T>& b)
{
  return true; //a.c != b.c;
}
