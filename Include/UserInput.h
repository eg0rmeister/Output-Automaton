#include <iostream>
#include <Automaton.h>

class UserInput{
 public:
  /// @brief Constructs automaton using user inputs
  /// @return Constructed automaton
  static Automaton InputAutomaton();
 
 private:
  /// @brief Creates a vector of integers according to user input
  /// @param number_message Message to output before inputting size of vector
  /// @param element_message Message to output before inputting elements of vector
  /// @return Constructed vector
  static std::vector<size_t> InitializeRulePart(
    std::string number_message,
    std::string element_message
  );

  /// @brief Adds a user-defined rule to automaton
  /// @param automaton Automaton to modify
  static void InitializeRule(Automaton& automaton);

  /// @brief Adds user-defined rules to automaton
  /// @param automaton Automaton to modify
  static void InitializeRules(Automaton& automaton);

  /// @brief Gets starting state vector from user input
  /// @param number_of_variables Amount of variables in automaton
  /// @return Starting state
  static std::vector<bool> GetStartingState(size_t number_of_variables);

  /// @brief Constructs automaton without any rules
  /// @return Constructed automaton
  static Automaton InitializeAutomaton();
};