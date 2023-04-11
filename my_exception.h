#pragma once              
#include <cstring>        
#include <string>
using namespace std;

enum ErrorCode           
{
   EC_RANGE = -3,
   EC_MEMORY = -2,
   EC_UNKNOWN = -1,
   EC_OK = 0
};

class MyException
{
   string message;
   ErrorCode code;
 public:
   MyException(ErrorCode c, string msg) {
      code = c;
      message = msg;
   }
   string getMessage() const { return message; }
   ErrorCode getCode() const { return code; }
};