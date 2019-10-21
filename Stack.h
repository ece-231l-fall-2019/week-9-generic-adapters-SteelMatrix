template<typename T>
class Stack
{
  protected:
    List<T> c;
  public:

    T& top()
    {
      return c.back();
    }

    const T& top() const
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

    Stack<T>& operator=(const Stack<T>& other)
    {
      c = other;
    }
};

template<typename T>
bool operator==(const Stack<T>& a, const Stack<T>& b)
{
  return true; //a.c == b.c;
}

template<typename T>
bool operator!=(const Stack<T>& a, const Stack<T>& b)
{
  return true; //a.c != b.c;
}
