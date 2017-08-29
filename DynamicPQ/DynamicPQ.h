#include <iostream>
#include <queue>
#include <map>

template <typename T>
class Comparator {
  public:
    bool operator() (const T a, const T b) {
      return *a < *b;
    }
};
/*
   Key is the key
   Value is the object the data is stored in
   e.g. DynamicPriorityQueue<int, ListValue*>
   */
template <typename Key, typename Value>
class DynamicPriorityQueue {
  std::map<Key, Value*> *keyToValue;
  std::priority_queue<Value*, std::vector<Value*>, Comparator<Value*> > *pq; 

  public:
    // constructor
    DynamicPriorityQueue() {
      keyToValue = new std::map<Key, Value*>();
      pq = new std::priority_queue<Value*, std::vector<Value*>, Comparator<Value*> >(); 
    }

    void push(Key k, Value* n) {
      if(keyToValue->find(k) == keyToValue->end()) {
        (*keyToValue)[k] = n;
        pq->push(n);
      }
      else {
        Value* v = new Value(n);
        (*keyToValue)[k] = v;
        n = nullptr;
        pq->push(v);
      }
    }

    Value* top() {
      while(pq->top() == nullptr) {
        pq->pop();
      }
      return pq->top();
    }
};
