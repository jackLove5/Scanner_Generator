#ifndef NFA_H
#define NFA_H

#include <vector>
#include <list>
#include <unordered_set>
#include <memory>

#include "nfa_transition.h"

/*
 * A class representing an NFA.
 * Implemented using adjacency lists
 */
class NFA
{
  private:
    // Maps an NFA state id to a list containing the state's transitions
    std::vector<std::list<nfa_transition>> state_map;

    unsigned final_state_id;
    unsigned start_state_id;

  public:
    static const char EPSILON;
    static const unsigned ERROR;
    
    /*
     * Constructs an nfa from a single character
     */ 
    NFA(char c);
  
    /*
     * Construct an NFA corresponding to the disjunction of both operands'
     * regular expressions
     */
    void disjunction(const std::unique_ptr<NFA>& other);
    
    /*
     * Constructs an NFA corresponding to the concatenation of both operands'
     * regular expressions
     */
    void concatenate(const std::unique_ptr<NFA>& other);
    
    /*
     * Construct the NFA corresponding to the closure of the current NFA's
     * regular expression
     */
    void closure();
    
    /*
     * NFA's transition function.
     * If a transition over character c exists
     * between states x and y, delta(x, c) = y
     * returns NFA::ERROR if no transition from x exists of c
     */
    unsigned delta(unsigned state, char character) const;
    
    /*
     * Returns the set of states reachable by 0 or more epsilon transitions
     */
    std::unordered_set<unsigned> epsilon_closure(unsigned initial_state) const;
    /*
     * Returns the state id of the NFA's final state
     */ 
    unsigned get_final_state_id() const { return final_state_id; }
    
    /*
     * Returns the state id of the NFA's start state
     */
    unsigned get_start_state_id() const { return start_state_id; }
    const std::vector<std::list<nfa_transition>>& get_state_map() const
      { return state_map; }
};

#endif
