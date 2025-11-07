#pragma once

#include <string>
#include <memory>

namespace lisp {
  
  /* Expression definition */
  
  class Expression {
  public:
    virtual ~Expression() = default;
    virtual void print() = 0;
  };

  /* Symbol definition */
  
  class Symbol : public Expression {
  private:
    std::string m_Identifier;
  public:
    Symbol(std::string id);
    std::string getSymbol();
    void print() override;
  };

  /* Number definition */
  
  class Number : public Expression {
  public:
    virtual ~Number() = default;    
  };

  /* Integer definition */
  
  class Integer : public Number {
  private:
    long long m_Value;
  public:
    Integer(long long value);
    long long getValue();
    void print() override;
  };

  /* Real definition */
  
  class Real : public Number {
  private:
    long double m_Value;
  public:
    Real(long double value);
    long double getValue();
    void print() override;
  };

  /* List definition */
  
  class List : public Expression {
  private:
    std::unique_ptr<Expression> m_Head;
    std::unique_ptr<List> m_Tail;
  public:
    void append(std::unique_ptr<Expression> e);
    Expression *car();
    List *cdr();
    void print(bool start);
    void print() override;
  };
  
}
