#include "bind.h"
#include <iostream>

using namespace std;

int sum(int a, int b) {
	return a + b;
}

auto inc = bind(sum, _1, 1);

int main() {
	cout << "--BIND__TEST--" << endl;

	cout << inc(10) << endl;

	cout << "OWO IT WORKS" << endl;
	return 0;
}