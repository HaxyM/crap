#ifndef CRAP_VERSION_VARIABLETEMPLATES
#define CRAP_VERSION_VARIABLETEMPLATES

#ifdef __has_include
#if __has_include(<version>)
#include <version>
#endif
#endif

#ifdef __cpp_variable_templates
#define crap_variable_templates __cpp_variable_templates
#else
#ifdef _MSC_FULL_VER
#if _MSC_FULL_VER >= 190023918L
#define crap_variable_templates _MSVC_LANG
#else
#define crap_variable_templates 0L
#endif
#else
#define crap_variable_templates 0L
#endif
#endif

#endif

