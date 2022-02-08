#include <iostream>
#include <vector>
#include <utility>
#include "dst/superHashTable.h" /* i wrote this one myself because the hasfunction of
                        unordered_Map cannot hash pair*/
#include "dst/hashTable.h" /*also, wrote this one myself*/
#include <cmath>

int main(int argc, char const *argv[]) {
  HashTable* table = new HashTable();

  table->insert(0,0);
  cout<<table->get(0)<<endl;
  table->insert(5,5);
  cout<<table->get(5)<<endl;

  pair<int, int> my_pair0( 0, 0 );
  pair<int, int> my_pair1( 1, 1 );
  pair<int, int> my_pair2( 2, 2 );
  pair<int, int> my_pair3( 3, 4 );
  pair<int, int> my_pair4( 4, 4 );

  SuperHashTable* S = new SuperHashTable();
  cout<<"----------------------------------------------------------------\n";
  S->insert(my_pair0, table);
  cout<<S->curCap()<<endl;
  cout<<"getItems' size: "<<S->getItems().size()<<"++++++++\n";
  S->insert(my_pair1, table);
  cout<<S->curCap()<<endl;
  cout<<"getItems' size: "<<S->getItems().size()<<"++++++++\n";
  S->insert(my_pair2, table);
  cout<<S->curCap()<<endl;
  cout<<"getItems' size: "<<S->getItems().size()<<"++++++++\n";
  S->insert(my_pair3, table);
  cout<<S->curCap()<<endl;
  cout<<"getItems' size: "<<S->getItems().size()<<"++++++++\n";
  S->insert(my_pair4, table);
  cout<<S->curCap()<<endl;
  cout<<"getItems' size: "<<S->getItems().size()<<"++++++++\n";



  return 0;
}
