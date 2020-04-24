#include <iostream>

#ifndef __COLL_INTERNAL_NODE_H__
#define __COLL_INTERNAL_NODE_H__

namespace coll 
{

  template <typename T>
    struct node
    {
      T v;
      node *next;

      node(T v)
      {
        this->v = v;
        this->next = nullptr;
      }

      node(T v, node *next)
      {
        this->v = v;
        this->next = next;
      }
    };


  template <typename T>
    node<T> *add_to_node(node<T> *n, const T& v)
    {
      if (n == nullptr) {
        return new node<T>{v};
      }

      n->next = add_to_node(n->next, v);

      return n;
    }


  template <typename T>
    void free_node(node<T> *n)
    {
      if (n != nullptr)
        free_node(n->next);
      delete n;
    }


  template <typename T>
    void print_node(node<T> *n)
    {
      using std::cout;
      using std::endl;


      if (n == nullptr)
        cout << "[]";
      else
        for (node<T> *in = n; in != nullptr; in = in->next) {
          cout << in->v << endl;
        }
    }


  template <typename T>
    node<T> *reverse_node(node<T> *n)
    {
      if (n == nullptr || n->next == nullptr) return n;

      node<T> *p, *q, *r;

      p = n;
      q = n->next;

      for (;;) {
        r = q->next;
        q->next = p;

        if (r == nullptr) {
          q->next = p;
          break;
        }

        p = q;
        q = r;
      }

      n->next = nullptr;

      return q;
    }


  template <typename T>
    node<T> *add_to_front_node(node<T> *n, T v)
    {
      auto new_node = new node<T>{v};
      new_node->next = n;

      return new_node;
    }


  template <typename T>
    node<T> *add_node_at(node<T> *n, size_t idx, T v)
    {
      if (idx == 0) 
        return add_to_front_node(n, v);

      node<T> *itn = n;
      for (size_t i = 0; i < idx - 1; ++i) {
        if (itn == nullptr)
          return n;

        itn = itn->next;
      }

      node<T> *new_node = new node<T>{v};
      new_node->next = itn->next;
      itn->next = new_node; 

      return n;
    }


  template <typename T>
    node<T> *middle_node(node<T> *n)
    {
      node<T> *i = n;
      int count = 0;

      while (i != nullptr) {
        if (count == 2) {
          n = n->next;
          count = 0;
        }

        i = i->next;
        count++;

      }

      return n;
    }

}

#endif

