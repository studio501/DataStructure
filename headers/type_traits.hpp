
#ifdef _MSC_VER
#pragma once
#endif // _MSC_VER

#ifndef __TYPE_TRAITS_H_
#define __TYPE_TRAITS_H_

#include "Common.hpp"

BEGIN_TW

struct __true_type {};
struct __false_type {};

//Ω‚“˝”√
template<class Type>
struct remove_reference
{
	using type = Type;
};

template<class Type>
struct remove_reference<Type &>
{
	using type = Type;
};

template<class Type>
struct remove_reference<Type &&>
{
	using type = Type;
};

template<class Type>
constexpr inline typename remove_reference<Type>::type&& move(Type&& value)
{
	return static_cast<typename remove_reference<Type>::type&&>(value);
}

template<class Type>
struct type_traits
{
	typedef __false_type has_trivial_default_constructor;
	typedef __false_type has_trivial_copy_constructor;
	typedef __false_type has_trivial_assignment_operator;
	typedef __false_type has_trivial_destructor;
};

#define __TYPE_TRAITS_SIMPLE_DECLEAR(value_type,type)		\
template<>													\
struct type_traits<value_type>								\
{															\
	typedef type has_trivial_default_constructor;			\
	typedef type has_trivial_copy_constructor;				\
	typedef type has_trivial_assignment_operator;			\
	typedef type has_trivial_destructor;					\
};															\

DECLEAR_FOR_EACH_PRIMARYTYPE(__TYPE_TRAITS_SIMPLE_DECLEAR, __true_type);

END_TW

#endif // !__TYPE_TRAITS_H_