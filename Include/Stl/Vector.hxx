#ifndef STL_VECTOR_HXX
#define STL_VECTOR_HXX 1

#include <vector>
#include <string>

#include <boost/preprocessor/cat.hpp>

#define DEFINE_VECTOR(type, vecName)                           \
  typedef std::vector<type> vecName;                           \
  typedef vecName::iterator BOOST_PP_CAT(vecName, Iter);       \
  typedef vecName::const_iterator BOOST_PP_CAT(vecName, IterC)

DEFINE_VECTOR(int,         IntVec);
DEFINE_VECTOR(long,        LongVec);
DEFINE_VECTOR(double,      DoubleVec);
DEFINE_VECTOR(float,       FloatVec);
DEFINE_VECTOR(std::string, StringVec);

#endif
