#include <memory>
#include <vector>
#include <string>
#include <iostream>
#include "types.h"

using namespace std;

namespace lisp {
  bool num(char c) {
    if ('0' <= c && c <= '9') return true;
    return false;
  }
  bool alpha(char c) {
    if (('a' <= c && c <= 'z') ||
	('A' <= c && c <= 'Z') ||
	c == '"') return true;
    return false;
  }

  unique_ptr<Expression> parseSymbol(vector<string> tokens, int *index) {
    string tok = tokens[*index];
    return make_unique<Symbol>(tok);
  }

  unique_ptr<Expression> parseNumber(vector <string> tokens, int *index) {
    string tok = tokens[*index];
    unique_ptr<Number> num;
    if (tok.find('.') < tok.size()) // If it has a decimal place, treat it as a real number!
      num.reset(new Real(stold(tok)));
    else
      num.reset(new Integer(stoll(tok)));
    return num;
  }
  
  unique_ptr<Expression> parseAtom(vector<string> tokens, int *index) {
    unique_ptr<Expression> expr;
    if (alpha(tokens[*index][0])) expr = parseSymbol(tokens, index);
    else if (num(tokens[*index][0])) expr = parseNumber(tokens, index);
    // else error!
    // (*index)++;
    return expr;
  }

  unique_ptr<Expression> parseList(vector<string> tokens, int *index) {
    if (*index >= tokens.size()) return nullptr;
   
    string tok = tokens[*index];

    if (tok == "(") {
      (*index)++;
      unique_ptr<List> l = make_unique<List>();      
      while (tokens[*index] != ")") {
	l->append(parseList(tokens, index));
      }
      (*index)++;
      return l;
    }
    else if (tok == ")") {
      return nullptr;
    }
    else { // If it's an atom
      unique_ptr<Expression> ret = parseAtom(tokens, index);
      (*index)++;
      return ret;
    }
  }
  
  unique_ptr<Expression> parse(vector<string> tokens) {
    unique_ptr<Expression> ast;
    if (tokens.empty()) {
      // TODO
      // throw new EmptyExpressionException();
    }
    int index = 0;
    if (tokens[0] == "(") {
      ast = parseList(tokens, &index);
    }
    else
      ast = parseAtom(tokens, &index);
    return ast;
  }
}
