#ifndef Stl_Set_hxx_INCLUDED
#define Stl_Set_hxx_INCLUDED 1

#include <set>
#include <string>

#include <boost/preprocessor/cat.hpp>

#define DEFINE_SET(p_type, p_name)                           \
  typedef std::set<p_type> p_name;                           \
  typedef p_name::iterator BOOST_PP_CAT(p_name, Iter);       \
  typedef p_name::const_iterator BOOST_PP_CAT(p_name, IterC)

DEFINE_SET(int,         IntSet);
DEFINE_SET(long,        LongSet);
DEFINE_SET(float,       FloatSet);
DEFINE_SET(double,      DoubleSet);
DEFINE_SET(std::string, StringSet);

#endif
