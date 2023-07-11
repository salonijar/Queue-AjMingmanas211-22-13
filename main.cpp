#include <iostream>
#include <iomanip>
using namespace std;
#include "queue.h"

int main(int argc,char *argv[]) {
  Queue q;
  int size=0,j=1;
  for(int i=1; i < argc; i+=2){
    int price=0, cash=0; 
     if(argv[i][0]=='x'){
        if(q.get_size()==0){
          cout<<"Can't dequeue due to queue is empty\n";
        }
        else{
          int a = q.get_headPtr()->get_order();
          price = q.dequeue();
          cout<<"Customer no : "<<j<<"\n";
          if(a!=0){
            if(a==1)
              cout<<"Ramen\n";
            else if(a==2)
              cout<<"Noodles\n";
            else if(a==3)
              cout<<"Fried Chicken\n";
            cout<<"You have to pay "<<price<<"\n";
            do{
              cout<<"Cash : ";
              cin>>cash;
            }while(cash<price);
            cout<<"Thank you\n";
            if(cash>price){
              cout<<"Change is :"<<cash-price<<"\n";
            }
          }
          else{
             cout<<"choice not in the menu\n";
          }
         j++;
        }
        i--;
      }
       
    else{
      q.enqueue(atoi(argv[i]),atoi(argv[i+1]));
    }
    
    size = (q.get_size() ? q.get_size() : 0);
  }
  cout<<"\n"<<setw(30)<<setfill('=')<<"=\n";
  cout<<"there are "<<size<<" people left in queue";
}