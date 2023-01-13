#include <vector>
#include <map>
#include <string>

class Polynominal{

  public:
  Polynominal(){}

  // Crete a vector to store the coefficients of the polynominals for each variable.
  std::vector<int> coefficients;

  // Create a map to store the literal parts of each variable in the polynominal.
  // Example: {"X", {0, 1, 3}}, {"y", {1}} => x^3 + x^2 + y
  std::map<std::string, std::vector<int>> literalParts;

  int rest;
};