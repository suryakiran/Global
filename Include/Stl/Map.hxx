#ifndef Stl_Map_hxx_INCLUDED
#define Stl_Map_hxx_INCLUDED 1

#include <map>
#include <string>

#include <boost/preprocessor/cat.hpp>

#define DEFINE_MAP(key, value, mapName)                       \
  typedef std::map<key, value> mapName;                       \
  typedef mapName::value_type BOOST_PP_CAT (mapName, Value);  \
  typedef mapName::iterator   BOOST_PP_CAT (mapName, Iter);   \
  typedef mapName::const_iterator BOOST_PP_CAT(mapName, IterC)

namespace stl {
  DEFINE_MAP(std::string, std::string, StringMap);
  DEFINE_MAP(int, int, IntMap);
  DEFINE_MAP(int, std::string, IntStringMap);
  DEFINE_MAP(std::string, int, StringIntMap);
}

#include <Stl/Pair.hxx>

#endif
