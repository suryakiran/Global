#ifndef Signals_hxx_INCLUDED
#define Signals_hxx_INCLUDED 1

#include <string>
#include <map>
#include <set>
using namespace std ;

#include <boost/fusion/container.hpp>
#include <boost/fusion/sequence/intrinsic.hpp>
#include <boost/fusion/functional.hpp>
#include <boost/fusion/iterator.hpp>
#include <boost/fusion/include/for_each.hpp>
namespace fusion = boost::fusion;

#include <boost/shared_ptr.hpp>
#include <boost/signals2.hpp>

#define BOOST_SIGNAL(...) boost::shared_ptr< boost::signals2::signal < __VA_ARGS__ > >

class SignalBase
{
	public:
		~SignalBase () { }

		bool blockSignals (void)         { return m_blockSignals ; }
		void blockSignals (bool b) { m_blockSignals = b ; }

	protected:
    SignalBase () 
      : m_blockSignals (false) { }

	private:
		bool m_blockSignals ;
} ;

#endif

