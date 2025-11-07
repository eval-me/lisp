#include <string>
#include <iostream>
#include <memory>

#include "types.h"

using namespace std;

namespace lisp {
  /* Expression functions */
  /* Empty, interface */

  /* Symbol functions */
  
  Symbol::Symbol(std::string id) : m_Identifier(id) {}
  
  string Symbol::getSymbol() {
    return this->m_Identifier;
  }
  void Symbol::print() {
    cout << this->getSymbol() << " ";
  }

  /* Number functions */
  /* Empty, interface */

  /* Integer functions */
  
  Integer::Integer(long long value) : m_Value(value) {}
  
  long long Integer::getValue() {
    return this->m_Value;
  }
  void Integer::print() {
    cout << this->getValue() << " ";
  }

  /* Real Functions */
  
  Real::Real(long double value) : m_Value(value) {}
  
  long double Real::getValue() {
    return this->m_Value;
  }
  
  void Real::print() {
    cout << this->getValue() << " ";
  }

  void List::append(unique_ptr<Expression> e) {
    if (!this->m_Head) {
      this->m_Head = std::move(e);
    }
    else if (!this->m_Tail) {
      this->m_Tail = make_unique<List>();
      this->m_Tail->append(std::move(e));
    }
    else {
      this->m_Tail->append(std::move(e));
    }
  }

  Expression* List::car() {
    return this->m_Head.get();
  }

  List* List::cdr() {
    return this->m_Tail.get();
  }

  void List::print(bool start) {
    if (start)
      cout << "(";
    if (m_Head)
      m_Head->print();
    if (m_Tail)
      m_Tail->print(false);
    if (start)
      cout << ")";
  }

  void List::print() {
    this->print(true);
  }
}
  

