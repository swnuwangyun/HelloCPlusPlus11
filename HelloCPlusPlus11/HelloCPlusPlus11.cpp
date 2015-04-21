// HelloCPlusPlus11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <list>
#include <algorithm>
#include <thread>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	// Use of nullptr
	{
		int *a = nullptr;
		int b = 100;
		if (a){
			printf_s("a is not null");
		}
		if (a == nullptr){
			printf_s("a is null");
		}
		a = &b;
		printf_s("a=%d", *a);
	}

	// Use of auto
	{
		auto a = 100;
		auto b = "Hello";
		int c = 1.0234f;
		auto d = c;
		auto f = 23.22354f;
		printf_s("a=%d, b=%s, f=%f\n", a, b, f);

		list<int> l;
		l.push_back(1);
		l.push_back(2);
		l.push_back(3);
		for (auto i = l.begin(); i != l.end(); i++){
			int t = *i;
			printf_s("t=%d\n", t);
		}
		for (list<int>::iterator i = l.begin(); i != l.end(); i++){
			int t = *i;
			printf_s("t=%d\n", t);
		}

		int total = 0;
		for_each(l.begin(), l.end(), [&](int i){
			total += i; 
		});
		printf_s("total=%d\n", total);
	}

	// Use of lambda
	{
		auto f = [](int a, int b)->int{
			return a + b;
		};
		int result = f(1, 2);
		printf_s("result=%d\n", result);

		auto voidFunction = [](int a, int b){
			printf_s("inside voidFunction\n");
		};
		voidFunction(1, 2);

		auto a = [&]{
			printf_s("inside a, captured result=%d\n", result); 
			result++;
		};
		a();

		printf_s("result=%d\n", result);

		const int y = []{return 1 + 2; }();
		printf_s("const y=%d\n", y);
	}

	// Thread
	{
		thread t([]{
			printf_s("inside a thread\n");
		});
		t.join();
	}
	int a = 0;
	scanf_s("%d", &a);
	return 0;
}

