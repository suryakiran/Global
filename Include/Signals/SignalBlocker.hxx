#ifndef SignalBlocker_hxx_INCLUDED
#define SignalBlocker_hxx_INCLUDED

#include <QObject>

class SignalBlocker
{
public:
  SignalBlocker (QObject* p_object)
    : m_qtObject(p_object), m_origSetting(p_object->signalsBlocked())
    {
    }

  ~SignalBlocker()
    {
      if (m_qtObject)
      {
        m_qtObject->blockSignals(m_origSetting);
      }
    }

private:
  QObject* m_qtObject;
  bool m_origSetting;
};

#endif
