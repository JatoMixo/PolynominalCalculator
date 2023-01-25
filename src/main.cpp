#include <iostream>
#include <map>
#include <algorithm>
#include <D:/Miguel/Programas/PolynominalCalculator/src/polynominal.cpp>

Polynominal SumPolynominals(Polynominal first, Polynominal second);
Polynominal RestPolynominals(Polynominal first, Polynominal second);
Polynominal MultiplyPolynominals(Polynominal first, Polynominal second);
std::pair<Polynominal, Polynominal> DividePolynominals(Polynominal first, Polynominal second);

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
  
  Polynominal test2 = Polynominal();
  test2.monomials.push_back(Monomial(7, {{"x", 2}, {"a", 3}}));
  test2.monomials.push_back(Monomial(-2, {}));

  Polynominal test3 = Polynominal();
  test3.monomials.push_back(Monomial(-5, {}));

  std::cout << "Original: " << test.toString() << '\n';
  std::cout << "Summed by itself: " << SumPolynominals(test, test).toString() << '\n'; // -4x5y + 10x2a3
  std::cout << "Rest by itself: " << RestPolynominals(test, test).toString() << '\n'; // 0
  std::cout << "Multiply by itself: " << MultiplyPolynominals(test, test).toString() << '\n'; // 
  std::cout << "------------------------------\n";
  std::cout << SumPolynominals(test, test2).toString() << '\n';
  std::cout << RestPolynominals(test, test2).toString() << '\n';
  std::cout << MultiplyPolynominals(test, test2).toString() << '\n';
  std::cout << "------------------------------\n";
  std::cout << SumPolynominals(test2, test3).toString() << '\n';
  std::cout << RestPolynominals(test2, test3).toString() << '\n';
  
  return 0;
}

bool canSumMonomials(Monomial mon1, Monomial mon2){
  return mon1.literalPart == mon2.literalPart && mon1.coefficient + mon2.coefficient != 0;
}

Polynominal SumPolynominals(Polynominal first, Polynominal second){
  Polynominal result = Polynominal();

  bool summed;

  for (int i = 0; i < first.monomials.size(); i++){
    for (int j = 0; j < second.monomials.size(); j++){

      if (!canSumMonomials(first.monomials[i], second.monomials[i])){
        result.monomials.push_back(second.monomials[j]);
      }

      result.monomials.push_back(Monomial(first.monomials[i].coefficient + second.monomials[j].coefficient, first.monomials[i].literalPart));
      second.monomials.erase(second.monomials.begin() + j);
      summed = true;
      break;
    }

    if (!summed) result.monomials.push_back(first.monomials[i]);
    summed = false;
  }

  result.order();

  return result;
}

Polynominal RestPolynominals(Polynominal first, Polynominal second){

  Polynominal secondInverted;

  for (Monomial i : second.monomials){
    secondInverted.monomials.push_back(Monomial(i.coefficient * -1, i.literalPart));
  }

  return SumPolynominals(first, secondInverted);
}

Polynominal MultiplyPolynominals(Polynominal first, Polynominal second){

  Polynominal result = Polynominal();

  for (Monomial i : first.monomials){
    for (Monomial j : second.monomials){

      std::map<std::string, int> literalPart;

      for (std::pair<std::string, int> var : i.literalPart) literalPart[var.first] = var.second;
      for (std::pair<std::string, int> var : j.literalPart) literalPart[var.first] += var.second;
      
      result.monomials.push_back(Monomial(i.coefficient * j.coefficient, literalPart));
    }
  }

  // result.correct();

  return result;
}

std::pair<Polynominal, Polynominal> DividePolynominals(Polynominal first, Polynominal second){

  std::pair<Polynominal, Polynominal> result;

  return result;
}
