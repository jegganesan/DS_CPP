#include<iostream>

using namespace std;

template <typename T>struct node {
  T data;
  node* next;
  node(T a):data(a),next(NULL) {}
};
