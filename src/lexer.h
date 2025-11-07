#include <vector>
#include <string>
#include <unordered_set>
#include <iostream>

using namespace std;

#ifndef LEXER_H
#define LEXER_H
namespace lisp {
  vector<string> tokenize(string input);
  void printTokens(vector<string> tokens);
}
#endif
