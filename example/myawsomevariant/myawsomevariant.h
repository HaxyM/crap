#ifndef EXAMPLES_MYAWSOMEVARIANT_MYAWSOMEVARIANT
#define EXAMPLES_MYAWSOMEVARIANT_MYAWSOMEVARIANT

#include <crap/algorithm>
#include <crap/numeric>
#include <crap/utility>
#include <memory>
#include <new>
#include <type_traits>

template <class ... Types> class MyAwsomeVariant
{
 static_assert(!crap :: emptyType<Types...>(), "List of types must not be empty.");
 static_assert(crap :: noneOfType<std :: is_void, Types...>(), "None of fields may be void.");
 constexpr const static bool nothrowDestructible = crap :: allOfType<std :: is_nothrow_destructible, Types...>();
 constexpr const static bool nothrowCopyable = crap :: allOfType<std :: is_nothrow_copy_constructible, Types...>();
 template <class ... AnotherType> friend class MyAwsomeVariant;
 public:
 template <std :: enable_if_t<std :: is_default_constructible_v<crap :: frontType_t<Types...> >, void*> = nullptr>
	 MyAwsomeVariant() noexcept(std :: is_nothrow_default_constructible_v<crap :: frontType_t<Types...> >);
 template <class ... AnotherTypes,
	  std :: enable_if_t<crap :: allOfType<std :: is_copy_constructible, Types...>{}, void*> = nullptr,
	  std :: enable_if_t<crap :: isPermutationType <std :: is_same, Types...> :: template with<AnotherTypes...> :: value, void*> = nullptr>
	 MyAwsomeVariant(const MyAwsomeVariant<AnotherTypes...>& a) noexcept(nothrowCopyable);
 ~MyAwsomeVariant() noexcept(nothrowDestructible);
 private:
 template <class ... AnotherTypes> class indexRemapper;
 constexpr const static std :: size_t maxSize = crap :: maxForType<std :: size_t> :: template values<sizeof(Types)...>();
 constexpr const static std :: size_t commonAllignment = crap :: lcmValue<std :: size_t, alignof(Types)...>();
 template <class Type> void kill() noexcept(nothrowDestructible);
 template <class Type> void copyOnto(void* newData) const noexcept(nothrowCopyable);
 void killCurrent() noexcept(nothrowDestructible);
 void copyCurrent(void* newData) const noexcept(nothrowCopyable);
 using killer_type = crap :: commonType_t<decltype(&MyAwsomeVariant :: template kill<Types>)...>;
 using killers_type = std :: add_const_t<killer_type>[sizeof...(Types)];
 using copier_type = crap :: commonType_t<decltype(&MyAwsomeVariant :: template copyOnto<Types>)...>;
 using copiers_type = std :: add_const_t<copier_type>[sizeof...(Types)];
 static killers_type& getKillers() noexcept;
 static copiers_type& getCopiers() noexcept;
 static killers_type& killers;
 static copiers_type& copiers;
 std :: size_t index;
 std :: aligned_storage_t<maxSize, commonAllignment> data;
};

template <class ... Types> template <class ... AnotherTypes> class MyAwsomeVariant <Types...> :: indexRemapper
{
 static_assert(crap :: isPermutationType<std :: is_same, Types...> :: template with <AnotherTypes...> :: value, "Type lists must be ate least permutations.");
 public:
 static std :: size_t getIndexInThis(std :: size_t index) noexcept;
 static std :: size_t getIndexInAnother(std :: size_t index) noexcept;
 private:
 constexpr const static std :: size_t sizeOfIndicesInThis = sizeof...(AnotherTypes);
 constexpr const static std :: size_t sizeOfIndicesInAnother = sizeof...(Types);
 template <class Type> using indexInThis = crap :: findType<Type, std :: is_same, Types...>;
 template <class Type> using indexInAnother = crap :: findType<Type, std :: is_same, AnotherTypes...>;
 constexpr static std :: size_t indicesInThis[sizeOfIndicesInThis] = {indexInThis<AnotherTypes>()...};
 constexpr static std :: size_t indicesInAnother[sizeOfIndicesInAnother] = {indexInAnother<Types>()...};
};

template <class ... Types>
typename MyAwsomeVariant <Types...> :: killers_type&
MyAwsomeVariant <Types...> :: killers = MyAwsomeVariant <Types...> :: getKillers();

template <class ... Types>
typename MyAwsomeVariant <Types...> :: copiers_type&
MyAwsomeVariant <Types...> :: copiers = MyAwsomeVariant <Types...> :: getCopiers();

template <class ... Types> template <std :: enable_if_t <std :: is_default_constructible_v<typename crap :: frontType <Types...> :: type>, void*> >
MyAwsomeVariant <Types...> :: MyAwsomeVariant() noexcept(std :: is_nothrow_default_constructible_v<typename crap :: frontType <Types...> :: type>)
	: index(0u)
{
 new (reinterpret_cast<std :: add_pointer_t<crap :: frontType_t<Types...> > >(&data)) crap :: frontType_t<Types...>();
}

template <class ... Types> template <class ... AnotherTypes,
	std :: enable_if_t <crap :: allOfType<std :: is_copy_constructible, Types...>{}, void*>,
	std :: enable_if_t <crap :: isPermutationType <std :: is_same, Types...> :: template with<AnotherTypes...> :: value, void*> >
MyAwsomeVariant <Types...> :: MyAwsomeVariant(const MyAwsomeVariant<AnotherTypes...>& a) noexcept(MyAwsomeVariant <Types...> :: nothrowCopyable)
	: index(MyAwsomeVariant <Types...> :: indexRemapper <AnotherTypes...> :: getIndexInThis(a.index))
{
 a.copyCurrent(&data);
}

template <class ... Types>
inline MyAwsomeVariant <Types...> :: ~MyAwsomeVariant() noexcept(MyAwsomeVariant <Types...> :: nothrowDestructible)
{
 killCurrent();
}

template <class ... Types> template <class Type>
void MyAwsomeVariant <Types...> :: kill() noexcept(MyAwsomeVariant <Types...> :: nothrowDestructible)
{
 std :: destroy_at(std :: launder(reinterpret_cast<std :: add_pointer_t<Type> >(&data)));
}

template <class ... Types> template <class Type>
void MyAwsomeVariant <Types...> :: copyOnto(void* newData) const noexcept(MyAwsomeVariant <Types...> :: nothrowCopyable)
{
 new (reinterpret_cast<std :: add_pointer_t<Type> >(newData)) Type(*std :: launder(reinterpret_cast<std :: add_pointer_t<std :: add_const_t<Type> > >(&data)));
}

template <class ... Types>
inline void MyAwsomeVariant <Types...> :: killCurrent() noexcept(MyAwsomeVariant <Types...> :: nothrowDestructible)
{
 if (index < sizeof...(Types)) (this->*(killers[index]))();
}

template <class ... Types>
inline void MyAwsomeVariant <Types...> :: copyCurrent(void* newData) const noexcept(MyAwsomeVariant <Types...> :: nothrowCopyable)
{
 if (index < sizeof...(Types)) (this->*(copiers[index]))(newData);
}

template <class ... Types>
typename MyAwsomeVariant <Types...> :: killers_type& MyAwsomeVariant <Types...> :: getKillers() noexcept
{
 static typename MyAwsomeVariant <Types...> :: killers_type array {reinterpret_cast<killer_type>(&MyAwsomeVariant <Types...> :: template kill<Types>)...};
 return array;
}

template <class ... Types>
typename MyAwsomeVariant <Types...> :: copiers_type& MyAwsomeVariant <Types...> :: getCopiers() noexcept
{
 static typename MyAwsomeVariant <Types...> :: copiers_type array = {reinterpret_cast<copier_type>(&MyAwsomeVariant <Types...> :: template copyOnto<Types>)...};
 return array;
}

template <class ... Types> template <class ... AnotherTypes>
std :: size_t MyAwsomeVariant <Types...> :: template indexRemapper <AnotherTypes...> :: getIndexInThis(std :: size_t index) noexcept
{
 if (index < MyAwsomeVariant <Types...> :: template indexRemapper <AnotherTypes...> :: sizeOfIndicesInThis)
	 return MyAwsomeVariant <Types...> :: template indexRemapper <AnotherTypes...> :: indicesInThis[index];
 return MyAwsomeVariant <Types...> :: template indexRemapper <AnotherTypes...> :: sizeOfIndicesInAnother;
}

template <class ... Types> template <class ... AnotherTypes>
std :: size_t MyAwsomeVariant <Types...> :: template indexRemapper <AnotherTypes...> :: getIndexInAnother(std :: size_t index) noexcept
{
 if (index < MyAwsomeVariant <Types...> :: template indexRemapper <AnotherTypes...> :: sizeOfIndicesInAnother)
	 return MyAwsomeVariant <Types...> :: template indexRemapper <AnotherTypes...> :: indicesInAnother[index];
 return MyAwsomeVariant <Types...> :: template indexRemapper <AnotherTypes...> :: sizeOfIndicesInThis;
}
#endif

