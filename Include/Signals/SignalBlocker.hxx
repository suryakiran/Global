#ifndef SignalBlocker_hxx_INCLUDED
#define SignalBlocker_hxx_INCLUDED

class SignalBlocker
{
  public:
    SignalBlocker (SignalBase* p_object)
      : m_boostObject(p_object), m_origSetting(p_object->blockSignals())
    {
      m_qtObject = 0;
    }

    SignalBlocker (QObject* p_object)
      : m_qtObject(p_object), m_origSetting(p_object->blockSignals())
    {
      m_boostObject = 0;
    }

    ~SignalBlocker()
    {
      if (m_boostObject)
      {
        m_boostObject->blockSignals(m_origSetting);
      }
      else if (m_qtObject)
      {
        m_qtObject->blockSignals(m_origSetting);
      }
    }

  private:
    SignalBase* m_boostObject;
    QObject* m_qtObject;

    bool m_origSetting;
}

#endif
