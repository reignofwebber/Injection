#pragma once

#include "base.h"

template <typename T>
class simple_allocator : public _i_allocator<T>
{
public:
	static pallocator_type allocate()
	{
		try
		{
			pallocator_type tmp = malloc(sizeof(allocator_type));
			throw_if_fail(tmp, OutOfMemoryException("Failed at malloc()"));
		}
		catch (const OutOfMemoryException& exp)
		{

		}
		return static_cast<pallocator_type>(tmp);
	}

	static pallocator_type allocate(size_t n)
	{
		return static_cast<pallocator_type>(malloc(sizeof(allocator_type)*n));
	}

	static bool deallocate(pallocator_type)
	{

	}


	static bool construct();

	static bool destruct(pallocator_type);
};
