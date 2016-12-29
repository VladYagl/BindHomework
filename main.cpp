#include "bind.h"
#include <iostream>
#include <string>

using namespace std;

int sum(int a, int b) {
	return a + b;
}

void println(const string& text) {
	cout << text << endl;
}

auto inc = bind(sum, _1, 1);
auto another_sum = bind(sum, _1, _2);
auto say_hello = bind(println, "hello!");

string build_some_shit() {
	string s = "";
	for (int i = 60; i < 7000; i++) {
		s += i % 10 + 60;
	}
	return s;
}

int main() {
	cout << "--BIND__TEST--" << endl;

	auto shit_talking = bind(println, build_some_shit());
	shit_talking();

	string s;
	cin >> s;

	auto repeat = bind(println, s);
	repeat();

	cout << inc(10) << endl;
	cout << another_sum(1, 10) << endl;
	say_hello();

	cout << "OWO IT WORKS" << endl;
	return 0;
}