#ifndef _BASE_
#define _BASE_

class Base
{
public:
  Base() = default;
  ~Base() = default;
public:
  virtual void run_test(char *argv[]);
};

#endif // _BASE_
