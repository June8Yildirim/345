#pragma once
#include<iostream>
#include<string>

using namespace std;

class Pizza{
public:
  //Set all parts of the Product, and use the Product
  void setDough(const string& dough) {
    m_dough = dough;
  }
  void setSauce(const string& sauce) {
    m_sauce = sauce;
  }
  void setTopping(const string& topping) {
    m_topping = topping;
  }
  void open() const {
    cout << "Pizza with " << m_dough
	 << " dough, " << m_sauce << " sauce and "
	 << m_topping << " topping. Mmm." << endl;
  }
private:
  //Parts of the Product
  string m_dough;
  string m_sauce;
  string m_topping;
};

