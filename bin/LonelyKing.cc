#include <string>
#include <random>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <vector>
int main(){
  int N = 65000;
  int r1,sumvec;
  std::vector<std::vector<int>> game(1,std::vector<int>(N));
  srand (time(NULL));
  int s = game[0].size();
  std::cout<<s<<std::endl;
  while( s > 1){
    for(int r=1; r<30; ++r){
      game.push_back( std::vector<int>(s));
        for(int i=0; i<s; ++i){
          r1 = rand() % s-1;
          if (r==r1){
            r1 += 1;
            game[r][r1] = 1;
          }
          else{
            game[r][r1] = 1;
          }
        }
      sumvec=0;
      for( std::vector<int>::iterator it = game[r].begin(); it != game[r].end(); ++it){
        sumvec += *it;
        std::cout<<sumvec<<std::endl;
      }
      std::cout<<"Round: "<<r<<" Players: "<<game[r].size()<<" Minus: "<<sumvec<<std::endl;
    }
    s= s-sumvec;
  }
}
