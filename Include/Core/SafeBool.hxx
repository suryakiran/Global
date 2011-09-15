#ifndef SafeBool_hxx_INCLUDED
#define SafeBool_hxx_INCLUDED

template <class Derived>
struct SafeBool
{
  typedef void (SafeBool::*bool_type) () const;

  operator bool_type() const {
    return 
      static_cast<const Derived*>(this)->bool_test() ? &SafeBool::this_type_does_not_support_comparisons : 0;
  }

  private:
    void this_type_does_not_support_comparisons() const { };
};

#endif
