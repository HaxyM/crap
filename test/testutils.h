#ifndef TESTUTILS
#define TESTUTILS

#include <type_traits>

//Short notation constants.
template <unsigned int Value> using u = std :: integral_constant<unsigned int, Value>;
template <signed int Value> using i = std :: integral_constant<signed int, Value>;

//Constrained less comparators.
template <class, class, class> struct lessConstrainedType;

template <unsigned int Lhs, unsigned int Rhs, unsigned int Restriction>
	 struct lessConstrainedType<u<Lhs>, u<Rhs>, u<Restriction> >
	 : std :: integral_constant<bool, (Lhs < Rhs)>
{
 static_assert((Lhs != Restriction) && (Rhs != Restriction), "Failed on restriction!");
};

template <signed int Lhs, signed int Rhs, signed int Restriction>
	 struct lessConstrainedType<i<Lhs>, i<Rhs>, i<Restriction> >
	 : std :: integral_constant<bool, (Lhs < Rhs)>
{
 static_assert((Lhs != Restriction) && (Rhs != Restriction), "Failed on restriction!");
};

//Normal less comparators.
template <class, class> struct lessType;

template <unsigned int Lhs, unsigned int Rhs>
	 struct lessType<u<Lhs>, u<Rhs> > : std :: integral_constant<bool, (Lhs < Rhs)>
{
};

template <signed int Lhs, signed int Rhs>
	 struct lessType<i<Lhs>, i<Rhs> > : std :: integral_constant<bool, (Lhs < Rhs)>
{
};

//Constrained equality comparators.
template <class, class, class> struct equalConstrainedType;

template <unsigned int Lhs, unsigned int Rhs, unsigned int Restriction>
	 struct equalConstrainedType<u<Lhs>, u<Rhs>, u<Restriction> >
	 : std :: integral_constant<bool, (Lhs == Rhs)>
{
 static_assert((Lhs != Restriction) && (Rhs != Restriction), "Failed on restriction!");
};

template <signed int Lhs, signed int Rhs, signed int Restriction>
	 struct equalConstrainedType<i<Lhs>, i<Rhs>, i<Restriction> >
	 : std :: integral_constant<bool, (Lhs == Rhs)>
{
 static_assert((Lhs != Restriction) && (Rhs != Restriction), "Failed on restriction!");
};

//Normal equality comparators.
template <class, class> struct equalType;

template <unsigned int Lhs, unsigned int Rhs>
	 struct equalType<u<Lhs>, u<Rhs> > : std :: integral_constant<bool, (Lhs == Rhs)>
{
};

template <signed int Lhs, signed int Rhs>
	 struct equalType<i<Lhs>, i<Rhs> > : std :: integral_constant<bool, (Lhs == Rhs)>
{
};

//Values streams to types streams conversion.
template <class Type, Type ... Values> struct valuesToTypes;

template <unsigned int ... Values> struct valuesToTypes<unsigned int, Values...>
{
 template <template <class...> class Container>
	 using type = Container<u<Values>...>;
};

template <signed int ... Values> struct valuesToTypes<signed int, Values...>
{
 template <template <class...> class Container>
	 using type = Container<i<Values>...>;
};

template <class Type> struct valuesToTypesForType
{
 template <Type ... Values> using type = valuesToTypes<Type, Values...>;
 template <Type ... Values> using values = valuesToTypes<Type, Values...>;
};

//Types streams to values streams conversion.
template <class ... Types> struct typesToValues;

template <unsigned int ... Values> struct typesToValues<u<Values>...>
{
 template <template <unsigned int...> class Container>
	 using type = Container<Values...>;
};

template <signed int ... Values> struct typesToValues<i<Values>...>
{
 template <template <signed int...> class Container>
	 using type = Container<Values...>;
};
#endif

