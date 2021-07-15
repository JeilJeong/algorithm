#include <iostream>

using namespace	std;

struct Person {
	Person() { age = 0; }
	int		age;
	int		person = 10;
};

struct Mom : Person {
	Mom() { age = 1; }
};

struct Dad : Person {
	Dad() { age = 2; }
};

struct Child : Mom, Dad {
	int c = 3;
};

int		main(void)
{
	Mom		m;
	Child	ch;
	cout << &(ch.Mom::age) << endl;
	cout << &(ch.Dad::age) << endl;
	cout << &(ch.c) << endl;
	cout << sizeof(ch) << endl;
	cout << ch.Mom::person << endl;
	cout << m.Mom::person << endl;
	cout << m.Person::person << endl;
	cout << sizeof(m) << endl;
}