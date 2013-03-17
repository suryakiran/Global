#ifndef SignalBase_hxx_INCLUDED
#define SignalBase_hxx_INCLUDED 1

#include <string>
#include <map>
#include <set>
using namespace std ;

#include <Signals/signal_types.h>

#include <boost/type_traits/remove_reference.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/signals2.hpp>

#include <boost/preprocessor/control/expr_if.hpp>
#include <boost/preprocessor/arithmetic/inc.hpp>
#include <boost/preprocessor/iteration/local.hpp>
#include <boost/preprocessor/punctuation/comma_if.hpp>
#include <boost/preprocessor/repetition/enum_shifted_binary_params.hpp>
#include <boost/preprocessor/repetition/enum_shifted_params.hpp>

#ifndef MAX_SIGNAL_PARAMS
#define MAX_SIGNAL_PARAMS 10
#endif 

#define BOOST_SIGNAL(...) boost::shared_ptr< boost::signals2::signal < __VA_ARGS__ > >
BOOST_MPL_HAS_XXX_TRAIT_DEF(element_type);

namespace detail {
  template <class SmartPtrType, bool b>
  struct element_type_p {
    typedef typename SmartPtrType::element_type value_type;
    typedef typename boost::add_reference<value_type>::type reference_type;
  };

  template <class SmartPtrType>
  struct element_type_p<SmartPtrType, false> {
    typedef typename SmartPtrType::value_type value_type;
    typedef typename SmartPtrType::reference_type reference_type;
  };
  
  template <class SmartPtrType>
  struct element_type {
    static const bool value = has_element_type<SmartPtrType>::value;
    typedef typename element_type_p<SmartPtrType, value>::value_type value_type;
    typedef typename element_type_p<SmartPtrType, value>::reference_type reference_type;
  };
}

template <class derived_class>
class SignalBase
{
  public:
    typedef typename signal::types<derived_class>::type signal_type;
    typedef SignalBase<derived_class> base_type;

  private:
    template<class T> 
      struct get_type                                                   
      {                                                                                  
				typedef typename boost::remove_reference <
					typename fusion::result_of::at_key<signal_type, T>::type>::type smart_ptr_type;
        typedef typename detail::element_type<smart_ptr_type>::reference_type reference_type;
      };                                                                                

    struct initialize                                                                  
    {                                                                                  
      template <typename FusionMapItem>
        void operator() (FusionMapItem& p_item) const
        {
          typedef typename FusionMapItem::second_type SmartPtr;
          typedef typename detail::element_type<SmartPtr>::value_type ItemType ;
          p_item.second = SmartPtr(new ItemType) ;
        }
    };                                                                               

  public:
    SignalBase()
      :m_blockSignals(false)
    {
      fusion::for_each (m_signals, initialize());
    }

    template <class T>                                                                  
      typename get_type<T>::reference_type                                              
      signal (void) { return *(fusion::at_key<T>(m_signals)) ; }           

    virtual ~SignalBase()
    {
    }

		bool blockSignals (void)   { return m_blockSignals ; }
		void blockSignals (bool b) { m_blockSignals = b ; }

#define BOOST_PP_LOCAL_MACRO(n)\
	template<class id BOOST_PP_COMMA_IF(n) BOOST_PP_ENUM_SHIFTED_PARAMS(BOOST_PP_INC(n), typename T)> \
	void emitSignal(BOOST_PP_IF(n,BOOST_PP_ENUM_SHIFTED_BINARY_PARAMS,void BOOST_PP_TUPLE_EAT(3))\
			(BOOST_PP_INC(n), const T, &var))\
	{\
		fusion::fused<typename get_type<id>::reference_type> functionObj (signal<id>()) ;\
		if (blockSignals()) return ;\
		functionObj (fusion::make_vector(BOOST_PP_ENUM_SHIFTED_PARAMS(BOOST_PP_INC(n), var))) ;\
	}

#define BOOST_PP_LOCAL_LIMITS (0, MAX_SIGNAL_PARAMS)
#include BOOST_PP_LOCAL_ITERATE()

  protected:
    signal_type m_signals;

  private:
		bool m_blockSignals ;
};
#endif

