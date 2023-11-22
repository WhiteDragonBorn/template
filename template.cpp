#include <list>
#include <utility>

#include "List.h"

int main() {
  list<int> a;
  std::pair<list<int>::iterator, list<int>::iterator> b(a.begin(), a.end());

  a.push_front(3);
  a.push_front(4);
  a.push_front(5);
  a.push_front(6);
  a.push_front(7);

  auto iter = a.begin();
  iter++;
  a.insert_after(iter, 9);
  iter++;
  a.insert_after(iter, 7);
  for (auto start = a.begin(); start != a.end(); ++start) {
    std::cout << *start;
  }
  std::cout << std::endl;
  a.delete_after(iter);
  for (auto start = a.begin(); start != a.end(); ++start) {
    std::cout << *start;
  }

  a.clear();
  for (auto start = a.begin(); start != a.end(); ++start) {
    std::cout << *start;
  }

  return 0;
}
