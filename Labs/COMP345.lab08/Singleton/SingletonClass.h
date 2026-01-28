#pragma once

class SingletonClass{
private:
  int m_value;
  static SingletonClass *s_instance;
  SingletonClass(){
    m_value = 0;
  }

public:
  int get_value(){
    return m_value;
  }
  void increment_value(){
    m_value++;
  }
  static SingletonClass *instance() {
    if (!s_instance)
      s_instance = new SingletonClass();
    return s_instance;
  }

protected:
  virtual ~SingletonClass() {};
};

// Allocating and initializing SingletonClass's
// static data member.  The pointer is being
// allocated - not the object itself.
SingletonClass *SingletonClass::s_instance = 0;
