
#include "../exception/exception.h"



using namespace injection::exception;

bool add(int a,int b)
{
	return a + b;
}

void add1(int a,int b)
{
	char*p = (char *)malloc(10 * sizeof(wchar_t));
}

int main()
{
	invoke_try_catch(OutOfMemoryException("failed"), add,5,-5);
	

	getchar();
}

