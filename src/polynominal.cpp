#include <vector>
#include <cmath>
#include <string>
#include <D:/Miguel/Programas/PolynominalCalculator/src/monomial.cpp>

class Polynominal{

  public:
  Polynominal(){}
  Polynominal(std::vector<Monomial> monomials) {this->monomials = monomials;}

  std::vector<Monomial> monomials;

  std::string toString(){

    std::string str;

    // Iterate over every monomial
    for (int i = monomials.size() - 1; i >= 0; i--){

      // Add the coefficient
      if (monomials[i].coefficient > 0) str += '+';
      else if (monomials[i].coefficient < 0) str += '-';
      if (abs(monomials[i].coefficient) > 1 || i == 0) str += std::to_string(abs(monomials[i].coefficient));

      // Check if it has literal parts and add it
      for (std::pair<std::string, int> j : monomials[i].literalPart){
        // Add the name of the variable + its exponent (In case it's higher than 1)
        str += (j.second > 1 ? "(" : "") + j.first + ((j.second > 1) ? '^' + std::to_string(j.second) + ')' : "");
      }

      // Add a space just to separate them
      str += ' ';
    }

    // In case it's a NULL polynominal, print '0' instead of nothing
    if (monomials.size() == 0) return "0";

    return str;
  }

  // Get grade of the polynominal
  int getGrade(){
    int grade = 0;
    
    // For every monomial in the polynominal
    for (Monomial i : monomials){

      int actualGrade = i.getGrade();

      // If grade of the new monomial is higher than the older one, we store that in the variable
      if (actualGrade > grade) grade = actualGrade;
    }

    return grade;
  }

  // Order the list to put the monomials in the right order
  void order(){

    bool hasChangedOrder = false;

    for (int i = 1; i < monomials.size(); i++){
      if (monomials[i - 1].getGrade() < monomials[i].getGrade() || (monomials[i - 1].getGrade() == monomials[i].getGrade() && monomials[i - 1].coefficient > monomials[i].coefficient)) continue;

      Monomial temp = monomials[i - 1];

      monomials[i - 1] = monomials[i];

      monomials[i] = temp;

      hasChangedOrder = true;
    }

    // If we changed something, we check again, else the list is fully ordered.
    if (hasChangedOrder) order();
  }

  void correct(){

    Polynominal correctPolynominal;
    
    for (int i = 0; i < monomials.size(); i++){
      for (int j = 0; j < monomials.size(); j++){
        if (!canSumMonomials(monomials[i], monomials[j]) && i == monomials.size() - 1){
          correctPolynominal.monomials.push_back(monomials[i]);
          continue;
        }

        if (!canSumMonomials(monomials[i], monomials[j])){
          continue;
        }

        correctPolynominal.monomials.push_back(Monomial(monomials[i].coefficient + monomials[j].coefficient, monomials[i].literalPart));
        monomials.erase(monomials.begin() + i);
        monomials.erase(monomials.begin() + j);
        break;
      }
    }

    correctPolynominal.order();

    this->monomials = correctPolynominal.monomials;
  }
};
