#include <vector>
#include <map>
#include <string>

class Polynominal{

  public:
  Polynominal(){}

  // Crete a vector to store the coefficients of the polynominals for each variable.
  std::vector<int> coefficients;

  // Create a map to store the literal parts of each variable in the polynominal.
  // Example: {"X", {0, 1, 1}}, {"y", {1}} => x^3 + x^2 + y
  std::map<std::string, std::vector<int>> literalParts;

  std::string toString(){

    std::string str;

    // Iterate over every monomial
    for (int i = coefficients.size() - 1; i >= 0; i--){

      // Add the coefficient
      if (coefficients[i] > 0) str += '+';
      str += std::to_string(coefficients[i]);

      // Check it it has literal parts and add it
      for (std::pair<std::string, std::vector<int>> j : literalParts){
        // Add the name of the variable + its exponent (In case it's higher than 1)
        str += j.first + std::to_string((j.second[i] > 0 && i > 1) ? i + 1 : NULL);
      }

      // Add a space just to separate them
      str += ' ';
    }

    return str;
  }
};