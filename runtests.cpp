#include <iostream>

// change the value below to 1 to run tests against your StringList class.
// change the value below to 0 to run tests against the built in std::list.

#include <string>

#if 1
#include "List.h"
typedef List<std::string> StringList;
typedef List<int> IntList;
#include "Stack.h"
typedef Stack<std::string> StringStack;
typedef Stack<int> IntStack;
#include "Queue.h"
typedef Queue<std::string> StringQueue;
typedef Queue<int> IntQueue;
#else
#include <list>
typedef std::list<std::string> StringList;
typedef std::list<int> IntList;
#include <stack>
typedef std::stack<std::string> StringStack;
typedef std::stack<int> IntStack;
#include <queue>
typedef std::queue<std::string> StringQueue;
typedef std::queue<int> IntQueue;
#endif

void Assert(bool cond, std::string message)
{
	if (cond)
		std::cout << "Pass: " << message << std::endl;
	else
		std::cerr << "FAIL: " << message << std::endl;
}

int main()
{
	// TODO:
	// Write more tests to fully test your classes.

	StringList a;
	StringList b;

	a.push_front("A");
	Assert(a.front() == "A", "front == A");
	a.push_front("B");
	Assert(a.front() == "B", "front == B");
	a.pop_front();
	Assert(a.front() == "A", "front == A");
	a.push_front("Z");
	Assert(a.front() == "Z", "front == Z");

	b = a;
	// a.printData(1);
	// b.printData(1);
	Assert(b.front() == "Z", "b.front == Z");
	b.pop_front();
	Assert(b.front() == "A", "b.front == A");
	b.pop_front();
	// b.printData(1);
	Assert(b.empty() == true, "b is empty");
	Assert(a.empty() == false, "a is NOT empty");

	// TODO: check all methods on StringList...

	StringStack c;
	c.push("A");
	c.push("B");
	Assert(c.top() == "B", "B is at top");
	c.pop();
	Assert(c.empty() == false, "B is not empty");
	c.pop();
	Assert(c.empty() == true, "B is empty");

	// TODO: check all methods on StringStack...

	IntList ia;
	ia.push_front(5);
	ia.push_front(6);
	Assert(ia.front() == 6, "front is 6");

	// TODO: check all methods on IntList...

	IntStack ic;
	ic.push(6);
	ic.push(5);
	Assert(ic.top() == 5, "top is 5");

	IntStack ib = {1, 2, 3, 4, 5, 6};
	Assert(ib.top() == 6, "top is 6\t\t\t\t(1)");

	IntStack ib2;
	ib2 = ib;
	Assert(ib == ib2, "ib == ib2 before pop\t\t(2)");
	Assert(ib != ib2, "ib != ib2 before pop\t\t(3)");
	ib2.pop();
	Assert(ib == ib2, "ib == ib2 after pop\t\t(4)");
	Assert(ib != ib2, "ib != ib2 after pop\t\t(5)");

	// TODO: check all methods on IntStack...

	// TODO: check all methods on StringQueue...

	StringQueue sq;

	sq = {"Test", "A", "B", "C", "D", "End Test"};
	Assert(sq.empty() == false, "sq is NOT empty\t\t\t(6)");
	Assert(sq.front() == "Test", "Front of sq is \"Test\"\t\t(7)");
	Assert(sq.back() == "End Test", "Back of sq is \"End Test\"\t\t(8)");
	sq.pop();
	Assert(sq.front() == "A", "Front of sq is \"A\" after pop\t(9)");
	sq.push("E");
	Assert(sq.back() == "E", "Back of sq is \"E\" after push\t(10)");
	Assert(sq.size() == 6, "Size of sq is 6\t\t\t(11)");
	sq.clear();
	Assert(sq.empty() == true, "sq is empty after clear()\t\t(11)");

	StringQueue sq2;
	//Flavor text
	sq2 = {"Why are we still here?", "Just to suffer?", "Every night, I type in C code, C++ code, even in Javascript", "The errors I've got, the bugs I've got", "They won't stop recurring, it's like they're all still there!"};
	sq = sq2;
	Assert(sq == sq2, "sq equals sq2 after assignment\t(12)\n(Go into the code to see what sq2 is)");

	// TODO: check all methods on IntQueue...

	IntQueue iq;
	iq = {0, 1, 2, 3, 4, 5};
	Assert(iq.empty() == false, "iq is NOT empty\t\t\t(13)");
	Assert(iq.front() == 0, "Front of iq is 0\t\t\t(14)");
	Assert(iq.back() == 5, "Back of iq is 5\t\t\t(15)");
	iq.pop();
	Assert(iq.front() == 1, "Front of iq is 1 after pop\t(16)");
	iq.push(6);
	Assert(iq.back() == 6, "Back of iq is 6 after push\t(17)");
	Assert(iq.size() == 6, "Size of iq is 6\t\t\t(18)");
	iq.clear();
	Assert(iq.empty() == true, "iq is empty after clear()\t\t(19)");

	IntList il1 = {1, 2, 3, 4};

	return 0;
}
