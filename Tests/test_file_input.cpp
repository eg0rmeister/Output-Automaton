#include <Automaton.h>
#include <UserInput.h>
#include <GeneralInput.h>

#include <fstream>
#include <cassert>

// test_in_1.test
// starting state: 1 0 0 0 1
// rules: (+i means v_i becomes true, -i means v_i becomes false)
// if (0, 1) then +2
// if (1) then +0
// if (0) then +1
// if () then +3 (always)
// if (3) then -4

void checkStateEqual(std::vector<bool> left, std::vector<bool> right){
  assert(left.size() == right.size());
  for (size_t i = 0; i < left.size(); ++i){
    assert(left[i] == right[i]);
  }
}

int main(){
  std::ifstream file("TestInputs/test_in_1.test");
  Automaton automaton = GeneralInput::InputAutomaton(file);
  checkStateEqual(automaton.GetState(), {1, 0, 0, 0, 1});
  return 0;
}