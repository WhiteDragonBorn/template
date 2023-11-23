#pragma once
#include <iostream>

template <class T>
class list {
  typedef T value_type;
  typedef std::size_t size_type;
  typedef std::ptrdiff_t difference_type;
  typedef T& reference;
  typedef const value_type& const_reference;

 private:
  struct node {
    value_type data;
    node* next;

    node(const T& data_) : next(nullptr), data(data_) {}
  };
  typedef node* pointer;

  pointer head;

 public:
  list() { head = nullptr; }
  ~list() { clear(); };

  class iterator {
    // friend class list;
    pointer ptr;

   public:
    explicit iterator(const pointer& ptr_) : ptr(ptr_) {}

    pointer getPtr() const { return ptr; }

    iterator& operator=(const iterator& other) {
      if (this == &other) return *this;
      // delete ptr;
      ptr = other.ptr;
      return *this;
    }

    iterator& operator++() {
      if (ptr != nullptr)
        ptr = ptr->next;
      else
        ptr = nullptr;
      return *this;
    }

    iterator operator++(int) {
      iterator temp = *this;
      ++(*this);
      return temp;
    }

    bool operator==(iterator other) const { return ptr == other.ptr; }
    bool operator!=(iterator other) const { return !(*this == other); }
    iterator& operator+=(std::size_t n) {
      for (; n > 0; --n) {
        ++(*this);
      }
      return *this;
    }
    reference operator*() const { return ptr->data; }

    // difference_type operator-(iterator other) const { return other.ptr - ptr;
    // }

    // pointer operator->() const {
    //   pointer temp;
    //   temp = **this;
    //   return temp;
    // }
  };

  // iter
  iterator begin() { return iterator(head); }
  const iterator cbegin() const { return iterator(head); }
  iterator end() { return iterator(nullptr); }
  const iterator cend() const { return iterator(nullptr); }

  // access
  reference front() { return head->data; }
  const_reference front() const { return head->data; }

  // utility
  bool empty() { return head == nullptr; }
  void clear() {
    while (!empty()) delete_front();
  }

  // modifiers
  void push_front(const T& value) {
    pointer newNode = new node(value);
    newNode->next = head;
    head = newNode;
  }

  void insert_after(const iterator& pos, const value_type& value) {
    pointer newNode = new node(value);
    pointer pos_p = pos.getPtr();
    newNode->next = pos_p->next;
    pos_p->next = newNode;
  }

  template <class InputIt>
  void insert_after(const iterator& pos, InputIt first, InputIt last) {
    iterator temp = pos;
    for (InputIt start = first; start != last; ++start) {
      insert_after(temp, *start);
      temp++;
    }
  }

  iterator search(value_type elem) {
    for (auto start = begin(); start != end(); ++start) {
      if (*start == elem) return start;
    }
    return end();
  }

  template <class InputIt>
  iterator search(InputIt first, InputIt last) {
    for (iterator start = begin(); start != end(); ++start) {
      iterator temp = start;
      bool flag = true;
      for (InputIt internalIt = first; internalIt != last; ++internalIt) {
        if (flag == false) break;
        if (temp == end() || *internalIt != *temp) flag = false;
        ++temp;
      }
      if (flag) return start;
    }
    return end();
  }

  void delete_front() {
    pointer temp = head;
    head = head->next;
    temp->next = nullptr;
    delete temp;
    temp = nullptr;
  }

  void delete_after(const iterator& pos) {
    pointer posPtr = pos.getPtr();
    if (posPtr->next != nullptr) {
      pointer delNode = posPtr->next;
      posPtr->next = delNode->next;
      delNode->next = nullptr;
      delete delNode;
    }
  }

  void delete_after(const iterator& from, const iterator& to) {
    iterator temp = from;
    ++temp;
    difference_type i = 0;
    while (temp != to) {
      i++;
      ++temp;
    }

    for (; i > 0; i--) delete_after(from);
  }
};
