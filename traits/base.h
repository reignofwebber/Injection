#pragma once

#include "../forward.h"

NAMESPACE_INJECTION_BEGIN

NAMESPACE_TRAITS_BEGIN

struct _true_type {};
struct _false_type {};


template <typename T>
struct _traits
{
	using is_void = _false_type;
};

template<typename... Args>
struct _traits<void (*)(Args...)>
{
	using is_void = _true_type;
};













NAMESPACE_TRAITS_END

NAMESPACE_INJECTION_END