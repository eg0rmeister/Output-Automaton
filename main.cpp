#include <Automaton.h>
#include <UserInput.h>

int main(){
  Automaton automaton = UserInput::InputAutomaton();

  do {
    std::cout << automaton << std::endl;
  } while (automaton.ApplyAllRules());
  return 0;
}