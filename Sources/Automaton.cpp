#include <Automaton.h>

Automaton::Automaton(size_t amount_of_variables){
  state = std::vector<bool>(amount_of_variables);
}

Automaton::Automaton(const std::vector<bool>& starting_values){
  state = starting_values;
}

Automaton::Automaton(std::vector<bool>&& starting_values){
  state = std::move(starting_values);
}

bool Automaton::ApplyAllRules(){
  bool changed = false;
  for(const auto& rule : rules){
    changed = ApplyRule(rule) || changed;
  }
  return changed;
}

char Automaton::ApplyFirstRule()
{
  bool changed;
  bool rule_applied;
  for(const auto& rule : rules){
    rule_applied = CheckCondition(rule.condition_indices);
    if(!rule_applied) {
      continue;
    }
    changed = ApplyRule(rule);
    if(changed) {
      return 0; // Rule was applied and a change occured
    }
    return 1; // Rule was applied but no change occured
  }
  return 2; // No rule applied
}

std::vector<bool> Automaton::GetState() const {
  return state;
}

bool Automaton::ApplyRule(const Rule &rule){
  if (!CheckCondition(rule.condition_indices)){
    return false;
  }

  bool changed = false;
  changed = ChangeAtIndices(rule.output_true_indices, true);
  changed = ChangeAtIndices(rule.output_false_indices, false) || changed;

  return changed;
}

bool Automaton::CheckCondition(const std::vector<size_t>& condition) const{
  for (auto index : condition){
    if (!state[index]){
      return false;
    }
  }
  return true;
}

bool Automaton::ChangeAtIndices(const std::vector<size_t>& indices, bool value){
  bool changed = false;
  for (auto index : indices){
    changed = changed || (state[index] ^ value);
    state[index] = value;
  }
  return changed;
}

void Automaton::AddRule(
  std::vector<size_t> condition_indices, 
  std::vector<size_t> output_true_indices, 
  std::vector<size_t> output_false_indices
){
  rules.emplace_back(condition_indices, output_true_indices, output_false_indices);
}

std::ostream &operator<<(std::ostream &stream, const Automaton &automaton)
{
  for (auto value : automaton.GetState()){
    stream << value;
  }
  return stream;
}
