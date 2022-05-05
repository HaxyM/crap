#ifndef TESTUTILS
#define TESTUTILS

#include <type_traits>

template <unsigned int Value> using u = std :: integral_constant<unsigned int, Value>;
template <signed int Value> using i = std :: integral_constant<signed int, Value>;

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

template <class, class> struct lessType;

template <unsigned int Lhs, unsigned int Rhs>
	 struct lessType<u<Lhs>, u<Rhs> > : std :: integral_constant<bool, (Lhs < Rhs)>
{
};

template <signed int Lhs, signed int Rhs>
	 struct lessType<i<Lhs>, i<Rhs> > : std :: integral_constant<bool, (Lhs < Rhs)>
{
};

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

template <class, class> struct equalType;

template <unsigned int Lhs, unsigned int Rhs>
	 struct equalType<u<Lhs>, u<Rhs> > : std :: integral_constant<bool, (Lhs == Rhs)>
{
};

template <signed int Lhs, signed int Rhs>
	 struct equalType<i<Lhs>, i<Rhs> > : std :: integral_constant<bool, (Lhs == Rhs)>
{
};
#endif

