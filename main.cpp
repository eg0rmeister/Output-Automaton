#include <Automaton.h>
#include <UserInput.h>
#include <string>

int main(){
  Automaton automaton = UserInput::InputAutomaton();

  do {
    std::cout << automaton << std::endl;
  } while (automaton.ApplyFirstRule() == 0);
  return 0;
}