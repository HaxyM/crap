#ifndef EXAMPLES_MYAWSOMEVARIANT_MYAWSOMEVARIANT
#define EXAMPLES_MYAWSOMEVARIANT_MYAWSOMEVARIANT

#include <crap/algorithm>
#include <crap/numeric>
#include <crap/utility>
#include <memory>
#include <new>
#include <type_traits>
#include <utility>

template <class ... Types> class MyAwsomeVariant
{
 static_assert(!crap :: emptyType<Types...>(), "List of types must not be empty.");
 static_assert(crap :: noneOfType<std :: is_void, Types...>(), "None of fields may be void.");
	//Does not thow from destructor if none of possibly stored types does.
 constexpr const static bool nothrowDestructible = crap :: allOfType<std :: is_nothrow_destructible, Types...>();
	//Does not throw while copying if none of possibly stored types does.
 constexpr const static bool nothrowCopyable = crap :: allOfType<std :: is_nothrow_copy_constructible, Types...>();
	//Does not throw while moveing if none of possibly stored types does.
 constexpr const static bool nothrowMoveable = crap :: allOfType<std :: is_nothrow_move_constructible, Types...>();
	//Other template overloads should be friends to each other, so thingh like copying from permutation may work.
 template <class ... AnotherType> friend class MyAwsomeVariant;
	//Helper checking if "Type" is among possibly stored types.
 template <class Type>
	 using hasType = std :: integral_constant<bool, crap :: findType<Type, std :: is_same, Types...>() != crap :: findType <Type, std :: is_same, Types...> :: npos>;
 public:
	//Default constructor defaultly constructs first stored type.
	//Therefore if it is not possible, then there is no default constructor.
 template <std :: enable_if_t<std :: is_default_constructible_v<crap :: frontType_t<Types...> >, void*> = nullptr>
	 MyAwsomeVariant() noexcept(std :: is_nothrow_default_constructible_v<crap :: frontType_t<Types...> >);
	//May copy from any other variant that forms permutation of stored types and if all of them may be copied of course.
 template <class ... AnotherTypes,
	  std :: enable_if_t<crap :: allOfType<std :: is_copy_constructible, Types...>{}, void*> = nullptr,
	  std :: enable_if_t<crap :: isPermutationType <std :: is_same, Types...> :: template with<AnotherTypes...> :: value, void*> = nullptr>
	 MyAwsomeVariant(const MyAwsomeVariant<AnotherTypes...>& a) noexcept(nothrowCopyable);
	//May move from any other variant that forms permutation of stored types and if all of them may be moved of course.
 template <class ... AnotherTypes,
	  std :: enable_if_t<crap :: allOfType<std :: is_move_constructible, Types...>{}, void*> = nullptr,
	  std :: enable_if_t<crap :: isPermutationType <std :: is_same, Types...> :: template with<AnotherTypes...> :: value, void*> = nullptr>
	 MyAwsomeVariant(MyAwsomeVariant<AnotherTypes...>&& a) noexcept(nothrowMoveable);
 ~MyAwsomeVariant() noexcept(nothrowDestructible);
	//Force to store value of particular type "Type" if that type is among stored ones.
 template <class Type, class ... Args>
	 std :: enable_if_t<hasType<Type>{}, std :: add_lvalue_reference_t<Type> >
	 emplace(Args&& ... args)
		 //Will throw only if destruction or construction of new one does so.
	 noexcept(nothrowDestructible && std :: is_nothrow_constructible<Type, std :: add_rvalue_reference_t<Args>...>());
 private:
	//Helper translating indices of stroed types.
 template <class ... AnotherTypes> class indexRemapper;
	//Size required for union is side of largest of stored types.
 constexpr const static std :: size_t maxSize = crap :: maxForType<std :: size_t> :: template values<sizeof(Types)...>();
	//Alligment is LCM of all alligments (may be simpler on most architectures, but lets not assume anything).
 constexpr const static std :: size_t commonAllignment = crap :: lcmValue<std :: size_t, alignof(Types)...>();
	//Destroy stored element of type "Type".
 template <class Type> void kill() noexcept(nothrowDestructible);
	//Copy stored element of type "Type" onto new location (passed as argument).
 template <class Type> void copyOnto(void* newData) const noexcept(nothrowCopyable);
	//Move stored element of type "Type" onto new location (passed as argument).
 template <class Type> void moveOnto(void* newData) const noexcept(nothrowMoveable);
	//Destroy currently stored element (if any is stored).
 void killCurrent() noexcept(nothrowDestructible);
	//Copy stored element (if any is stored) onto new location (passed as argument).
 void copyCurrent(void* newData) const noexcept(nothrowCopyable);
	//Move stored element (if any is stored) onto new location (passed as argument).
 void moveCurrent(void* newData) const noexcept(nothrowMoveable);
	//Helper subtypes
 using killer_type = crap :: commonType_t<decltype(&MyAwsomeVariant :: template kill<Types>)...>;
 using killers_type = std :: add_const_t<killer_type>[sizeof...(Types)];
 using copier_type = crap :: commonType_t<decltype(&MyAwsomeVariant :: template copyOnto<Types>)...>;
 using copiers_type = std :: add_const_t<copier_type>[sizeof...(Types)];
 using mover_type = crap :: commonType_t<decltype(&MyAwsomeVariant :: template moveOnto<Types>)...>;
 using movers_type = std :: add_const_t<mover_type>[sizeof...(Types)];
	//Arrays (and helpers creating them) mapping index of stored element onto valid methods for its type.
 static killers_type& getKillers() noexcept;
 static copiers_type& getCopiers() noexcept;
 static movers_type& getMovers() noexcept;
 static killers_type& killers;
 static copiers_type& copiers;
 static movers_type& movers;
	//Index of curently stored type (if nothing currently stored - points outside of list).
 std :: size_t index;
	//Buffer to store data.
 std :: aligned_storage_t<maxSize, commonAllignment> data;
};

template <class ... Types> template <class ... AnotherTypes> class MyAwsomeVariant <Types...> :: indexRemapper
{
 static_assert(crap :: isPermutationType<std :: is_same, Types...> :: template with <AnotherTypes...> :: value, "Type lists must be at least permutations.");
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

template <class ... Types>
typename MyAwsomeVariant <Types...> :: movers_type&
MyAwsomeVariant <Types...> :: movers = MyAwsomeVariant <Types...> :: getMovers();

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

template <class ... Types> template <class ... AnotherTypes,
	std :: enable_if_t <crap :: allOfType<std :: is_move_constructible, Types...>{}, void*>,
	std :: enable_if_t <crap :: isPermutationType <std :: is_same, Types...> :: template with<AnotherTypes...> :: value, void*> >
MyAwsomeVariant <Types...> :: MyAwsomeVariant(MyAwsomeVariant<AnotherTypes...>&& a) noexcept(MyAwsomeVariant <Types...> :: nothrowMoveable)
	: index(MyAwsomeVariant <Types...> :: indexRemapper <AnotherTypes...> :: getIndexInThis(a.index))
{
 a.moveCurrent(&data);
}

template <class ... Types>
inline MyAwsomeVariant <Types...> :: ~MyAwsomeVariant() noexcept(MyAwsomeVariant <Types...> :: nothrowDestructible)
{
 killCurrent();
}

template <class ... Types> template <class Type, class ... Args>
inline std :: enable_if_t<typename MyAwsomeVariant <Types...> :: template hasType<Type>{}, std :: add_lvalue_reference_t<Type> >
	MyAwsomeVariant <Types...> :: emplace(Args&& ... args)
noexcept(MyAwsomeVariant <Types...> :: nothrowDestructible && std :: is_nothrow_constructible<Type, std :: add_rvalue_reference_t<Args>...>())
{
 killCurrent();
 new (reinterpret_cast<std :: add_pointer_t<Type> >(&data)) Type (std :: forward<Args>(args)...);
 index = crap :: findType<Type, std :: is_same, Types...>();
 return *std :: launder(reinterpret_cast<std :: add_pointer_t<Type> >(&data));
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

template <class ... Types> template <class Type>
void MyAwsomeVariant <Types...> :: moveOnto(void* newData) const noexcept(MyAwsomeVariant <Types...> :: nothrowMoveable)
{
 using ptr = std :: add_pointer_t<Type>;
 using ptr_to_const = std :: add_pointer_t<std :: add_const_t<Type> >;
 new (reinterpret_cast<ptr>(newData)) Type(std :: move(*std :: launder(reinterpret_cast<ptr_to_const>(&data))));
}

template <class ... Types>
inline void MyAwsomeVariant <Types...> :: killCurrent() noexcept(MyAwsomeVariant <Types...> :: nothrowDestructible)
{
 if (index < sizeof...(Types)) (this->*(killers[index]))();
 index = sizeof...(Types);
}

template <class ... Types>
inline void MyAwsomeVariant <Types...> :: copyCurrent(void* newData) const noexcept(MyAwsomeVariant <Types...> :: nothrowCopyable)
{
 if (index < sizeof...(Types)) (this->*(copiers[index]))(newData);
}

template <class ... Types>
inline void MyAwsomeVariant <Types...> :: moveCurrent(void* newData) const noexcept(MyAwsomeVariant <Types...> :: nothrowMoveable)
{
 if (index < sizeof...(Types)) (this->*(movers[index]))(newData);
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

template <class ... Types>
typename MyAwsomeVariant <Types...> :: movers_type& MyAwsomeVariant <Types...> :: getMovers() noexcept
{
 static typename MyAwsomeVariant <Types...> :: movers_type array = {reinterpret_cast<mover_type>(&MyAwsomeVariant <Types...> :: template moveOnto<Types>)...};
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
