#include <string>
#include <list>

using namespace std;

namespace lisp {
  class Expression {
  public:
    virtual ~Expression();
  };

  class Symbol : public Expression {
  private:
    string symbol;
  public:
    Symbol(string symbol) {
      this->symbol = symbol;
    }
    virtual string getSymbol() {
      return this->symbol;
    }
  };

  class Number : public Expression {
    // FIXME (probably)
  };

  class Integer : public Number {
  private:
    long long value;
  public:
    Integer(long long value) {
      this->value = value;
    }
    virtual long long getValue() {
      return this->value;
    }
  };

  class Real : public Number {
  private:
    long double value;
  public:
    Real(long double value) {
      this->value = value;
    }
    virtual long double getValue() {
      return this->value;
    }
  };

  class List : public Expression {
  private:
    list<Expression> list;
  public:
    List() {
      
    }
    // FIXME TRANSITION INTO AN ACTUAL LINKED LIST STRUCTURE!!!
    virtual void append(Expression e) {
      this->list.push_back(e);
    }
    // virtual Expression car() {
    //   return list.front();
    // }

    // virtual List cdr() {
    //   return list.
    // }
  };

  // TODO maybe add maps
  
}
