#ifndef Stl_Pair_hxx_INCLUDED
#define Stl_Pair_hxx_INCLUDED 1

#include <utility>

namespace stl {
  typedef std::pair<int, int> IntPair;
  typedef std::pair<std::string, std::string> StringPair;
  typedef std::pair<int, std::string> IntStringPair;
  typedef std::pair<std::string, int> StringIntPair;
}

#endif
