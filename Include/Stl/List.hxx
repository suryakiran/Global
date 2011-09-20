#ifndef Stl_List_hxx_INCLUDED
#define Stl_List_hxx_INCLUDED 1

#include <list>
#include <string>

#include <boost/preprocessor/cat.hpp>

#define DEFINE_LIST(p_type, p_name)                          \
  typedef std::list<p_type> p_name;                          \
  typedef p_name::iterator BOOST_PP_CAT(p_name, Iter);       \
  typedef p_name::const_iterator BOOST_PP_CAT(p_name, IterC)

namespace stl {
  DEFINE_LIST(int,         IntList);
  DEFINE_LIST(long,        LongList);
  DEFINE_LIST(float,       FloatList);
  DEFINE_LIST(double,      DoubleList);
  DEFINE_LIST(std::string, StringList);
}

#endif
