#ifndef S_NFA_H
#define S_NFA_H

#include <vector>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <string>

#include "NFA.h"
#include "nfa_transition.h"

/*
 * S_NFA class: Aggregates syntactic categories (represented by NFA objects)
 */
class S_NFA
{
  private:
    // Maps an S_NFA state id to a list containing the state's transitions
    std::vector<std::list<nfa_transition>> state_map;

    // Maps an S_NFA state to the syntactic category label it accepts
    std::unordered_map<unsigned, std::string> accepted_map;
    std::unordered_map<std::string, int> priority_map;
    unsigned start_state_id;

  public:
    static const char EPSILON;
    static const unsigned ERROR;
    
    S_NFA();
    void add_category(const NFA& to_add, const std::string& label);
    unsigned delta(unsigned state, char character) const;
    std::unordered_set<unsigned> epsilon_closure(unsigned initial_state) const;
    std::string get_accepted_category(unsigned state_id) const;
    unsigned get_start_state_id() const { return start_state_id; }
    int get_priority(const std::string& str) const 
      { return priority_map.at(str); }
};

#endif
