#pragma once
#include <vector>
#include <iostream>

class Automaton{
 public:
  /// @brief Constructor with all varriables starting at zero
  /// @param amount_of_variables Total amount of variables
  Automaton(size_t amount_of_variables = 0);

  /// @brief Constructor
  /// @param starting_values Starting state of automaton
  Automaton(const std::vector<bool>& starting_values);

  /// @brief Constructor
  /// @param starting_values Starting state of automaton
  Automaton(std::vector<bool>&& starting_values);

  /// @brief Changes the state of the automaton according to all the rules
  /// @return True if changes did happen
  bool ApplyAllRules();

  /// @brief Changes the state of the automaton according to the first matching rule
  /// @return 0 if a rule was applied and a change happened,
  /// 1 if rule was applied but no changes happened,
  /// 2 if no rule was applied
  char ApplyFirstRule();
  
  /// @brief Adds a rule to the ruleset
  /// @param condition_indices The condition of the rule being applied
  /// @param output_true_indices The variables that must become true if the condition is fulfilled
  /// @param output_false_indices The variables that must become true if the condition is fulfilled
  void AddRule(
    std::vector<size_t> condition_indices, 
    std::vector<size_t> output_true_indices = std::vector<size_t>(),
    std::vector<size_t> output_false_indices = std::vector<size_t>()
  );

  /// @brief Get a copy of state
  /// @return copy of state
  std::vector<bool> GetState() const;

 private:
  struct Rule{
    Rule(
      std::vector<size_t> condition_indices,
      std::vector<size_t> output_true_indices,
      std::vector<size_t> output_false_indices
    ): 
      condition_indices(condition_indices),
      output_true_indices(output_true_indices),
      output_false_indices(output_false_indices) {}
    
    std::vector<size_t> condition_indices;
    std::vector<size_t> output_true_indices;
    std::vector<size_t> output_false_indices;
  };

  /// @brief Changes the state of the automaton according to the rule provided
  /// @param rule the rule to apply
  /// @return true state changed
  bool ApplyRule(const Rule& rule);

  /// @brief Checks that condition is met
  /// @param condition Positions of indices that must be true
  /// @return True if condition is met
  bool CheckCondition(const std::vector<size_t>& condition) const;

  /// @brief Changes the state at indices
  /// @param indices Vector of indices where a change must occur
  /// @param value Value that must be set at indices
  /// @return True if a change occured
  bool ChangeAtIndices(const std::vector<size_t>& indices, bool value);

  std::vector<bool> state;
  std::vector<Rule> rules;
};

std::ostream& operator<<(std::ostream& stream, const Automaton& automaton);