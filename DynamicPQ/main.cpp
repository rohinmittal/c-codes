#include "DynamicPQ.h"

class Node {
  public:
    int count;
    Node(int val) : count(val) {}
    Node(const Node *n) {
      count = n->count;
    }   

    bool operator< (const Node &b) {
      return this->count < b.count;
    }   
};

int main() {
  DynamicPriorityQueue<int, Node> dPQ;

  Node n1(12);
  dPQ.push(1, &n1);

  n1.count = 35; 
  dPQ.push(1, &n1);

  Node n2(15);
  dPQ.push(2, &n2);

  n2.count = 25; 
  dPQ.push(2, &n2);


  std::cout<<dPQ.top()->count;
  std::cout<<std::endl;
  return 0;
}

