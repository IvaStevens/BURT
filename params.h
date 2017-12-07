// Param file Enum
#ifndef BURT_PARAM_H
#define BURT_PARAM_H
#include <stdexcept>
#include <string>
#include <map> 
using namespace std;

template <typename T>
class EnumParser 
{
  map <string, int> enumMap;
  public:
    EnumParser(){};
    
    
    int ParseSomeEnum(const string &value)
    { 
      map<string, int>::const_iterator iValue;
      
      iValue = enumMap.find(value);
      if (iValue  == enumMap.end())
        throw runtime_error("");
      return iValue->second;
    }
};
  
enum DIR {UP, UP_RIGHT, RIGHT, DOWN_RIGHT, DOWN, DOWN_LEFT, LEFT, UP_LEFT};
template <>
EnumParser<DIR>::EnumParser()
{
  //TODO
}

enum XorYorZ {X, Y, Z};
template <>
EnumParser<XorYorZ>::EnumParser()
{
  enumMap["X"] = 1;
  enumMap["Y"] = 2;
  enumMap["Z"] = 3;
}

enum FORCE {LIGHT, MEDIUM, HEAVY};
template <>
EnumParser<FORCE>::EnumParser()
{
  enumMap["LIGHT"] = 1;
  enumMap["MEDIUM"] = 2;
  enumMap["HEAVY"] = 3;
}

enum DISTANCE {NEAR, AWAY, FAR};
template <>
EnumParser<DISTANCE>::EnumParser()
{
  enumMap["NEAR"] = 1;
  enumMap["AWAY"] = 2;
  enumMap["FAR"] = 3;
}

enum FLAG {CONTROL, FREEZE, HOME, REPEAT, REWARD, REWARD_SET, REWIND, SKIP, TARGET};
template <>
EnumParser<FLAG>::EnumParser()
{
  enumMap["CONTROL"] = 1;
  enumMap["FREEZE"] = 2;
  enumMap["HOME"] = 3;
  enumMap["REPEAT"] = 4;
  enumMap["REWARD"] = 5;
  enumMap["REWARD_SET"] = 6;
  enumMap["REWIND"] = 7;
  enumMap["SKIP"] = 8;
  enumMap["TARGET"] = 9;
}

#endif