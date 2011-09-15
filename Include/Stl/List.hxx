#ifndef STL_LIST_HXX
#define STL_LIST_HXX 1

#include <list>
#include <string>

typedef std::list<std::string> StringList ;
typedef StringList::iterator StringListIter;
typedef StringList::const_iterator StringListIterC;

typedef std::list<int> IntList ;
typedef IntList::iterator IntListIter;
typedef IntList::const_iterator IntListIterC;

typedef std::list<long> LongList ;
typedef LongList::iterator LongListIter;
typedef LongList::const_iterator LongListIterC;

typedef std::list<double> DoubleList ;
typedef DoubleList::iterator DoubleListIter;
typedef DoubleList::const_iterator DoubleListIterC;

typedef std::list<float> FloatList ;
typedef FloatList::iterator FloatListIter;
typedef FloatList::const_iterator FloatListIterC;

#endif
