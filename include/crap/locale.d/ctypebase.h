#ifndef CRAP_LOCALE_CTYPEBASE
#define CRAP_LOCALE_CTYPEBASE

#include <locale>
#include <type_traits>

namespace crap
{
 namespace ctypeBase
 {
  using mask = std :: ctype_base :: mask;
  using space = std :: integral_constant<mask, std :: ctype_base :: space>;
  using print = std :: integral_constant<mask, std :: ctype_base :: print>;
  using cntrl = std :: integral_constant<mask, std :: ctype_base :: cntrl>;
  using upper = std :: integral_constant<mask, std :: ctype_base :: upper>;
  using lower = std :: integral_constant<mask, std :: ctype_base :: lower>;
  using alpha = std :: integral_constant<mask, std :: ctype_base :: alpha>;
  using digit = std :: integral_constant<mask, std :: ctype_base :: digit>;
  using punct = std :: integral_constant<mask, std :: ctype_base :: punct>;
  using xdigit = std :: integral_constant<mask, std :: ctype_base :: xdigit>;
  using blank = std :: integral_constant<mask, std :: ctype_base :: blank>;
  using alnum = std :: integral_constant<mask, std :: ctype_base :: alnum>;
  using graph = std :: integral_constant<mask, std :: ctype_base :: graph>;
 }
}
#endif

