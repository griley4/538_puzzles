#include <string>
#include <random>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <vector>
#include <numeric> //accumulate
#include <algorithm> //sort

int main(){
  int rounds = 9999999;
  int defwinz = 0;
  int oldrecord = 9;
  srand (time(NULL));
  std::vector<int> points = {1,2,3,4,5,6,7,8,9,10};
  std::vector<int> defender = {100,0,0,0,0,0,0,0,0,0};
  std::vector<int> attacker(10);
  std::vector<int> rando(11);
  float defscore = 0;
  float atkscore = 0;
  for(int i=0;i<rounds;++i){
    std::fill(attacker.begin(),attacker.end(),0);
    std::fill(rando.begin(),rando.end(),0);
    rando[0]=0;
    rando[10]=100;
    for(int k=1;k<10;++k){
      rando[k] = rand() %100;
    }
    std::sort(rando.begin(),rando.end());
    attacker[0] = rando[1]-rando[0];
    attacker[1] = rando[2]-rando[1];
    attacker[2] = rando[3]-rando[2];
    attacker[3] = rando[4]-rando[3];
    attacker[4] = rando[5]-rando[4];
    attacker[5] = rando[6]-rando[5];
    attacker[6] = rando[7]-rando[6];
    attacker[7] = rando[8]-rando[7];
    attacker[8] = rando[9]-rando[8];
    attacker[9] = rando[10]-rando[9];
//    std::cout<<" sum? "<<std::accumulate(attacker.begin(), attacker.end(),0)<<std::endl;   
    for(int j=0; j<10; ++j){
      if(attacker[j]>defender[j]) atkscore += points[j];
      else if(attacker[j]<defender[j]) defscore += points[j];
      else {atkscore += points[j]/2.; defscore += points[j]/2.;}
    }
    if(atkscore>defscore){
     if(defwinz>oldrecord){ 
      std::cout<<"Winningest: ";
      for(std::vector<int>::const_iterator l = attacker.begin(); l!=attacker.end(); ++l){
        std::cout<<*l<<" ";
      }
      std::cout<<" "<<std::endl;
      std::cout<<"Score: "<<defwinz<<std::endl;
      oldrecord=defwinz;
     }
      defender=attacker; 
      defwinz=0;

    }
    if(atkscore<=defscore) ++defwinz;
    //    std::cout<<"atk: "<<atkscore<<" def: "<<defscore<<" Wins?: "<<defwinz<<std::endl;
    atkscore=defscore=0;
  }
//  std::cout<<std::endl;
//  std::cout<<std::endl;
//  std::cout<<"Castle num: ";
//  for(std::vector<int>::const_iterator l = points.begin(); l!=points.end(); ++l){
//    std::cout<<*l<<" ";
//  }
//  std::cout<<" "<<std::endl;
//  std::cout<<"Winningest: ";
//  for(std::vector<int>::const_iterator l = attacker.begin(); l!=attacker.end(); ++l){
//    std::cout<<*l<<" ";
//  }
//  std::cout<<" "<<std::endl;
//  std::cout<<"Score: "<<defwinz<<std::endl;
}
