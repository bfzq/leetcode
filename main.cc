#include <iostream>
#include "global.h"
#include "base.h"
#include "two_sum.h"
#include <string.h>
using namespace std;

enum QUESTIONS {TWO_SUM,
                UNKNOWN};

QUESTIONS
get_question(char *arg)
{
  if (arg == NULL)
    return UNKNOWN;
  if (strcasecmp(arg, "two_sum") == 0)
    return ::TWO_SUM;
  else
    return UNKNOWN;
}

int
got_run_body(QUESTIONS question, Base **base)
{
  switch (question)
  {
  case TWO_SUM:
  {
    *base = new Twosum();
    break;
  }
  case UNKNOWN:
  defualt:
  {
    cout << "error opt." << endl;
    return -1;
  }
  }
  return 0;
}

int
run_code(QUESTIONS question, char *argv[])
{
  Base *base = nullptr;
  if (got_run_body(question, &base) != 0)
    return -1;
  if (base == nullptr)
  {
    base = new Base();
  }
  base->run_test(argv);
  delete base;
  return 0;
}

int
main(int args, char *argv[])
{
  return run_code(get_question(argv[1]),
                  argv + 2);
}
