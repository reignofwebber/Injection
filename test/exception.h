#pragma once

#include <string>
#include <iostream>

using std::string;


struct myExp
{
	string err;

	myExp(string s)
	{
		err = s;
		std::cout << err+" construct" << std::endl;
	}

	~myExp()
	{
		std::cout << err + " destruct" << std::endl;
	}

	void test_throw()
	{
		throw myExp("abc");
	}
};
