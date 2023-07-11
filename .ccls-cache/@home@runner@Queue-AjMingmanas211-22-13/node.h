#ifndef node_h
#define node_h

class NODE {
  int order, qty;
  NODE *nextPtr;

public:
  NODE(int, int);
  ~NODE();
  int get_value();
  void set_next(NODE *);
  NODE *get_next();
  int get_order(){ return (order>=1&&order<=3) ?  order :  0;} 
};

typedef NODE *NodePtr;

NODE::NODE(int order_inp, int qty_inp) {
  this->order = order_inp;
  this->qty = qty_inp;
  cout << "My order is ." << order_inp<<"\n";
  nextPtr = NULL;
}

int NODE::get_value() {
  int price;
  switch (order) {
  case 1:
    price = 100 * qty;
    break;
  case 2:
    price = 20 * qty;
    break;
  case 3:
    price = 50 * qty;
    break;
  default:
    return 0;
    break;
  }

  return price;
}

NODE *NODE::get_next() { return nextPtr; }

void NODE::set_next(NODE *t) { nextPtr = t; }

NODE::~NODE() {
  //cout<<"deleting " <<order<<endl;
}

#endif