#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  // create a new ULListStr object and add strings
  ULListStr temp;
  temp.push_front("one");
  temp.push_back("two");
  temp.push_back("three");
  temp.push_back("four");
  temp.push_back("five");
  temp.push_back("six");
  temp.push_back("seven");
  temp.push_back("eight");
  temp.push_back("nine");
  temp.push_back("ten");
  temp.push_back("eleven");
  temp.push_back("twelve");
  temp.push_back("thirteen");
  temp.push_front("zero");

  // test if the strings were added correctly with get, front(), and back()
  std::cout << temp.get(0) << std::endl;
  std::cout << temp.get(1) << std::endl;
  std::cout << temp.front() << std::endl;
  std::cout << temp.back() << std::endl;

  // try pop_front()
  temp.pop_front();
  temp.pop_front();
  std::cout << temp.get(0) << std::endl;

  return 0;
}
