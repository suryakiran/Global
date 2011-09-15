#ifndef STL_SET_HXX
#define STL_SET_HXX 1

#include <set>
#include <string>

typedef std::set<std::string> StringSet ;
typedef StringSet::iterator StringSetIter;
typedef StringSet::const_iterator StringSetIterC;

typedef std::set<int> IntSet ;
typedef IntSet::iterator IntSetIter;
typedef IntSet::const_iterator IntSetIterC;

typedef std::set<long> LongSet ;
typedef LongSet::iterator LongSetIter;
typedef LongSet::const_iterator LongSetIterC;

typedef std::set<double> DoubleSet ;
typedef DoubleSet::iterator DoubleSetIter;
typedef DoubleSet::const_iterator DoubleSetIterC;

typedef std::set<float> FloatSet ;
typedef FloatSet::iterator FloatSetIter;
typedef FloatSet::const_iterator FloatSetIterC;

#endif
