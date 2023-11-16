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
    friend class list;
    pointer ptr;

   public:

    explicit iterator(const pointer& ptr_) : ptr(ptr_) {}

    iterator& operator=(const iterator& other) {
      if (this == &other) return *this;
      delete ptr;
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
    reference operator*() const { return ptr->data; }

    //pointer operator->() const {
    //  pointer temp;
    //  temp = **this;
    //  return temp;
    //}
  };

  iterator begin() { return iterator(head); }
  iterator end() { return iterator(nullptr); }

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
     pointer pos_p = pos.ptr;
     newNode->next = pos_p->next;
     pos_p->next = newNode;
   }

  iterator search(const iterator& from, const iterator& to) {
    iterator ptr = begin();
  }

  // iterator search(const T& value) {

  //}

  void delete_front() {
    pointer temp = head;
    head = head->next;
    temp->next = nullptr;
    delete temp;
    temp = nullptr;
  }

  void delete_after();
};
