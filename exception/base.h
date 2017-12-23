#pragma once

#include "../forward.h"
#include "../traits/base.h"


using std::string;
using std::cout;
using std::endl;


NAMESPACE_INJECTION_BEGIN

NAMESPACE_EXCEPTION_BEGIN

class _base_exception;

class RunTimeException;
class OutOfMemoryException;

class _base_exception
{
public:
	explicit _base_exception(string msg, string filename, string funcname, int linenum)
		:msg_string_(msg), filename_string_(filename), funcname_string_(funcname), linenum_int_(linenum)
	{
	}

public:
	virtual void message() const = 0;

protected:
	string	filename_string_;
	string	funcname_string_;
	int		linenum_int_;

	string msg_string_;

	void base_message() const
	{
		cout << "Exception at:" << "<" << filename_string_ << "> in " << funcname_string_ << "(" << linenum_int_ << ")" << endl;
		cout << "Message:" << msg_string_ << endl;
	}

	void base_message_begin() const
	{
		cout << "EXCEPTION_BEGIN-------------------------------------------------------------------------------" << endl;
	}

	void base_message_end() const
	{
		cout << "EXCEPTION_END-------------------------------------------------------------------------------" << endl;
	}
};



NAMESPACE_EXCEPTION_END

NAMESPACE_INJECTION_END

/////////////////////////////////////////////////////////////////////////////////////////////////////////

#define exception(msg)	injection::exception::_base_exception(msg,__FILE__,__FUNCTION__,__LINE__)

/////////////////////////////////////////////////////////////////////////////////////////////////////////

//handle exception

using namespace injection::exception;
using namespace injection::traits;

//void throw_if_fail(bool flag, const _base_exception &exp)		//child exception will cast to be _base_exception
//{
//	if (!flag)
//	{
//		throw exp;					//can't catch child exception....
//	}
//}

template <class Exception, typename Func, typename... Args>
void invoke_try_catch_dispatch(_false_type,const Exception &exp, Func func, Args... args)
{
	try
	{
		if (!func(args...))
			throw exp;
	}
	catch (_base_exception& exp)
	{
		exp.message();
	}
	catch (...)
	{
		cout << "Unknown exception" << endl;
	}
}

template <class Exception, typename Func, typename... Args>
void invoke_try_catch_dispatch(_true_type,const Exception &exp, Func func, Args... args)
{
	try
	{
		func(args...);
	}
	catch (_base_exception& exp)
	{
		exp.message();
	}
	catch (...)
	{
		cout << "Unknown exception" << endl;
	}
}

template <class Exception, typename Func, typename... Args>
void invoke_try_catch(const Exception &exp, Func func, Args... args)
{
	using is_void = typename _traits<Func>::is_void;
	invoke_try_catch_dispatch(is_void(), exp, func, args...);
}
