
#ifndef CMAKE_IS_FUN
#error Expect CMAKE_IS_FUN definition
#endif

#if CMAKE_IS != Fun
#error Expect CMAKE_IS=Fun definition
#endif


template<bool test>
struct CMakeStaticAssert;

template<>
struct CMakeStaticAssert<true> {};

static const char fun_string[] = CMAKE_IS_;
#ifndef NO_SPACES_IN_DEFINE_VALUES
static const char very_fun_string[] = CMAKE_IS_REALLY;
#endif

enum {
  StringLiteralTest1 = sizeof(CMakeStaticAssert<sizeof(CMAKE_IS_) == sizeof("Fun")>)
#ifndef NO_SPACES_IN_DEFINE_VALUES
  ,
  StringLiteralTest2 = sizeof(CMakeStaticAssert<sizeof(CMAKE_IS_REALLY) == sizeof("Very Fun")>)
#endif
};

#ifdef TEST_GENERATOR_EXPRESSIONS
#ifndef CMAKE_IS_DECLARATIVE
#error Expect declarative definition
#endif
#ifdef GE_NOT_DEFINED
#error Expect not defined generator expression
#endif

#ifndef ARGUMENT
#error Expected define expanded from list
#endif
#ifndef LIST
#error Expected define expanded from list
#endif

// TEST_GENERATOR_EXPRESSIONS
#endif

#ifndef BUILD_IS_DEBUG
# error "BUILD_IS_DEBUG not defined!"
#endif
#ifndef BUILD_IS_NOT_DEBUG
# error "BUILD_IS_NOT_DEBUG not defined!"
#endif

// Check per-config definitions.
#ifdef TEST_CONFIG_DEBUG
# if !BUILD_IS_DEBUG
#  error "BUILD_IS_DEBUG false with TEST_CONFIG_DEBUG!"
# endif
# if BUILD_IS_NOT_DEBUG
#  error "BUILD_IS_NOT_DEBUG true with TEST_CONFIG_DEBUG!"
# endif
#else
# if BUILD_IS_DEBUG
#  error "BUILD_IS_DEBUG true without TEST_CONFIG_DEBUG!"
# endif
# if !BUILD_IS_NOT_DEBUG
#  error "BUILD_IS_NOT_DEBUG false without TEST_CONFIG_DEBUG!"
# endif
#endif

int main(int argc, char **argv)
{
  return 0;
}
