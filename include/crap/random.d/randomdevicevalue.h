#ifndef CRAP_RANDOM_RANDOMDEVICEVALUE
#define CRAP_RANDOM_RANDOMDEVICEVALUE

#include <climits>
#include <cstddef>

#include "../numeric.d/iotavalue.h"
#include "../utility.d/bisectvalue.h"

namespace crap
{
 template <std :: size_t Init> struct randomDeviceValue
 {
  private:
  template <std :: size_t, char...> struct process;
  template <std :: size_t SubInit> struct process<SubInit>;
  template <std :: size_t SubInit, char Symbol> struct process<SubInit, Symbol>;
  template <std :: size_t SubInit> struct step1;
  template <std :: size_t SubInit> struct step2;
  template <std :: size_t SubInit> struct step3;
  template <class Type, std :: size_t N> constexpr static std :: size_t elements(Type (&)[N]) noexcept;
  constexpr const static std :: size_t any = 0u;
  constexpr const static std :: size_t zeros = any ^ any;
  #ifdef __INCLUDE_LEVEL__
  constexpr const static std :: size_t init = (Init ^ (~zeros)) + __INCLUDE_LEVEL__;
  #else
  constexpr const static std :: size_t init = (Init ^ (~zeros));
  #endif
  public:
  constexpr const static std :: size_t value = step3 <step2 <step1 <init> :: value> :: value> :: value;
 };

 template <std :: size_t Init> template <std :: size_t SubInit, char ... Symbols> struct randomDeviceValue <Init> :: process
 {
  private:
  using values = bisectValue<char, Symbols...>;
  template <char ... SubSymbols> using lower = process<SubInit, SubSymbols...>;
  template <char ... SubSymbols> using upper = process<values :: template lower <lower> :: value, SubSymbols...>;
  public:
  constexpr const static std :: size_t value = values :: template upper <upper> :: value;
 };

 template <std :: size_t Init> template <std :: size_t SubInit> struct randomDeviceValue <Init> :: template process<SubInit>
 {
  constexpr const static std :: size_t value = SubInit;
 };

 template <std :: size_t Init> template <std :: size_t SubInit, char Symbol> struct randomDeviceValue <Init> :: template process<SubInit, Symbol>
 {
  private:
  constexpr const static std :: size_t value1 = (SubInit ^ ((SubInit << CHAR_BIT) | static_cast<std :: size_t>(Symbol)));
  constexpr const static std :: size_t value2 = value1 ^ (value1 << 13u);
  constexpr const static std :: size_t value3 = value2 ^ (value2 >> 17u);
  public:
  constexpr const static std :: size_t value = value3 ^ (value3 << 5u);
 };

 template <std :: size_t Init> template <std :: size_t SubInit> struct randomDeviceValue <Init> :: step1
 {
  private:
  //TODO: Check why timestamp is locking on particular value, and time not.
  //#ifdef __TIMESTAMP__
  //constexpr const static char symbols[] = __TIMESTAMP__;
  //#else
  constexpr const static char symbols[] = __TIME__ __DATE__;
  //#endif
  constexpr const static std :: size_t size = randomDeviceValue <Init> :: elements(symbols);
  template <std :: size_t ... Indices> using Implementation = typename randomDeviceValue <Init> :: template process<SubInit, symbols[Indices]...>;
  public:
  constexpr const static std :: size_t value = iotaValue <size, std :: size_t> :: template type <Implementation> :: value;
 };

 template <std :: size_t Init> template <std :: size_t SubInit> struct randomDeviceValue <Init> :: step2
 {
  private:
  #ifdef __BASE_FILE__
  constexpr const static char symbols[] = __BASE_FILE__;
  #else
  constexpr const static char symbols[] = __FILE__;
  #endif
  constexpr const static std :: size_t size = randomDeviceValue <Init> :: elements(symbols);
  template <std :: size_t ... Indices> using Implementation = typename randomDeviceValue <Init> :: template process<SubInit, symbols[Indices]...>;
  public:
  constexpr const static std :: size_t value = iotaValue <size, std :: size_t> :: template type <Implementation> :: value;
 };

 template <std :: size_t Init> template <std :: size_t SubInit> struct randomDeviceValue <Init> :: step3
 {
  private:
  #ifdef __VERSION__
  constexpr const static char symbols[] = __VERSION__;
  #else
  constexpr const static char symbols[] = "Unknown version.";
  #endif
  constexpr const static std :: size_t size = randomDeviceValue <Init> :: elements(symbols);
  template <std :: size_t ... Indices> using Implementation = typename randomDeviceValue <Init> :: template process<SubInit, symbols[Indices]...>;
  public:
  constexpr const static std :: size_t value = iotaValue <size, std :: size_t> :: template type <Implementation> :: value;
 };
}

template <std :: size_t Init> template <class Type, std :: size_t N> inline constexpr std :: size_t crap :: randomDeviceValue <Init> :: elements(Type (&)[N]) noexcept
{
 return N;
}
#endif

