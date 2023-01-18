#include <iostream>
#include <map>
#include <algorithm>
#include <D:/Miguel/Programas/PolynominalCalculator/src/polynominal.cpp>

Polynominal SumPolynominals(Polynominal first, Polynominal second);
Polynominal RestPolynominals(Polynominal first, Polynominal second);
Polynominal MultiplyPolynominals(Polynominal first, Polynominal second);
Polynominal DividePolynominals(Polynominal first, Polynominal second);

int main(){

  // Hashmap to store declared polynominals
  // =Example=
  // "P(x)", Polynominal(3, 4x^2, etc)
  std::map<std::string, Polynominal> polynominals;

  // Infinite loop
  /*while (true){
    std::cout << "\n>>> ";

    std::string firstVarName;
    char operation;
    std::string secondVarName;

    std::cin >> firstVarName >> operation >> secondVarName;

    // Declare a new polynominal
    if (operation == '='){

    } else if (polynominals.find(firstVarName) == polynominals.end() && polynominals.find(secondVarName) == polynominals.end()) {
      std::cout << "Invalid polynominal => Doesn't exist.\n";
    }
    
    // Do the correct operation with the specified polynominals
    if (operation == '+'){
      std::cout << SumPolynominals(polynominals[firstVarName], polynominals[secondVarName]).toString();
    } else if (operation == '-'){
      std::cout << SumPolynominals(polynominals[firstVarName], polynominals[secondVarName]).toString();
    } else if (operation == '*'){
      std::cout << MultiplyPolynominals(polynominals[firstVarName], polynominals[secondVarName]).toString();
    } else if (operation == '/'){
      std::cout << DividePolynominals(polynominals[firstVarName], polynominals[secondVarName]).toString();
    }
  }*/

  Polynominal test = Polynominal();
  test.monomials.push_back(Monomial(5, {{"x", 2}, {"a", 3}}));
  test.monomials.push_back(Monomial(-2, {{"x", 5}, {"y", 1}}));

  std::cout << test.toString() << '\n';
  std::cout << SumPolynominals(test, test).toString() << '\n';
  std::cout << RestPolynominals(test, test).toString() << '\n';
  std::cout << MultiplyPolynominals(test, test).toString() << '\n';

  return 0;
}

Polynominal SumPolynominals(Polynominal first, Polynominal second){
  Polynominal result = Polynominal();

  for (Monomial i : first.monomials){
    for (Monomial j : second.monomials){
      if (i.literalPart == j.literalPart && i.coefficient + j.coefficient != 0) result.monomials.push_back(Monomial(i.coefficient + j.coefficient, i.literalPart));
    }
  }

  return result;
}

Polynominal RestPolynominals(Polynominal first, Polynominal second){

  Polynominal secondInverted;

  for (int i = second.monomials.size() - 1; i >= 0; i--){
    if (second.monomials[i].coefficient - first.monomials[i].coefficient != 0) secondInverted.monomials.push_back(Monomial(second.monomials[i].coefficient * -1, second.monomials[i].literalPart));
  }

  return SumPolynominals(first, secondInverted);
}

Polynominal MultiplyPolynominals(Polynominal first, Polynominal second){

  Polynominal result = Polynominal();

  for (Monomial i : first.monomials){
    for (Monomial j : second.monomials){

      std::map<std::string, int> literalPart;

      if (i.coefficient * j.coefficient != 0) result.monomials.push_back(Monomial(i.coefficient * j.coefficient, literalPart));
    }
  }

  return result;
}