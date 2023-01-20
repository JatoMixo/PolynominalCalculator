#include <vector>
#include <cmath>
#include <string>
#include <D:/Miguel/Programas/PolynominalCalculator/src/monomial.cpp>

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
      else if (monomials[i].coefficient < 0) str += '-';
      if (abs(monomials[i].coefficient) > 1) str += std::to_string(abs(monomials[i].coefficient));

      // Check if it has literal parts and add it
      for (std::pair<std::string, int> j : monomials[i].literalPart){
        // Add the name of the variable + its exponent (In case it's higher than 1)
        str += (j.second > 1 ? "(" : "") + j.first + ((j.second > 1) ? '^' + std::to_string(j.second) + ')' : "");
      }

      // Add a space just to separate them
      str += ' ';
    }

    if (monomials.size() == 0) return "0";

    return str;
  }

  int getGrade(){
    int grade = 0;
    for (Monomial i : monomials){

      int actualGrade = i.getGrade();

      if (actualGrade > grade) grade = actualGrade;
    }

    return grade;
  }

  void correct(){
    for (int i = 0; i < monomials.size(); i++){
      for (int j = 0; j < monomials.size(); j++){
        if (monomials[i].literalPart != monomials[i].literalPart) continue; 
        monomials.push_back(Monomial(monomials[i].coefficient + monomials[i].coefficient, monomials[i].literalPart));
        monomials.erase(monomials.begin() + i);
        monomials.erase(monomials.begin() + j);
      }
    }

    order();
  }

  void order(){

    bool hasChangedOrder = false;

    for (int i = 0; i < monomials.size() - 2; i++){
      if (monomials[i + 1].getGrade() <= monomials[i].getGrade()) continue;

      Monomial temp = monomials[i + 1];

      monomials[i + 1] = monomials[i];

      monomials[i] = temp;

      hasChangedOrder = true;
      
    }

    if (hasChangedOrder) order();
  }
};