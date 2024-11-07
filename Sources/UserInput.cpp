#include <UserInput.h>

Automaton UserInput::InputAutomaton(){
  Automaton automaton = InitializeAutomaton();

  InitializeRules(automaton);
  return automaton;
}

Automaton UserInput::InitializeAutomaton(){
  size_t number_of_variables;
  std::cout << "Enter number of variables of the automaton: ";
  std::cin >> number_of_variables;

  char answer;
  std::cout << "Are you going to define starting state? (Y/N): ";
  std::cin >> answer;
  std::cout << std::endl;
  
  Automaton automaton;
  if (answer == 'Y' || answer == 'y'){
    automaton = Automaton(GetStartingState(number_of_variables));
  } else if (answer == 'N' || answer == 'n'){
    automaton = Automaton(number_of_variables);
  }
  std::cout << std::endl;
  return automaton;
}

std::vector<bool> UserInput::GetStartingState(size_t number_of_variables){
  std::vector<bool> starting_state(number_of_variables);
  std::cout << "Enter starting state:";
  bool b;
  for (auto value : starting_state){
    std::cin >> b;
    value = b;
  }
  return starting_state;
}

void UserInput::InitializeRules(Automaton& automaton){
  size_t number_of_rules;
  std::cout << "Enter number of rules you are going to specify: ";
  std::cin >> number_of_rules;

  for (size_t i = 0; i < number_of_rules; ++i) {
    std::cout << "Rule " << i << std::endl;
    std::cout << std::endl;

    InitializeRule(automaton);
  }
}

void UserInput::InitializeRule(Automaton& automaton){
  auto condition_indices = InitializeRulePart(
      "Enter number of condition values: ",
      "Enter indices of variables in condition: "
    );
    auto output_true_indices = InitializeRulePart(
      "Enter number of values that become true if condition is met: ",
      "Enter indices of variables that become true if condition is met: "
    );
    auto output_false_indices = InitializeRulePart(
      "Enter number of values that become false if condition is met: ",
      "Enter indices of variables that become false if condition is met: "
    );

    automaton.AddRule(condition_indices, output_true_indices, output_false_indices);
}

std::vector<size_t> UserInput::InitializeRulePart(
    std::string number_message,
    std::string element_message)
{
  size_t number_of_elements;
  std::cout << number_message;
  std::cin >> number_of_elements;
  std::vector<size_t> indices(number_of_elements);

  std::cout << element_message;
  for(auto& element : indices) {
    std::cin >> element;
  }
  std::cout << std::endl;
  return indices;
}