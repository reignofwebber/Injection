#pragma once

#include <stdlib.h>


template <typename T>
struct _i_allocator
{
	using allocator_type = T;
	using pallocator_type = T*;

	static pallocator_type allocate() = 0;
	static pallocator_type allocate(size_t) = 0;

	static bool deallocate(pallocator_type) = 0;

	static bool construct() = 0;

	static bool destruct(pallocator_type) = 0;

};

template <typename T>
class simple_allocator : public _i_allocator<T>
{
public:
	static pallocator_type allocate()
	{
		return static_cast<pallocator_type>(malloc(sizeof(allocator_type)));
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
