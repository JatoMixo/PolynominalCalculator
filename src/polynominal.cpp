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

    if (monomials.size() == 0) return "0";

    std::string str;

    for (int i = monomials.size() - 1; i >= 0; i--){
      str += monomials[i].toString();
      if (i != 0) str += ' ';
    }

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

    if (monomials.size() <= 1) {
      return;
    }

    Polynominal correctPolynominal;
    
    for (int i = 0; i < monomials.size(); i++){
      for (int j = 0; j < monomials.size(); j++){
        if (!canSumMonomials(monomials[i], monomials[j]) && i == monomials.size() - 1){
          correctPolynominal.monomials.push_back(monomials[i]);
          continue;
        }

        if (!canSumMonomials(monomials[i], monomials[j])) {
          continue;
        }

        correctPolynominal.monomials.push_back(Monomial(monomials[i].coefficient + monomials[j].coefficient, monomials[i].literalPart));
        monomials.erase(monomials.begin() + i);
        monomials.erase(monomials.begin() + j);
      }
    }

    correctPolynominal.order();

    this->monomials = correctPolynominal.monomials;
  }
};
