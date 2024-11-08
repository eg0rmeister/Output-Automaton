#include <iostream>
#include <Automaton.h>

class GeneralInput{
 public:
  /// @brief Constructs automaton using file inputs
  /// @param stream Input stream
  /// @return Constructed automaton
  /// @details Input file must be of a certain structure:
  /// number of variables of the automaton
  /// starting state
  /// number of rules
  /// Then for each rule:
  /// number of condition indices and the indices
  /// number of values to become true if condition is met and their indices
  /// number of values to become false if condition is met and their indices
  static Automaton InputAutomaton(std::istream& stream);
 
 private:
  /// @brief Creates a vector of integers according to file
  /// @param stream Input stream
  /// @return Constructed vector
  static std::vector<size_t> InitializeRulePart(std::istream& stream);

  /// @brief Adds a file-defined rule to automaton
  /// @param automaton Automaton to modify
  /// @param stream Input stream
  static void InitializeRule(Automaton& automaton, std::istream& stream);

  /// @brief Adds file-defined rules to automaton
  /// @param automaton Automaton to modify
  /// @param stream Input stream
  static void InitializeRules(Automaton& automaton, std::istream& stream);

  /// @brief Gets starting state vector from file
  /// @param number_of_variables Amount of variables in automaton
  /// @param stream Input stream
  /// @return Starting state
  static std::vector<bool> GetStartingState(size_t number_of_variables, std::istream& stream);

  /// @brief Constructs automaton without any rules
  /// @param stream Input stream
  /// @return Constructed automaton
  static Automaton InitializeAutomaton(std::istream& stream);
};