#include<iostream>
#include "node.h"

using namespace std;

template <typename T>class list {
  node<T> *head;
public:
  list():head(NULL) {}
  void disp();
  void add(const T a);
  void make_circular();
  bool is_circular();
};

template <typename T> void list<T>::add(const T a) {
  node<T> *n = new node<T>(a);
  if(head == NULL) {
    head = n;
    return;
  }
  node<T> *t = head;
  while(t->next!=NULL) {
    t = t->next;
  }
  t->next = n;
}

template <typename T> void list<T>::make_circular() {
  if(head == NULL) {
    return;
  }
  node<T> *t = head;
  while(t->next!=NULL) {
    t = t->next;
  }
  t->next = head;
}

template <typename T> bool list<T>::is_circular() {
  if(head == NULL) {
    return false;
  }
  node<T> *t = head;
  while(t->next!=NULL) {
    if(t->next == head) {
      return true;
    }
    t = t->next;
  }
  return false;
}

template <typename T> void list<T>::disp() {
  node<T> *t = head;
  cout<<"Displaying list: ";
  while(t!=NULL) {
    cout<<t->data<<" ";
    t = t->next;
  }
  cout<<endl;
}

int main()
{
  list<int> l;
  l.add(1);
  l.add(2);
  l.add(3);
  l.disp();
  cout<<"Enter 1 to make list circular ";
  int ch;
  cin>>ch;
  if(ch == 1) {
    l.make_circular();
  }
  cout<<"Is circular: "<<l.is_circular()<<endl;
  return 0;
}
