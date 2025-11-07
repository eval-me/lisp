#include <string>
#include <vector>
#include <iostream>
#include "lexer.h"
#include "parser.h"
#include "types.h"

using namespace lisp;
using namespace std;

int main() {
  string input;
  getline(cin, input);
  
  cout << "Your input: " << input << endl;
  vector<string> tokens = tokenize(input);
  printTokens(tokens);
  cout << "Parsed output: ";
  parse(tokens)->print();
  cout << endl;
  return 0;
}
