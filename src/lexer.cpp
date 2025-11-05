#include <string>
#include <vector>
#include <unordered_set>

#include <iostream> // for testing purposes

using namespace std;

namespace lisp {
  vector<string> tokenize(string input) {
    /* -- Define important lexemes -- */
    unordered_set<char> singles = {'(', ')', '\'', ','}; // treated as single chars
    unordered_set<char> quotes = {'"'}; // treated as quotes
    unordered_set<char> specials = {'\\'}; // treated as special character activators
    unordered_set<char> empties = {' ', '\t', '\n', '\0'}; // Treated as spaces;
  
    vector<string> tokens;
    string current;

    bool inQuotes = false;
    bool specialChar = false;
    for (char c : input) {
      // append single lexemes (if not in quotes)
      if (singles.count(c) && !inQuotes) {
	if (!current.empty()) {
	  tokens.push_back(current);
	  current.clear();
	}
	tokens.push_back(string(1, c));
      }
      else if (specials.count(c) && inQuotes) { // Check if special char ahead
	current += c;
	specialChar = true;
      }
      else if (quotes.count(c) && !specialChar) {
	current += c;
	if (inQuotes) {
	  tokens.push_back(current);
	  current.clear();
	  inQuotes = false;
	}
	else inQuotes = true;
      }
      else if (inQuotes) {
	specialChar = false;
	current += c;
      }
      else if (empties.count(c)) {
	if (!current.empty()) {
	  tokens.push_back(current);
	  current.clear();
	}
      }
      else {
	current += c;
      }
    }
    if (!current.empty()) {
      tokens.push_back(current);
      current.clear();
    }
    return tokens;
  }

  void printTokens(vector<string> tokens) {
    cout << "Tokens: ";
    for (string t : tokens) {
      cout << t << " ";
    }
    cout << endl;
  }

  int main() {
    string input;
    getline(cin, input);
    cout << "Your input: " << input << endl;
    printTokens(tokenize(input));
  
  
    return 0;
  }
}
