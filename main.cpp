#include <Automaton.h>
#include <UserInput.h>
#include <FileInput.h>
#include <string>
#include <fstream>

int main(){
  std::ifstream file("in.out");
  Automaton automaton = FileInput::InputAutomaton(file);

  do {
    std::cout << automaton << std::endl;
  } while (automaton.ApplyAllRules());
  return 0;
}