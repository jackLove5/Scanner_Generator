#ifndef NFA_TRANSITION
#define NFA_TRANSITION

/*
 * A class representing a transition in a NFA
 */
class nfa_transition
{
  public:
    nfa_transition(char c, unsigned id) :
      character(c), dst_node_id(id) {}
    char character;
    unsigned dst_node_id;
};
#endif
