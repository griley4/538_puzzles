#include <string>
#include <random>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <vector>
int main(){
  int tests = 10000;
  int sumres = 0;
  srand (time(NULL));
  std::vector<int> result(tests);
  for (int test=0;test<tests;++test){
    bool go=1;
    int N = 2;
    int s = N;
    int r=0;
    int r1,sumvec=0;
    std::vector<std::vector<int>> game(10,std::vector<int>(N));
    while(go){
      if (s > 1){
        for(int i=0; i<s; ++i){
          r1 = rand() % s;
          if (i==r1){
            r1 = (r1+1)%s;
          }
          game[r][r1] = 1;
        }
        sumvec=0;
        for( std::vector<int>::iterator it = game[r].begin(); it != game[r].end(); ++it){
          sumvec += *it;
          //  std::cout<<*it<<" tot: "<<sumvec<<std::endl;
        }
        //      std::cout<<"Round: "<<r<<" Players: "<<game[r].size()<<" Minus: "<<sumvec<<std::endl;
        ++r;
        s = s-sumvec;
        game[r] =  std::vector<int>(s);
      }
      else{
        go=0;
        std::cout<<"Round: "<<r<<" Players: "<<game[r].size()<<std::endl;
        result[test] = game[r].size();
      }
    }
  }
  for( std::vector<int>::iterator it2 = result.begin(); it2 != result.end(); ++it2){
    sumres += *it2;
  }
  std::cout<<"Wins: "<<sumres<<" Losses: "<< tests - sumres<<std::endl;
}
