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
    int grade = 0;
    
    // For every varible in the monomial, sum its grade to the global one.
    for (std::pair<std::string, int> i : literalPart){
      grade += i.second;
    }

    return grade;
  }
};