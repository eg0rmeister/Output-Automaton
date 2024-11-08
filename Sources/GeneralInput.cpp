#include <fstream>
#include <GeneralInput.h>

Automaton GeneralInput::InputAutomaton(std::istream& stream){
  Automaton automaton = InitializeAutomaton(stream);

  InitializeRules(automaton, stream);
  return automaton;
}

Automaton GeneralInput::InitializeAutomaton(std::istream& stream){
  size_t number_of_variables;
  stream >> number_of_variables;

  Automaton automaton;
  automaton = Automaton(GetStartingState(number_of_variables, stream));
  return automaton;
}

std::vector<bool> GeneralInput::GetStartingState(size_t number_of_variables, std::istream& stream){
  std::vector<bool> starting_state(number_of_variables);
  bool b;
  for (auto value : starting_state){
    stream >> b;
    value = b;
  }
  return starting_state;
}

void GeneralInput::InitializeRules(Automaton& automaton, std::istream& stream){
  size_t number_of_rules;
  stream >> number_of_rules;

  for (size_t i = 0; i < number_of_rules; ++i) {
    InitializeRule(automaton, stream);
  }
}

void GeneralInput::InitializeRule(Automaton& automaton, std::istream& stream){
  auto condition_indices = InitializeRulePart(stream);
    auto output_true_indices = InitializeRulePart(stream);
    auto output_false_indices = InitializeRulePart(stream);

    automaton.AddRule(condition_indices, output_true_indices, output_false_indices);
}

std::vector<size_t> GeneralInput::InitializeRulePart(std::istream& stream)
{
  size_t number_of_elements;
  stream >> number_of_elements;
  std::vector<size_t> indices(number_of_elements);

  for(auto& element : indices) {
    stream >> element;
  }
  return indices;
}