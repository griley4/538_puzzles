#include <string>
#include <random>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <vector>
#include <numeric> //accumulate
#include <algorithm> //sort

int main(){
  int wins = 0;
  int losses = 0;
  int ties = 0;
  int it = 1;
  std::vector<int> points = {1,2,3,4,5,6,7,8,9,10};
  std::vector<int> defender = {0,0,0,0,0,0,0,0,50,50};
  std::vector<int> attacker(10);
  float defscore = 0;
  float atkscore = 0;
  for(int a=0;a<101;a+=it){
//    std::cout<<a<<std::endl;
    for(int b=0;b<101;b+=it){
      if(a+b>100) continue;
      for(int c=0;c<101;c+=it){
        if(a+b+c>100) continue;
        for(int d=0;d<101;d+=it){
          if(a+b+c+d>100) continue;
          for(int e=0;e<101;e+=it){
            if(a+b+c+d+e>100) continue;
            for(int f=0;f<101;f+=it){
              if(a+b+c+d+e+f>100) continue;
              for(int g=0;g<101;g+=it){
                if(a+b+c+d+e+f+g>100) continue;
                for(int h=0;h<101;h+=it){
                  if(a+b+c+d+e+f+g+h>100) continue;
                  for(int i=0;i<101;i+=it){
                    if(a+b+c+d+e+f+g+h+i>100) continue;
                    for(int j=0;j<101;j+=it){
                      if(a+b+c+d+e+f+g+h+i+j!=100) continue;
//                      std::cout<<a<<","<<b<<","<<c<<","<<d<<","<<e<<","<<f<<","<<g<<","<<h<<","<<i<<","<<j<<std::endl;
                      attacker[0]=a;
                      attacker[1]=b;
                      attacker[2]=c;
                      attacker[3]=d;
                      attacker[4]=e;
                      attacker[5]=f;
                      attacker[6]=g;
                      attacker[7]=h;
                      attacker[8]=i;
                      attacker[9]=j;
                      //    std::cout<<" sum? "<<std::accumulate(attacker.begin(), attacker.end(),0)<<std::endl;   
                      for(int k=0; k<10; ++k){
                        if(attacker[k]>defender[k]) atkscore += points[k];
                        else if(attacker[k]<defender[k]) defscore += points[k];
                        else {atkscore += points[k]/2.; defscore += points[k]/2.;}
                      }
//                      std::cout<<"atk: "<<atkscore<<" def: "<<defscore;
                      if(atkscore>defscore){++losses;}
                      if(atkscore<defscore) {++wins;}
                      if(atkscore==defscore) {++ties;}
                      atkscore=defscore=0;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }

    std::cout<<"Wins: "<<float(wins)/(wins+losses+ties)<<" Losses: "<<float(losses)/(wins+losses+ties)<<" Ties: "<<float(ties)/(wins+losses+ties)<<std::endl;
}
