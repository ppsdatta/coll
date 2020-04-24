#ifndef __COLL_LLIST_H__
#define __COLL_LLIST_H__

#include "./internals/node.hpp"

namespace coll
{

  template <typename T>
    class llist
    {
      public:
        explicit llist() : _head(nullptr), _len(0) {
          // empty contructor
        }

        // copy
        // move
        //

        void append(const T& v) {
          this->_head = add_to_node(
              this->_head,
              v
              );
          _len++;
        }

        void prepend(const T& v) {
          this->_head = add_to_front_node(
              this->_head,
              v
              );
        }

        void insert(size_t pos, const T& v) {
          this->_head = add_node_at(
              this->_head,
              pos,
              v);
        }

        void reverse() {
          this->_head = reverse_node(
              this->_head
              );
        }

        size_t size() const {
          return this->_len;
        }

        // temporary
        //
        void print_list() const {
          print_node(this->_head);
        }

        virtual ~llist() {
          free_node(this->_head);
        }
      private:
        node<T> *_head;
        size_t _len;
    };

}

#endif

