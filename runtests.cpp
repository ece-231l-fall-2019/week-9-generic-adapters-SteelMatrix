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
	Assert(ib.top() == 6, "top is 6\t\t\t\t\t\t\t(1)");

	IntStack ib2;
	ib2 = ib;
	Assert(ib == ib2, "ib == ib2 before pop\t\t\t\t\t(2)");
	Assert(ib != ib2, "ib != ib2 before pop\t\t\t\t\t(3)");
	ib2.pop();
	Assert(ib == ib2, "ib == ib2 after pop\t\t\t\t\t(4)");
	Assert(ib != ib2, "ib != ib2 after pop\t\t\t\t\t(5)");

	// TODO: check all methods on IntStack...

	// TODO: check all methods on StringQueue...

	StringQueue sq;

	sq = {"Test", "A", "B", "C", "D", "End Test"};
	Assert(sq.empty() == false, "sq is NOT empty\t\t\t\t\t\t(6)");
	Assert(sq.size() == 6, "The size of sq is 6\t\t\t\t\t(7)");
	Assert(sq.front() == "Test", "Front of sq is \"Test\"\t\t\t\t\t(8)");
	Assert(sq.back() == "End Test", "Back of sq is \"End Test\"\t\t\t\t\t(9)");
	sq.pop();
	Assert(sq.size() == 5, "The size of sq is 5\t\t\t\t\t(10)");
	Assert(sq.front() == "A", "Front of sq is \"A\" after pop\t\t\t\t(11)");
	sq.push("E");
	Assert(sq.back() == "E", "Back of sq is \"E\" after push\t\t\t\t(12)");
	Assert(sq.size() == 6, "Size of sq is 6\t\t\t\t\t\t(13)");
	sq.clear();
	Assert(sq.empty() == true, "sq is empty after clear()\t\t\t\t\t(14)");

	StringQueue sq2;
	//Flavor text
	sq2 = {"Why are we still here?", "Just to suffer?", "Every night, I program in C, C++, even in LabVIEW", "The errors I've got, the bugs I've got", "They won't stop recurring, it's like they're all still there!"};
	sq = sq2;
	Assert(sq == sq2, "sq == sq2 after assignment\t\t\t\t(15)");
	Assert(sq != sq2, "sq != sq2 after assignment\t\t\t\t(16)");
	sq.pop();
	Assert(sq == sq2, "sq == sq2 after pop()\t\t\t\t\t(17)");
	Assert(sq != sq2, "sq != sq2 after pop()\t\t\t\t\t(18)");

	// TODO: check all methods on IntQueue...

	IntQueue iq;
	iq = {0, 1, 2, 3, 4, 5};
	Assert(iq.empty() == false, "iq is NOT empty\t\t\t\t\t\t(19)");
	Assert(iq.size() == 6, "The size of sq is 6\t\t\t\t\t(20)");
	Assert(iq.front() == 0, "Front of iq is 0\t\t\t\t\t\t(21)");
	Assert(iq.back() == 5, "Back of iq is 5\t\t\t\t\t\t(22)");
	iq.pop();
	Assert(iq.front() == 1, "Front of iq is 1 after pop\t\t\t\t(23)");
	Assert(iq.size() == 5, "The size of iq is 5 after pop\t\t\t\t(24)");
	iq.push(6);
	Assert(iq.back() == 6, "Back of iq is 6 after push\t\t\t\t(25)");
	iq.clear();
	Assert(iq.empty() == true, "iq is empty after clear()\t\t\t\t\t(26)");

	IntQueue iq2;
	//Flavor Numbers
	iq2 = {8, 6, 7, -5, 3, 0, 9};
	iq = iq2;
	Assert(iq == iq2, "iq == iq2 after assignment\t\t\t\t(27)");
	Assert(iq != iq2, "iq != iq2 after assignment\t\t\t\t(28)");
	iq.pop();
	Assert(iq == iq2, "iq == iq2 after pop\t\t\t\t\t(29)");
	Assert(iq != iq2, "iq != iq2 after pop\t\t\t\t\t(30)");

	// TODO: check all methods on StringList...
	StringList sl;
	sl = {"This is a test", "This is a test as well"};
	Assert(sl.empty() == false, "sl is not empty\t\t\t\t\t\t(31)");
	Assert(sl.front() == "This is a test", "The front of sl matches the given phrase\t\t\t(32)");
	sl.push_front("The runtests is nearing its conclusion.");
	Assert(sl.front() == "The runtests is nearing its conclusion.", "The front of sl matches the new phrase\t\t\t(33)");
	Assert(sl.back() == "This is a test as well", "The back of sl matches the given phrase\t\t\t(34)");
	StringList sl2;
	sl2 = sl;
	Assert(sl == sl2, "sl == sl2 after assignment\t\t\t\t(35)");
	Assert(sl != sl2, "sl != sl2 after assignment\t\t\t\t(36)");
	sl.pop_front();
	Assert(sl == sl2, "sl == sl2 after pop_front() on sl\t\t\t\t(37)");
	Assert(sl != sl2, "sl != sl2 after pop_front() on sl\t\t\t\t(38)");
	sl.clear();
	Assert(sl.empty() == true, "sl is empty\t\t\t\t\t\t(39)");

	// TODO: check all methods on IntList...
	IntList il;
	il = {1, 2, 3, 5, 8, 13, 21};
	Assert(il.empty() == false, "il is not empty\t\t\t\t\t\t(40)");
	Assert(il.size() == 7, "The size of il is 7\t\t\t\t\t(41)");
	Assert(il.front() == 1, "The front of il is 1\t\t\t\t\t(42)");
	Assert(il.back() == 21, "The back of il is 21\t\t\t\t\t(43)");
	il.push_front(-1);
	Assert(il.front() == -1, "The front of il is -1\t\t\t\t\t(44)");
	il.push_back(34);
	Assert(il.back() == 34, "The back of il is 34 after push_back()\t\t\t(45)");
	Assert(il.size() == 9, "The size of il is 9 after push_back() and push_front()\t(46)");
	IntList il2;
	il2 = il;
	Assert(il2.empty() == false, "il2 is not empty after assignment\t\t\t\t(47)");
	Assert(il2.size() == 9, "The size of il2 is 9\t\t\t\t\t(48)");
	Assert(il == il2, "il == il2 after assignment\t\t\t\t(49)");
	Assert(il != il2, "il != il2 after assignment\t\t\t\t(50)");
	il.pop_front();
	Assert(il == il2, "il == il2 after pop_front\t\t\t\t\t(51)");
	Assert(il != il2, "il != il2 after pop_front\t\t\t\t\t(52)");
	il.clear();
	il2.clear();
	Assert(il.empty() == true, "il is empty after clear()\t\t\t\t\t(53)");
	Assert(il2.empty() == true, "il2 is empty after clear()\t\t\t\t(54)");


	return 0;
}
