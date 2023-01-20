#include <string>
#include <map>

class Monomial{
  
  public:

  Monomial() {}
  Monomial(int coefficient, std::map<std::string, int> literalPart) {this->coefficient = coefficient; this->literalPart = literalPart;}

  int coefficient;
  std::map<std::string, int> literalPart;

  int getGrade(){
    int grade = 0;
    for (std::pair<std::string, int> i : literalPart){
      grade += i.second;
    }

    return grade;
  }
};