#include <iostream>
#include <Automaton.h>

class FileInput{
 public:
  /// @brief Constructs automaton using file inputs
  /// @param file Stream of input file
  /// @return Constructed automaton
  /// @details Input file must be of a certain structure:
  /// number of variables of the automaton
  /// starting state
  /// number of rules
  /// Then for each rule:
  /// number of condition indices and the indices
  /// number of values to become true if condition is met and their indices
  /// number of values to become false if condition is met and their indices
  static Automaton InputAutomaton(std::ifstream& file);
 
 private:
  /// @brief Creates a vector of integers according to file
  /// @param file Stream of input file
  /// @return Constructed vector
  static std::vector<size_t> InitializeRulePart(std::ifstream& file);

  /// @brief Adds a file-defined rule to automaton
  /// @param automaton Automaton to modify
  /// @param file Stream of input file
  static void InitializeRule(Automaton& automaton, std::ifstream& file);

  /// @brief Adds file-defined rules to automaton
  /// @param automaton Automaton to modify
  /// @param file Stream of input file
  static void InitializeRules(Automaton& automaton, std::ifstream& file);

  /// @brief Gets starting state vector from file
  /// @param number_of_variables Amount of variables in automaton
  /// @param file Stream of input file
  /// @return Starting state
  static std::vector<bool> GetStartingState(size_t number_of_variables, std::ifstream& file);

  /// @brief Constructs automaton without any rules
  /// @param file Stream of input file
  /// @return Constructed automaton
  static Automaton InitializeAutomaton(std::ifstream& file);
};