#include "List.h"
#include <list>


int main() {
  std::list<int> b;
  b.push_front(3);
  std::cout << *b.begin();



  //list<int> a;
  //a.push_front(3);
  //a.push_front(4);
  //a.push_front(5);
  //a.push_front(6);
  //a.push_front(7);
  //for (auto start = a.begin(); start != a.end(); ++start) {
  //  std::cout << *start;
  //}
  //return 0;
}
