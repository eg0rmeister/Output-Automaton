#include <fstream>
#include <FileInput.h>

Automaton FileInput::InputAutomaton(std::ifstream& file){
  Automaton automaton = InitializeAutomaton(file);

  InitializeRules(automaton, file);
  return automaton;
}

Automaton FileInput::InitializeAutomaton(std::ifstream& file){
  size_t number_of_variables;
  file >> number_of_variables;

  Automaton automaton;
  automaton = Automaton(GetStartingState(number_of_variables, file));
  return automaton;
}

std::vector<bool> FileInput::GetStartingState(size_t number_of_variables, std::ifstream& file){
  std::vector<bool> starting_state(number_of_variables);
  bool b;
  for (auto value : starting_state){
    file >> b;
    value = b;
  }
  return starting_state;
}

void FileInput::InitializeRules(Automaton& automaton, std::ifstream& file){
  size_t number_of_rules;
  file >> number_of_rules;

  for (size_t i = 0; i < number_of_rules; ++i) {
    InitializeRule(automaton, file);
  }
}

void FileInput::InitializeRule(Automaton& automaton, std::ifstream& file){
  auto condition_indices = InitializeRulePart(file);
    auto output_true_indices = InitializeRulePart(file);
    auto output_false_indices = InitializeRulePart(file);

    automaton.AddRule(condition_indices, output_true_indices, output_false_indices);
}

std::vector<size_t> FileInput::InitializeRulePart(std::ifstream& file)
{
  size_t number_of_elements;
  file >> number_of_elements;
  std::vector<size_t> indices(number_of_elements);

  for(auto& element : indices) {
    file >> element;
  }
  std::cout << std::endl;
  return indices;
}