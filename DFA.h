#ifndef DFA_H
#define DFA_H

#include <vector>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <fstream>

#include "S_NFA.h"
#include "dfa_transition.h"
#include "DFA_State.h"

class DFA
{
  private:
    std::unordered_map<DFA_State, std::list<dfa_transition>> state_map;
    std::unordered_map<DFA_State, std::string> accepted_map;
    std::unordered_map<std::string, int> priority_map;
    DFA_State start_state;

/*
     * Perform Hopcroft's algorithm
     * returns the resulting set partition
     */
    std::vector<std::unordered_set<DFA_State>> hopcroft();
    
    std::string get_accepted_category
      (const S_NFA& nfa, const std::unordered_set<unsigned>& dfa_state);

    std::unordered_set<DFA_State> set_intersection
      (const std::unordered_set<DFA_State>& first,
        const std::unordered_set<DFA_State>& second);

    std::unordered_set<DFA_State> set_difference
      (const std::unordered_set<DFA_State>& first,
        const std::unordered_set<DFA_State>& second);
 
    std::vector<std::unordered_set<DFA_State>>::iterator
      get_loc(std::vector<std::unordered_set<DFA_State>>& partition,
        DFA_State search);

    DFA_State delta(std::unordered_map<DFA_State, 
        std::list<dfa_transition>>&, DFA_State, char);
    
    std::unordered_map<DFA_State, std::vector<std::pair<char, char>>> 
      get_t_ranges(const DFA_State& start);

  public:
    DFA(const S_NFA& nfa);
    DFA_State delta(const DFA_State& , char character) ;
    void minimize();
    void generate_scanner(std::ofstream& file);
    void print();

    static const DFA_State ERROR;
};

#endif
