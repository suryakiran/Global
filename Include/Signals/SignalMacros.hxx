//
// Not putting this piece of code between ifdef guards as this needs to be
// included as and when asked for.
//

SignalsMap m_signals ;                                                             

template<class T> 
struct get_type                                                   
{                                                                                  
	typedef typename boost::remove_reference <
		typename fusion::result_of::at_key<SignalsMap, T>::type>::type
		::reference value_type;
} ;                                                                                

struct initialize                                                                  
{                                                                                  
	template <typename FusionMapItem>
		void operator() (FusionMapItem& p_item) const
		{
			typedef typename FusionMapItem::second_type SmartPtr;
			typedef typename SmartPtr::value_type ItemType ;
			p_item.second = SmartPtr(new ItemType) ;
		}
}  ;                                                                               

public:                                                                                
	template <class T>                                                                  
		typename get_type<T>::value_type                                              
			signal (void) { return *(fusion::at_key<T>(m_signals)) ; }           


#include <Signals/EmitSignalMacro.hxx>
