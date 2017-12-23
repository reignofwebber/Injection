#pragma once

#include "base.h"

using namespace injection::exception;

NAMESPACE_INJECTION_BEGIN

NAMESPACE_EXCEPTION_BEGIN

////////////////////////////////////////////////////////////////////////////////////////////////

//1-----RunTimeException
class RunTimeException : public _base_exception
{
public:
	explicit RunTimeException(string msg,string filename, string funcname, int linenum)
		: _base_exception(msg, filename, funcname, linenum)
	{
		cout << "Exception type:" << "RunTimeException" << endl;
	}


};


//////////////////////////////////////////////////////////////////////////////////////////////

//2---------------OutOfMemoryException

class OutOfMemoryException :public _base_exception
{
public:
	explicit OutOfMemoryException(string msg,string filename, string funcname, int linenum)
		:_base_exception(msg,filename, funcname, linenum)
	{
	}

	virtual void message() const
	{
		base_message_begin();
		cout << "Exception type:" << "OutOfMemoryException" << endl;
		base_message();
		base_message_end();
	}
};


NAMESPACE_EXCEPTION_END

NAMESPACE_INJECTION_END

////////////////////////////////////////////////////////////////////////////////////////////////////////

//declare exceptions

#define RunTimeException(msg)		injection::exception::RunTimeException(msg,__FILE__,__FUNCTION__,__LINE__)
#define OutOfMemoryException(msg)	injection::exception::OutOfMemoryException(msg,__FILE__,__FUNCTION__,__LINE__)


