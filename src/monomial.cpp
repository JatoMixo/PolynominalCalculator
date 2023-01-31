#include <string>
#include <map>

class Monomial{
  
  public:

  Monomial() {}
  Monomial(int coefficient, std::map<std::string, int> literalPart) {this->coefficient = coefficient; this->literalPart = literalPart;}

  // Coefficient of monomial
  int coefficient;
  
  // Map to store the literal part as follows. {"a", 5}, {"x", 3} => (a^5)(x^3)
  std::map<std::string, int> literalPart;

  // Get grade of monomial
  int getGrade() {
    
    if(literalPart.empty()) return 1;

    int grade = 0;
    
    // For every varible in the monomial, sum its grade to the global one.
    for (std::pair<std::string, int> i : literalPart){
      grade += i.second;
    }

    return grade;
  }
  
  std::string toString(){

    if (coefficient == 0){
      return "0";
    }

    std::string str;

    if (coefficient > 0){
      str += '+';
    } else if (coefficient < 0){
      str += '-';
    }

    if (abs(coefficient) > 1 || literalPart.empty()){
      str += std::to_string(abs(coefficient));
    }

    for (std::pair<std::string, int> i : literalPart){
      str += (i.second > 1 ? "(" : "") + i.first + ((i.second > 1) ? '^' + std::to_string(i.second) + ')' : "");
    }

    return str;
  }
};

bool canSumMonomials(Monomial mon1, Monomial mon2){
  return mon1.literalPart == mon2.literalPart;
}

Monomial DivideMonomials(Monomial first, Monomial second){

  Monomial result = Monomial();

  if (second.coefficient == 0) {
    return Monomial();
  }

  result.coefficient = first.coefficient / second.coefficient;

  for (std::pair<std::string, int> i : first.literalPart){
    if (second.literalPart.find(i.first) == second.literalPart.end()){
      result.literalPart[i.first] = i.second;
      continue;
    }

    result.literalPart[i.first] = i.second - second.literalPart[i.first];
  }

  return result;
}