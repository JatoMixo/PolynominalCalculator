#include <vector>
#include <cmath>
#include <map>
#include <string>

class Monomial{

  public:

  Monomial() {}

  int coefficient;
  std::map<std::string, int> literalPart;
};

class Polynominal{

  public:
  Polynominal(){}

  std::vector<Monomial> monomials;

  std::string toString(){

    std::string str;

    // Iterate over every monomial
    for (int i = monomials.size() - 1; i >= 0; i--){

      // Add the coefficient
      if (monomials[i].coefficient > 0) str += '+';
      if (abs(monomials[i].coefficient > 1)) str += std::to_string(monomials[i].coefficient);

      // Check it it has literal parts and add it
      for (std::pair<std::string, int> j : monomials[i].literalPart){
        // Add the name of the variable + its exponent (In case it's higher than 1)
        str += (j.second > 1 ? "(" : "") + j.first + ((j.second > 1) ? '^' + std::to_string(j.second) + ')' : "");
      }

      // Add a space just to separate them
      str += ' ';
    }

    return str;
  }
};