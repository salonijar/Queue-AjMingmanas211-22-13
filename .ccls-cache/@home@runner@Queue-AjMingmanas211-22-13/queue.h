#include "node.h"

class Queue {
  NodePtr headPtr, tailPtr;
  int size=0;

public:
  void enqueue(int, int);
  int dequeue();
  Queue();
  ~Queue(); // dequeue all
  void print_all();
  int get_size(){return size;}
  NodePtr get_headPtr() {return headPtr;}

};

Queue::Queue(){
  size=0;
  headPtr=NULL;
  tailPtr=NULL;
}

Queue::~Queue(){
 int i;
 int n=size;

  //while(size>0)
  for(i=0;i<n;i++)
    dequeue();
  
}
void Queue::enqueue(int order_inp,int qty_inp) {
  NodePtr new_node = new NODE(order_inp, qty_inp); // 1.Create
 // 2 Connect
  if(new_node){
    if(size == 0){
      headPtr = new_node;
    }
    else{
      tailPtr->set_next(new_node);
    }
    tailPtr = new_node;
    ++size;
    //print_all();
  }
  else{
    cout<<"No memory avaible\n";
  }
}

int Queue::dequeue() {
  int value;
  NodePtr temp;
 if(headPtr){
    temp = headPtr;
    value = temp->get_value();
    headPtr = headPtr->get_next();
    delete temp;
    if(size == 0)
        tailPtr=nullptr;
  --size; 
  }
  return value;
}

void Queue::print_all(){
  NODE* currentPtr = headPtr;
  for(int i = 0; i < size; i++){
    if(currentPtr!=nullptr){
      cout<< currentPtr->get_value();
      cout<< "-> ";
      currentPtr = currentPtr->get_next();
    }
  }
      cout << "x\n";
}