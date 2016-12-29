#include "bind.h"
#include <iostream>
#include <string>

using namespace std;

int plain_inc(int a) {
	return ++a;
}

int ref_inc(int& a) {
	return ++a;
}

int cosnt_ref_inc(int const& a) {
	return a + 1;
}

int ref_ref_inc(int && a) {
	return ++a;
}

int main() {
	cout << "--BIND__TEST--" << endl;

	int a = 10;
	int& a_ref = a;
	int const& a_const_ref = 10;
	int&& a_ref_ref = 10;

	cout << bind(plain_inc, a)() << endl;
	cout << bind(plain_inc, a_ref)() << endl;
	cout << bind(plain_inc, a_const_ref)() << endl;
	cout << bind(plain_inc, a_ref_ref)() << endl;

	cout << bind(ref_inc, a)() << endl;
	cout << bind(ref_inc, a_ref)() << endl;
	//cout << bind(ref_inc, a_const_ref)() << endl;
	cout << bind(ref_inc, a_ref_ref)() << endl;

	cout << bind(cosnt_ref_inc, a)() << endl;
	cout << bind(cosnt_ref_inc, a_ref)() << endl;
	cout << bind(cosnt_ref_inc, a_const_ref)() << endl;
	cout << bind(cosnt_ref_inc, a_ref_ref)() << endl;

	cout << bind(ref_inc, _1)(a) << endl;
	cout << bind(ref_inc, _1)(a_ref) << endl;
	//cout << bind(ref_inc, a_const_ref)() << endl;
	cout << bind(ref_inc, _1)(a_ref_ref) << endl;


	cout << "OWO IT WORKS" << endl;
	return 0;
}