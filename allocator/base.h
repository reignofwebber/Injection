#pragma once

#include <stdlib.h>

#include "../exception/exception.h"


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
