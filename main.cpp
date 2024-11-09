#include <Automaton.h>
#include <UserInput.h>

int main(){
  Automaton automaton = UserInput::InputAutomaton();
  while(true){
    std::cout << "Current state: " << automaton << std::endl;
    std::cout << "Enter action to continue (n - next iteration, q - quit): ";
    char answer;
    std::cin >> answer;
    std::cout << std::endl;
    if (answer == 'q' || answer == 'Q'){
      std::cout << "Quitting by user command" << std::endl;
      break;
    }
    if (answer != 'n' && answer != 'N'){
      std::cout << "Incorrect input" << std::endl;
      continue;
    }
    // answer is 'n' or 'N'
    char automaton_result = automaton.ApplyFirstRule();
    if (automaton_result == 2){
      std::cout << "Automaton stopped execution" << std::endl;
      break;
    }
    if (automaton_result == 1){
      std::cout << "Automaton's state did not change" << std::endl;
      break;
    }
  }
  return 0;
}