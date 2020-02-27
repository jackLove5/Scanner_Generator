#include <iostream>
#include <deque>
#include <climits>
#include <string>

#include "DFA.h"
#include "NFA.h"
#include "S_NFA.h"
#include "DFA_State.h"
#include "dfa_transition.h"

/*
 * DFA implementation file
 */

using namespace std;

extern unordered_set<char> complete_alphabet;
extern unordered_map<char, string> char_to_str;

const DFA_State DFA::ERROR {{}};

string DFA::get_accepted_category(const S_NFA& nfa, 
    const unordered_set<unsigned>& dfa_state)
{
  /*
   * If dfa_state is an accepting state, accept the category w/ the highest
   * priority
   */
  string res {""};
  int curr_priority {INT_MIN};
  for (auto x : dfa_state)
  {
    string accepted {""};
    if ((accepted = nfa.get_accepted_category(x)) != "")
    {
      priority_map[accepted] = nfa.get_priority(accepted);
      if (nfa.get_priority(accepted) > curr_priority)
      {
        res = accepted;
        curr_priority = nfa.get_priority(accepted);
      }
    }
  }

  return res;
}

/*
 * Constructs a DFA from an S_NFA
 * Implements the "subset construction"
 * algorithm
 */
DFA::DFA(const S_NFA& nfa)
{
  unordered_map<unsigned, unordered_set<unsigned>> e_closure_cache;
 
  // unordered_set representing the dfa's start state
  auto start_set {nfa.epsilon_closure(nfa.get_start_state_id())};

  e_closure_cache[nfa.get_start_state_id()] = start_set;

  // Create new DFA start state and add accepted category if necessary
  start_state = DFA_State(start_set);

  auto accepted_category {get_accepted_category(nfa, start_set)};
  if (!accepted_category.empty())
  {
    accepted_map[start_state] = accepted_category;
  }
  
  deque<unordered_set<unsigned>> work_list {start_set};

  // Do the subset construction algorithm
  while (!work_list.empty())
  {
    auto curr_dfa_state {work_list.front()};
    work_list.pop_front();

    // Add all outgoing transitions for the current dfa state
    for (auto c : complete_alphabet)
    {
      // Construct the destination state over character c
      // This is the union of epsilon closures of delta(si, c)
      unordered_set<unsigned> dst_set;
      for (auto nfa_state : curr_dfa_state)
      {
        if (nfa.delta(nfa_state, c) != NFA::ERROR) 
        {
          unsigned dst {nfa.delta(nfa_state, c)};

          unordered_set<unsigned> e_closure;
          if (e_closure_cache.count(dst) == 0)
          {
            e_closure = nfa.epsilon_closure(dst);
            e_closure_cache[dst] = e_closure;
          }
          else
          {
            e_closure = e_closure_cache[dst];
          }
 
          for (auto x : e_closure)
          {
            dst_set.emplace(x);
          }
        }
      }

      DFA_State dst_state(dst_set);
      if (dst_state != DFA::ERROR)
      {
        // Record the transition
        state_map[curr_dfa_state].push_front({c, dst_state});

        // Create an entry for and add it to the worklist 
        // if we haven't seen it before
        if (state_map.find(dst_state) == state_map.end())
        {
          work_list.push_back(dst_set);
          state_map[dst_state] = {};
          auto accepted_category {get_accepted_category(nfa, dst_set)};
          if (!accepted_category.empty())
          {
            accepted_map[dst_state] = accepted_category;
          }
        }
      }
    }
  }
}

/*
 * Minimizes the DFA
 * Performs hopcroft's then rebuilds the dfa from the set parition
 */
void DFA::minimize()
{
  // Do Hopcroft's algorithm and get the resulting set partition
  auto set_partition {hopcroft()};

  // Rebuild the DFA
  unordered_map<DFA_State, list<dfa_transition>> new_state_map;
 
  /*
   * Each element of the set partition is a state in the new DFA.
   * New state ids are set to their location in the set partition to guarantee
   * uniqueness
   */
  DFA_State new_start({0});
  unordered_map<DFA_State, string> new_accepted_map;
 
  /*
   * Fill transitions
   */
  for (size_t i{0}; i < set_partition.size(); i++)
  {
    DFA_State new_state({static_cast<unsigned>(i)});
    new_state_map[new_state] = {};

    // for all old DFA_States in the set
    for (auto element : set_partition.at(i))
    {
      // Add to the new DFA's accepted map if needed
      if (accepted_map.find(element) != accepted_map.end())
      {
        new_accepted_map[new_state] = accepted_map[element]; 
      }

      // Update the new DFA's starting state id if needed
      if (element == start_state)
      {
        new_start = new_state;
      }

      // Add transitions to the new DFA
      for (auto t : state_map[element])
      {
        auto dst_index {get_loc(set_partition, t.dst_node_id) - 
          set_partition.begin()};
        
        DFA_State dst_state = DFA_State({static_cast<unsigned>(dst_index)});

        if (delta(new_state_map, new_state, t.character) ==
            DFA::ERROR)
        {
          new_state_map[new_state].push_front({t.character, dst_state});
        }
      }
    }
  }

  // Replace all fields
  start_state = new_start;
  state_map = new_state_map;
  accepted_map = new_accepted_map;
}

/*
 * Perform Hopcroft's algorithm
 * returns the resulting set partition
 */
vector<unordered_set<DFA_State>> DFA::hopcroft()
{
  /*
   * Initialize the set partition
   * Two states are in the same subset if they are either both
   * not accepting states or if they accept the same category
   */

  cout << "state count: " << state_map.size() << endl;
  unordered_map<string, unordered_set<DFA_State>> accepting_states;
  unordered_set<DFA_State> not_accepting_states;

  for (auto p : state_map)
  {
    if (accepted_map.find(p.first) == accepted_map.end())
    {
      not_accepting_states.emplace(p.first);
    }
    else
    {
      string accepted_str {accepted_map[p.first]};
      accepting_states[accepted_str].emplace(p.first);
    }
  }

  list<unordered_set<DFA_State>> set_partition;
  
  /*
   * keys: p, c
   * value: set of all states for which a transition over c leads to a state
   * in the set at *p
   */
  unordered_map<unordered_set<DFA_State>*, 
    unordered_map<char, unordered_set<DFA_State>>> x_map;

  for (auto p : accepting_states)
  {
    set_partition.push_back(p.second);
  }

  // Make sure no subsets are empty (precondition for Hopcroft)
  if (!not_accepting_states.empty())
  {
    set_partition.push_back(not_accepting_states);
  }

 /*
  * Preprocess x_map values
  */ 
  auto W = set_partition;
  for (auto& st : W)
  {
    auto s = &st;
    for (auto& p : state_map)
    {
      auto& state = p.first;
      for (auto& t : p.second)
      {
        if (s->find(t.dst_node_id) != s->end())
        {
          x_map[s][t.character].emplace(state);
        }
      }
    }
  }

  while (!W.empty())
  {
    cout << "P: " << set_partition.size() << endl;
    cout << "W: " << W.size() << endl;
    // Choose and remove a set A from W
    unordered_set<DFA_State>* A {&W.back()};
    W.pop_back();
  
    for (auto c : complete_alphabet)
    {
      /*
       * Let X be the set of states for which a transition on c
       * leads to a state in A
       */
      unordered_set<DFA_State> X {x_map[A][c]};

      x_map[A][c].clear();
      for (auto& Y : set_partition)
      {
        auto inter {set_intersection(X, Y)};
        auto diff {set_difference(Y, X)};
        if (!inter.empty() && !diff.empty())
        {
          unordered_set<DFA_State> y_cpy {Y}; 
          
          // Replace Y in P by the two sets
          Y = inter;
          set_partition.push_back(diff);
          
          unordered_map<char, unordered_set<DFA_State>> inter_x;
          unordered_map<char, unordered_set<DFA_State>> diff_x;

          
          if (std::find(W.begin(), W.end(), y_cpy) != W.end())
          {      
            auto it = std::find(W.begin(), W.end(), y_cpy);
            auto y_ptr = &(*it);
            for (auto c : complete_alphabet)
            {
              for (auto& state : x_map[y_ptr][c])
              {
                {
                  if (inter.find(delta(state,c)) != inter.end())
                  {
                    inter_x[c].emplace(state);
                  }
                  else if (diff.find(delta(state,c)) != diff.end())
                  {
                    diff_x[c].emplace(state);
                  }
                }
              }
            }
          }
          else
          {
            for (auto& p : state_map)
            {
              auto& state = p.first;
              for (auto& t : p.second)
              {
                if (inter.find(t.dst_node_id) != inter.end())
                {
                  inter_x[t.character].emplace(state);
                }
                else if (diff.find(t.dst_node_id) != diff.end())
                {
                  diff_x[t.character].emplace(state);
                }
              }
            }
          }

          list<unordered_set<DFA_State>>::iterator it;
          // If Y is in W
          if ((it = std::find(W.begin(), W.end(), y_cpy)) != W.end())
          {
            // Replace Y in W by the same two sets
            unordered_set<DFA_State>* ptr {&(*it)};
            x_map[ptr].clear();
            W.erase(it);
            
            W.push_back(inter);
            x_map[&W.back()] = inter_x;
            W.push_back(diff);
            x_map[&W.back()] = diff_x;
          }
          else
          {
            // Insert the smaller of the two sets
            if (inter.size() <= diff.size())
            {
              W.push_back(inter);
              x_map[&W.back()] = inter_x;
            }
            else
            {
              W.push_back(diff);
              x_map[&W.back()] = diff_x;
            }
          }
        }
      }
    }
  }
  
  return vector<unordered_set<DFA_State>>
    (set_partition.begin(), set_partition.end());
}

unordered_set<DFA_State> DFA::set_difference(const unordered_set<DFA_State>&
    first, const unordered_set<DFA_State>& second)
{
  auto res {first};
  for (auto& s : second)
  {
    if (res.find(s) != res.end())
    {
      res.erase(s);
    }
  }

  return res;
}

unordered_set<DFA_State> DFA::set_intersection(const unordered_set<DFA_State>&
    first, const unordered_set<DFA_State>& second)
{
  unordered_set<DFA_State> res;
  for (auto& s : first)
  {
    if (second.find(s) != second.end())
    {
      res.emplace(s);
    }
  }

  return res;
}

/*
 * Returns iterator pointing to the element containing the value search
 */
vector<unordered_set<DFA_State>>::iterator
  DFA::get_loc(vector<unordered_set<DFA_State>>& set_partition,
    DFA_State search)
{
  auto ret {set_partition.begin()};
  for (; ret != set_partition.end(); ret++)
  {
    if (ret->find(search) != ret->end())
      return ret;
  }

  return ret;
}

/*
 * DFA's transition function
 * If a transition over character c exists
 * between states x and y, delta(x, c) = y
 * returns DFA::ERROR if no transition from x exists over c
 */
DFA_State DFA::delta(const DFA_State& state, char character)
{
  for (const auto& t : state_map[state])
  {
    if (t.character == character)
    {
      return t.dst_node_id;
    }
  }

  return DFA::ERROR;
}

/*
 * Overload that accepts any state map
 * (for use only in the minimize function)
 */
DFA_State DFA::delta(unordered_map<DFA_State, 
    list<dfa_transition>>& s_map, DFA_State state, char character)
{
  for (auto t : s_map[state])
  {
    if (t.character == character)
    {
      return t.dst_node_id;
    }
  }

  return DFA::ERROR;
}


unordered_map<DFA_State, vector<pair<char, char>>> DFA::get_t_ranges(
    const DFA_State& start)
{
  auto& t_list {state_map[start]};
  vector<dfa_transition> t_vec = vector<dfa_transition>
    (t_list.begin(), t_list.end());

  // Sort by dst nodes, then characters 
  std::sort(t_vec.begin(), t_vec.end(), 
      [](dfa_transition& t1, dfa_transition& t2) {
      if (t1.dst_node_id == t2.dst_node_id)
      {
        return t1.character < t2.character;
      }
      else
      {
        return t1.dst_node_id < t2.dst_node_id;
      }
  });
  
  // Map destination states to list of character ranges
  unordered_map<DFA_State, vector<pair<char, char>>> res;
  int lo {0};
  while (lo < t_vec.size())
  {
    int hi {lo + 1};
    // elements in [lo...hi) have the same dst node
    while (hi < t_vec.size() && t_vec[hi].dst_node_id == t_vec[lo].dst_node_id)
    {
      hi++;
    }

    res[t_vec[lo].dst_node_id] = {};
    for (int r_begin {lo}; r_begin < hi;)
    {
      // invariant: elements in [r_begin...r_end) have sequential characters
      int r_end {r_begin + 1};
      while (r_end < hi && t_vec[r_end].character - 1 == 
          t_vec[r_end-1].character)
      {
        r_end++;
      }

      res[t_vec[lo].dst_node_id].push_back(make_pair(t_vec[r_begin].character, 
            t_vec[r_end-1].character));

      r_begin = r_end;
    }

    lo = hi;
  }

  return res; 
}

/*
 * Output scanner code
 */
void DFA::generate_scanner(std::ofstream& file)
{
  file << "// Auto-generated code\n\n";
  file << "#include <iostream>\n";
  file << "#include <stack>\n";
  file << "#include <string>\n";
  file << "#include <fstream>\n";
  file << "#include <vector>\n";
  file << "#include <unordered_map>\n\n";
  file << "class Scanner\n{\n";

  // Map accepting states to their syntactic categories
  file << "  private:\n    std::unordered_map<unsigned, std::string> " <<
    "accepted_map {\n";

  int i {0};
  for (auto& p : accepted_map)
  {
    file << "       {" << p.first << ", \"" << p.second;

    if (i == accepted_map.size() - 1)
    {
      file << "\"}\n";
    }
    else
    {
      file << "\"},\n";
    }

    i++;
  }

  file << "     };\n\n";

  // DFA code
  file << "     std::pair<std::string, std::string> get_lex(std::ifstream& ";
  file << "in_stream)\n";
  file << "     {\n";
  file << "       std::string lexeme {""};\n";
  file << "       std::stack<unsigned> s;\n\n";
  file << "       char c;\n";
  file << "       goto s" << start_state << ";\n";

  // Each DFA state
  for (auto& s : state_map)
  {
    file << "s" << s.first << ":\n";
    // Clear the stack on accepting states
    if (accepted_map.count(s.first) > 0)
    {
      file << "        s = std::stack<unsigned>();\n";
    }

    file << "       s.push(" << s.first << ");\n";
    file << "       if (!in_stream.get(c))\n";
    file << "       {\n";
    file << "         lexeme = lexeme + \" \";\n";
    file << "         goto sout;\n";
    file << "       }\n";
    file << "       lexeme = lexeme + c;\n\n";
    auto t_ranges {get_t_ranges(s.first)};
    
    int i {0};
    for (auto& p : t_ranges)
    {
      if (i == 0)
      {
        file << "       if (";
      }
      else
      {
        file << "       else if (";
      }

      for (int j {0}; j < p.second.size(); j++ )
      {
        auto& range {p.second[j]};
        string first = char_to_str[range.first];
        string last = char_to_str[range.second];

        if (first == last)
        {
          file << "c  == \'" << first << "\' ";
        }
        else
        {
          file << "c >= \'" << first << "\' && c <= \'" << last;
          file << "\' ";
        }

        if (j < p.second.size() - 1)
        {
          file << "|| ";
        }
        else
        {
          file << ") goto s" << p.first << ";\n";
        }
      }
      
      i++;
    }

    if (!t_ranges.empty())
    {
      file << "       else goto sout;\n";
    }
    else
    {
      file << "       goto sout;\n";
    }
  }

  // sout
  file << "sout:\n";
  file << "       s.push(-1);\n";
  file << "       std::string old {lexeme};\n";
  file << "       do\n";
  file << "       {\n";
  file << "         s.pop();\n";
  file << "         if (in_stream.eof())\n";
  file << "         {\n";
  file << "           in_stream.clear();\n";
  file << "         }\n";
  file << "         else\n";
  file << "         {\n";
  file << "           in_stream.unget();\n";
  file << "         }\n";
  file << "         lexeme = lexeme.substr(0, lexeme.length() - 1);\n";
  file << "       } while (!s.empty() && accepted_map.count(s.top()) == 0);\n\n";

  file << "if (!s.empty() && accepted_map.count(s.top()) > 0)\n";
  file << "         return make_pair(accepted_map[s.top()], lexeme);\n";
  file << "       else\n         return make_pair(\"\", old);\n";
  file << "       }\n\n";
 
  // scan method 
  file << "  public:\n\n";
  file << "  std::vector<std::pair<std::string, std::string>> scan(";
  file << "std::ifstream& stream)\n";
  file << "{\n";
  file << "    std::vector<std::pair<std::string, std::string>> res_vec;\n";
  file << "    std::pair<std::string, std::string> res;\n\n";
  file << "    do\n    {\n     res = get_lex(stream);\n";
  file << "     res_vec.push_back(res);\n";
  file << "    } while (stream.peek() != EOF && res.first != \"\");\n\n";
  file << "    stream.close();\n";
  file << "    if (res.first == \"\")\n    {\n     std::cerr << \"Scanner";
  file << " error: couldn't recognize token \" << res.second\n";
  file << "       << std::endl;\n";
  file << "     return {};\n    }\n    else\n    {\n     return res_vec;\n";
  file << "    }\n   }\n};";
}

void DFA::print()
{
  for (auto p : state_map)
  {
    cout << "STATE " << p.first << ": ";
    for (auto conn : p.second)
      cout << '(' << conn.character << ", " << conn.dst_node_id << ") ";
    cout << endl;

    if (p.first == start_state)
      cout << "START STATE" << endl;

    if (accepted_map.find(p.first) != accepted_map.end())
    {
      cout << "ACCEPTING STATE " << endl;
    }

    cout << endl;
  }
}
