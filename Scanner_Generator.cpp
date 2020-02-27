/*
 * A scanner generator program
 */

#include <iostream>
#include <fstream>
#include <string>
#include <memory>

#include "DFA.h"
#include "NFA.h"
#include "Regex_Parser.h"

using namespace std;

// Printable alphabet range
static char ALPHABET_START {' '};
static char ALPHABET_END {'~'};

unordered_set<char> printable_alphabet;

unordered_set<char> complete_alphabet {'\f', '\n', '\r', '\t', '\v'};

unordered_map<char, string> char_to_str {{'\f', "\\f"}, {'\n', "\\n"}, 
  {'\r', "\\r",}, {'\t', "\\t"}, {'\v', "\\v"}, {'\\', "\\\\"}};

int main()
{
  // Fill alphabets
  void fill_alphabets();

  fill_alphabets();

  string input_regex;
  S_NFA nfa;

  cout << "> ";
  while (getline(cin, input_regex))
  {
    // Parse the regular expression and create an NFA
    unique_ptr<NFA> nfa_ptr;
    try
    {
      nfa_ptr = Regex_Parser::regex_to_nfa(input_regex);
    }
    catch (std::runtime_error& e)
    {
      // Exit on invalid regex
      cerr << "Invalid Regex\"" << input_regex << "\": " << e.what() << endl;
      exit(-1);
    }

    cout << " > ";
    // Get syntactic category
    string syn_cat;
    if (!getline(cin, syn_cat))
    {
      cerr << "Error. Expected syntactic category for regex:\"" << 
        input_regex << "\"." << endl;
      
      exit(-1);
    }
    
    nfa.add_category(*nfa_ptr, syn_cat);
   
    cout << "> ";
  }

  // Create a the scanner DFA from the nfa and minimize
  DFA scanner {nfa};
  scanner.minimize();

  // Write scanner code to file
  ofstream outfile("Scanner.h"); 
  scanner.generate_scanner(outfile);
  
  outfile.close();
  cout << endl;  

  return 0;
}

void fill_alphabets()
{
  for (char c {ALPHABET_START}; c <= ALPHABET_END; c++)
  {
    printable_alphabet.emplace(c);
    complete_alphabet.emplace(c);
    if (c != '\\')
    {
      char_to_str[c] = c;
    }
  }
}
