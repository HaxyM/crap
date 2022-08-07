#ifndef CRAP_NUMBERS_SQRT2TYPE
#define CRAP_NUMBERS_SQRT2TYPE

namespace crap
{
 template <class> struct sqrt2;

 template <> struct sqrt2<float>
 {
  constexpr const static float value = 1.4142135623730950488f;
 };

 template <> struct sqrt2<double>
 {
  constexpr const static double value = 1.4142135623730950488;
 };

 template <> struct sqrt2<long double>
 {
  constexpr const static double value = 1.4142135623730950488l;
 };
}
#endif

