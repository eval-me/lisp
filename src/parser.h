#include <vector>
#include <string>
#include "types.h"

using namespace std;

#ifndef PARSER_H
#define PARSER_H

namespace lisp {
  /*
    Check if a character is part of a certain lexical group
  */
  bool num(char c);
  bool alpha(char c);

  /* --- Parsing functions --- */
  unique_ptr<Expression> parseSymbol(vector<string> tokens, int index);
  unique_ptr<Expression> parseNumber(vector <string> tokens, int index);
  unique_ptr<Expression> parseAtom(vector<string> tokens, int index);
  unique_ptr<Expression> parseList(vector<string> tokens, int index);
  unique_ptr<Expression> parse(vector<string> tokens);
  
}
#endif
