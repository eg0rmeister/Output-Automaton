#include <Automaton.h>
#include <UserInput.h>
#include <GeneralInput.h>
#include <string>
#include <fstream>

int main(){
  std::ifstream file("in.out");
  Automaton automaton = GeneralInput::InputAutomaton(file);

  do {
    std::cout << automaton << std::endl;
  } while (automaton.ApplyAllRules());
  return 0;
}