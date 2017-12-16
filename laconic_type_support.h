#pragma once
#include <type_traits>

/*
	Laconic type support

	Isn't good enough at some of SFINAE context and when type or value member must doesn't exists by current arguments context.
	//todo: - fix it.
*/

namespace lts
{
	template<class Type>
	struct type_constant
	{
		using type = Type;
		//todo: need value support?
		//should use sfinae for
		//using value = Type::value
		//and other members of integral_constant
	};

	using ::std::integral_constant;
	using ::std::bool_constant;
	using ::std::true_type;
	using ::std::false_type;

	template<class Type>
	using identity_type = Type;

	template<size_t Value>
	using size_t_constant = ::std::integral_constant<std::size_t, Value>;

	template<size_t Value>
	using unsigned_constant = ::std::integral_constant<unsigned, Value>;

#define SHORTENED_BOOL_METAFUNCTOR_1TYPEARG(functor_name) template<class Type> using functor_name = ::std::bool_constant<::std::functor_name<typename Type::type>::value>
#define SHORTENED_TYPE_METAFUNCTOR_1TYPEARG(functor_name) template<class Type> using functor_name = ::lts::type_constant<typename ::std::functor_name<typename Type::type>::type>
#define SHORTENED_SIZE_T_METAFUNCTOR_1TYPEARG(functor_name) template<class Type> using functor_name = ::lts::size_t_constant<::std::functor_name<typename Type::type>::value>
#define SHORTENED_BOOL_METAFUNCTOR_2TYPEARG(functor_name, Arg1, Arg2) template<class Arg1, class Arg2> using functor_name = ::std::bool_constant<::std::functor_name<typename Arg1::type, typename Arg2::type>::value>
#define SHORTENED_TYPE_METAFUNCTOR_2TYPEARG(functor_name, Arg1, Arg2) template<class Arg1, class Arg2> using functor_name = ::lts::type_constant<typename ::std::functor_name<typename Arg1::type, typename Arg2::type>::type>
#define SHORTENED_SIZE_T_METAFUNCTOR_1TYPEARG_1DEFAULTEDVALUEARG(functor_name, Arg1, Arg2, Arg2Default) template<class Arg1, class Arg2 = Arg2Default> using functor_name = ::lts::size_t_constant<::std::functor_name<typename Arg1::type, Arg2::type::value>::value>
#define SHORTENED_TYPE_METAFUNCTOR_1BOOLARG_2TYPEARG(functor_name, Arg1, Arg2, Arg3) template<class Arg1, class Arg2, class Arg3> using functor_name = ::lts::type_constant<typename ::std::functor_name<Arg1::type::value, typename Arg2::type, typename Arg3::type>::type>
//#define SHORTENED_TYPE_METAFUNCTOR_1VALUEARG_1DEFAULTEDTYPEARG(functor_name, Arg1, Arg2, Arg2Default) template<class Arg1, class Arg2 = Arg2Default> using functor_name = ::lts::type_constant<typename ::std::functor_name<Arg1::value, typename Arg2::type>::type>

	SHORTENED_BOOL_METAFUNCTOR_1TYPEARG(is_void);
	SHORTENED_BOOL_METAFUNCTOR_1TYPEARG(is_null_pointer);
	SHORTENED_BOOL_METAFUNCTOR_1TYPEARG(is_integral);
	SHORTENED_BOOL_METAFUNCTOR_1TYPEARG(is_floating_point);
	SHORTENED_BOOL_METAFUNCTOR_1TYPEARG(is_array);
	SHORTENED_BOOL_METAFUNCTOR_1TYPEARG(is_enum);
	SHORTENED_BOOL_METAFUNCTOR_1TYPEARG(is_union);
	SHORTENED_BOOL_METAFUNCTOR_1TYPEARG(is_class);
	SHORTENED_BOOL_METAFUNCTOR_1TYPEARG(is_function);
	SHORTENED_BOOL_METAFUNCTOR_1TYPEARG(is_pointer);
	SHORTENED_BOOL_METAFUNCTOR_1TYPEARG(is_lvalue_reference);
	SHORTENED_BOOL_METAFUNCTOR_1TYPEARG(is_rvalue_reference);
	SHORTENED_BOOL_METAFUNCTOR_1TYPEARG(is_member_object_pointer);
	SHORTENED_BOOL_METAFUNCTOR_1TYPEARG(is_member_function_pointer);
	SHORTENED_BOOL_METAFUNCTOR_1TYPEARG(is_fundamental);
	SHORTENED_BOOL_METAFUNCTOR_1TYPEARG(is_arithmetic);
	SHORTENED_BOOL_METAFUNCTOR_1TYPEARG(is_scalar);
	SHORTENED_BOOL_METAFUNCTOR_1TYPEARG(is_object);
	SHORTENED_BOOL_METAFUNCTOR_1TYPEARG(is_compound);
	SHORTENED_BOOL_METAFUNCTOR_1TYPEARG(is_reference);
	SHORTENED_BOOL_METAFUNCTOR_1TYPEARG(is_member_pointer);
	SHORTENED_BOOL_METAFUNCTOR_1TYPEARG(is_const);
	SHORTENED_BOOL_METAFUNCTOR_1TYPEARG(is_volatile);
	SHORTENED_BOOL_METAFUNCTOR_1TYPEARG(is_trivial);
	SHORTENED_BOOL_METAFUNCTOR_1TYPEARG(is_trivially_copyable);
	SHORTENED_BOOL_METAFUNCTOR_1TYPEARG(is_standard_layout);
	SHORTENED_BOOL_METAFUNCTOR_1TYPEARG(is_pod);
	SHORTENED_BOOL_METAFUNCTOR_1TYPEARG(is_literal_type);
	//SHORTENED_BOOL_METAFUNCTOR_1TYPEARG(has_unique_object_representations);
	SHORTENED_BOOL_METAFUNCTOR_1TYPEARG(is_empty);
	SHORTENED_BOOL_METAFUNCTOR_1TYPEARG(is_polymorphic);
	SHORTENED_BOOL_METAFUNCTOR_1TYPEARG(is_abstract);
	SHORTENED_BOOL_METAFUNCTOR_1TYPEARG(is_final);
	//SHORTENED_BOOL_METAFUNCTOR_1TYPEARG(is_aggregate);
	SHORTENED_BOOL_METAFUNCTOR_1TYPEARG(is_signed);
	SHORTENED_BOOL_METAFUNCTOR_1TYPEARG(is_unsigned);
	SHORTENED_BOOL_METAFUNCTOR_1TYPEARG(is_default_constructible);
	SHORTENED_BOOL_METAFUNCTOR_1TYPEARG(is_trivially_default_constructible);
	SHORTENED_BOOL_METAFUNCTOR_1TYPEARG(is_nothrow_default_constructible);
	SHORTENED_BOOL_METAFUNCTOR_1TYPEARG(is_copy_constructible);
	SHORTENED_BOOL_METAFUNCTOR_1TYPEARG(is_trivially_copy_constructible);
	SHORTENED_BOOL_METAFUNCTOR_1TYPEARG(is_nothrow_copy_constructible);
	SHORTENED_BOOL_METAFUNCTOR_1TYPEARG(is_move_constructible);
	SHORTENED_BOOL_METAFUNCTOR_1TYPEARG(is_trivially_move_constructible);
	SHORTENED_BOOL_METAFUNCTOR_1TYPEARG(is_nothrow_move_constructible);
	SHORTENED_BOOL_METAFUNCTOR_1TYPEARG(is_copy_assignable);
	SHORTENED_BOOL_METAFUNCTOR_1TYPEARG(is_trivially_copy_assignable);
	SHORTENED_BOOL_METAFUNCTOR_1TYPEARG(is_nothrow_copy_assignable);
	SHORTENED_BOOL_METAFUNCTOR_1TYPEARG(is_move_assignable);
	SHORTENED_BOOL_METAFUNCTOR_1TYPEARG(is_trivially_move_assignable);
	SHORTENED_BOOL_METAFUNCTOR_1TYPEARG(is_nothrow_move_assignable);
	SHORTENED_BOOL_METAFUNCTOR_1TYPEARG(is_destructible);
	SHORTENED_BOOL_METAFUNCTOR_1TYPEARG(is_trivially_destructible);
	SHORTENED_BOOL_METAFUNCTOR_1TYPEARG(is_nothrow_destructible);
	SHORTENED_BOOL_METAFUNCTOR_1TYPEARG(has_virtual_destructor);
	//SHORTENED_BOOL_METAFUNCTOR_1TYPEARG(is_swappable);
	//SHORTENED_BOOL_METAFUNCTOR_1TYPEARG(is_nothrow_swappable);
	using ::std::negation;

	SHORTENED_TYPE_METAFUNCTOR_1TYPEARG(underlying_type);
	SHORTENED_TYPE_METAFUNCTOR_1TYPEARG(decay);
	//SHORTENED_TYPE_METAFUNCTOR_1TYPEARG(remove_cvref);
	SHORTENED_TYPE_METAFUNCTOR_1TYPEARG(remove_cv);
	SHORTENED_TYPE_METAFUNCTOR_1TYPEARG(remove_const);
	SHORTENED_TYPE_METAFUNCTOR_1TYPEARG(remove_volatile);
	SHORTENED_TYPE_METAFUNCTOR_1TYPEARG(add_cv);
	SHORTENED_TYPE_METAFUNCTOR_1TYPEARG(add_const);
	SHORTENED_TYPE_METAFUNCTOR_1TYPEARG(add_volatile);
	SHORTENED_TYPE_METAFUNCTOR_1TYPEARG(remove_reference);
	SHORTENED_TYPE_METAFUNCTOR_1TYPEARG(add_lvalue_reference);
	SHORTENED_TYPE_METAFUNCTOR_1TYPEARG(add_rvalue_reference);
	SHORTENED_TYPE_METAFUNCTOR_1TYPEARG(remove_pointer);
	SHORTENED_TYPE_METAFUNCTOR_1TYPEARG(add_pointer);
	SHORTENED_TYPE_METAFUNCTOR_1TYPEARG(make_signed);
	SHORTENED_TYPE_METAFUNCTOR_1TYPEARG(make_unsigned);
	SHORTENED_TYPE_METAFUNCTOR_1TYPEARG(remove_extent);
	SHORTENED_TYPE_METAFUNCTOR_1TYPEARG(remove_all_extents);

	SHORTENED_BOOL_METAFUNCTOR_2TYPEARG(is_assignable, AssignableType, AssigneeType);
	SHORTENED_BOOL_METAFUNCTOR_2TYPEARG(is_trivially_assignable, AssignableType, AssigneeType);
	SHORTENED_BOOL_METAFUNCTOR_2TYPEARG(is_nothrow_assignable, AssignableType, AssigneeType);
	//SHORTENED_BOOL_METAFUNCTOR_2TYPEARG(is_swappable_with, Type1, Type2);
	//SHORTENED_BOOL_METAFUNCTOR_2TYPEARG(is_nothrow_swappable_with, Type1, Type2);
	SHORTENED_BOOL_METAFUNCTOR_2TYPEARG(is_same, Type1, Type2);
	SHORTENED_BOOL_METAFUNCTOR_2TYPEARG(is_base_of, Base, Derived);
	SHORTENED_BOOL_METAFUNCTOR_2TYPEARG(is_convertible, From, To);	

	SHORTENED_SIZE_T_METAFUNCTOR_1TYPEARG(alignment_of);
	SHORTENED_SIZE_T_METAFUNCTOR_1TYPEARG(rank);
	
	SHORTENED_SIZE_T_METAFUNCTOR_1TYPEARG_1DEFAULTEDVALUEARG(extent, ArrayType, Dimension, ::lts::unsigned_constant<0>);
	//SHORTENED_TYPE_METAFUNCTOR_1VALUEARG_1DEFAULTEDTYPEARG(enable_if, Condition, Type, void);

	using ::std::aligned_storage;
	using ::std::void_t;
	using ::std::conjunction;
	using ::std::disjunction;

	SHORTENED_TYPE_METAFUNCTOR_1BOOLARG_2TYPEARG(conditional, condition, TypeIfSuccess, TypeIfFail);
	
	/*
	todo: implement this:
	
	aligned_union;
	
	is_invocable
	is_invocable_r
	is_nothrow_invocable
	is_nothrow_invocable_r

	common_type

	result_of
	invoke_result
	
	is_constructible
	is_trivially_constructible
	is_nothrow_constructible;
	*/

#undef SHORTENED_TYPE_METAFUNCTOR_1TYPEARG
#undef SHORTENED_BOOL_METAFUNCTOR_1TYPEARG
#undef SHORTENED_SIZE_T_METAFUNCTOR_1TYPEARG
#undef SHORTENED_TYPE_METAFUNCTOR_2TYPEARG
#undef SHORTENED_BOOL_METAFUNCTOR_2TYPEARG
#undef SHORTENED_SIZE_T_METAFUNCTOR_1TYPEARG_1DEFAULTEDVALUEARG
#undef SHORTENED_TYPE_METAFUNCTOR_1BOOLARG_2TYPEARG
//#undef SHORTENED_TYPE_METAFUNCTOR_1VALUEARG_1DEFAULTEDTYPEARG
}

/*
Example: 

using T = type_constant<void>;
using U = type_constant<int&>;
using Y = type_constant<int>;
using W = type_constant<int[5][7]>;
using calculus = std::conjunction<negation<negation<is_void<identity_type<add_cv<T>>>>>, is_assignable<U, Y>, alignment_of<U>, extent<W>?, conditional<true_type, true_type, false_type>?, true_type>;
calculus::type a;
std::cout << (int)calculus::value;
_getch();

*/
