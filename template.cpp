#include <list>
#include <utility>
#include <vector>

#include "List.h"

template <class container>
void print(const container& obj);

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
  iter++;

  std::cout << std::endl;
  print(a);
  std::cout << std::endl;

  std::vector<int> vec{1, 2, 3};
  a.insert_after(iter, vec.begin(), vec.end());
  // a.insert_after(iter, a.begin(), iter);

  std::cout << std::endl;
  print(a);
  std::cout << std::endl;

  auto iter_2 = iter;

  //++iter_2;
  //++iter_2;
  iter_2 += 2;

  a.delete_after(iter, iter_2);

  std::cout << std::endl;
  print(a);
  std::cout << std::endl;

  if (a.search(3) != a.end())
    std::cout << "found" << std::endl;
  else
    std::cout << "not found" << std::endl;

  a.push_front(3);
  a.push_front(2);
  a.push_front(1);
  a.push_front(1);

  std::cout << std::endl;
  print(a);
  std::cout << std::endl;

  if (a.search(vec.begin(), vec.end()) != a.end())
    std::cout << "found" << std::endl;
  else
    std::cout << "not found" << std::endl;

  auto test = a.search(vec.begin(), vec.end());
  std::cout << *(++test);

  // a.clear();

  return 0;
}

template <class container>
void print(const container& obj) {
  for (auto start = obj.cbegin(); start != obj.cend(); ++start) {
    std::cout << *start << " ";
  }
}
