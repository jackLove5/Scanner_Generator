#include <deque>
#include <climits>
#include <string>

#include "NFA.h"
#include "S_NFA.h"
#include "nfa_transition.h"

using namespace std;

/*
 * S_NFA implementation file
 */

const char S_NFA::EPSILON {-1};
const unsigned S_NFA::ERROR {UINT_MAX};

/*
 * Default constructor
 */
S_NFA::S_NFA()
{
  // Create the start state
  start_state_id = 0;
  state_map.push_back({});
}

/*
 * Adds a syntactic category to the S_NFA
 */
void S_NFA::add_category(const NFA& to_add, const string& label)
{
  unsigned size_offset {static_cast<unsigned>(state_map.size())};
  unsigned to_add_start {to_add.get_start_state_id() + size_offset};
  unsigned to_add_end {to_add.get_final_state_id() + size_offset};

  auto to_add_state_map {to_add.get_state_map()}; 
  // Append to_add's states
  for (int i = 0; i < to_add_state_map.size(); i++)
  {
    state_map.push_back(to_add_state_map.at(i));
    for (auto& conn : state_map.back())
    {
      conn.dst_node_id += size_offset;
    }
  }

  // Connect to_add to the start state w/ an epsilon transition
  nfa_transition connect(EPSILON, to_add_start);
  state_map.at(start_state_id).push_front(connect); 

  // Add the new accepted state
  accepted_map[to_add_end] = label;

  // Recently added categories get lowest priority
  priority_map[label] = -((int) priority_map.size());
}

/*
 * S_NFA's transition function
 * If a transition over character c exists
 * between states x and y, delta(x, c) = y
 * returns S_NFA::ERROR if no transition from x exists over c
 */
unsigned S_NFA::delta(unsigned state, char character) const
{
  for (auto t : state_map.at(state))
  {
    if (t.character == character)
    {
      return t.dst_node_id;
    }
  }
  
  return ERROR;
}

/**
 * Returns the set of states reachable by 0 or more epsilon transitions
 */
unordered_set<unsigned> S_NFA::epsilon_closure(unsigned init_state) const
{
  unordered_set<unsigned> result;

  deque<unsigned> work_list {init_state};
  while (!work_list.empty())
  {
    auto current_state {work_list.front()};
    work_list.pop_front();

    result.emplace(current_state);
    for (auto t : state_map[current_state])
    {
      // if an epsilon transition connects to a new state, enqueue the new state
      if (t.character == EPSILON && result.find(t.dst_node_id) == result.end())
        work_list.push_back(t.dst_node_id);
    }
  }

  return result;
}

/*
 * Returns the string that the specified state accepts
 * Returns "" if the state is not an accepting state
 */
string S_NFA::get_accepted_category(unsigned state_id) const
{
  return accepted_map.count(state_id) > 0 ? accepted_map.at(state_id) : "";
}
