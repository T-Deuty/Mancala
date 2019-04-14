#pragma once
#include <exception>

using namespace std;

struct exitException : public exception
{
	const char * what() const throw ()
	{
		return "exitException";
	}
};

struct nonIntException : public exception
{
	const char * what() const throw ()
	{
		return "nonIntException";
	}
};

