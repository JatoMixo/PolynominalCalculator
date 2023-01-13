#include <vector>
#include <map>
#include <string>

class Polynominal{

  public:
  Polynominal(){}

  // Crete a map to store the coefficients of the polynominals for each variable.
  // Example: {"x", {1, 0, 5, -7}} => -7x^4 + 5x^3 + x + rest
  // Example with 2 variables: {"x", {1, 2}}, {"y", {0, 3, 4}} => 4y^3 + 3*2x^2y^2 + x + rest

  std::map<std::string, std::vector<int>> coefficients;

  int rest;
};