#include <Automaton.h>
#include <UserInput.h>
#include <GeneralInput.h>

#include <fstream>
#include <cassert>

// test_in_2.test
// starting state: 0 0
// rules: (+i means v_i becomes true, -i means v_i becomes false)
// if (0) then +1 -0
// if (1) then +0 -1

void checkStateEqual(std::vector<bool> left, std::vector<bool> right){
  assert(left.size() == right.size());
  for (size_t i = 0; i < left.size(); ++i){
    assert(left[i] == right[i]);
  }
}

int main(){
  std::ifstream file("TestInputs/test_in_2.test");
  Automaton automaton = GeneralInput::InputAutomaton(file);
  checkStateEqual(automaton.GetState(), {0, 1});
  assert(automaton.ApplyFirstRule() == 0);
  checkStateEqual(automaton.GetState(), {1, 0});
  assert(automaton.ApplyFirstRule() == 0);
  checkStateEqual(automaton.GetState(), {0, 1});
  assert(automaton.ApplyFirstRule() == 0);
  checkStateEqual(automaton.GetState(), {1, 0});
  assert(automaton.ApplyFirstRule() == 0);
  return 0;
}