#include <iostream>
#include <map>
#include <algorithm>
#include </home/jatomixo/Code/PolynominalCalculator/src/polynominal.cpp>

std::string polynominalToString(Polynominal pol);
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
  while (true){
    std::cout << "\n>>> ";

    std::string firstVarName;
    char operation;
    std::string secondVarName;

    std::cin >> firstVarName >> operation >> secondVarName;

    if (operation == '='){

    } else if (polynominals.find(firstVarName) && polynominals.find(secondVarName)) {
      std::cout << "Invalid polynominal => Doesn't exist.\n";
    }
    
    if (operation == '+'){
      std::cout << polynominalToString(SumPolynominals(polynominals[firstVarName], polynominals[secondVarName]));
    } else if (operation == '-'){
      std::cout << polynominalToString(RestPolynominals(polynominals[firstVarName], polynominals[secondVarName]));
    } else if (operation == '*'){
      std::cout << polynominalToString(MultiplyPolynominals(polynominals[firstVarName], polynominals[secondVarName]));
    } else if (operation == '/'){
      std::cout << polynominalToString(DividePolynominals(polynominals[firstVarName], polynominals[secondVarName]));
    }
  }

  return 0;
}