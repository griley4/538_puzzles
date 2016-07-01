#include <string>
#include <random>
#include <stdlib.h>
#include <iostream>
#include <time.h>

int main(){
  int r1, rg, rs, rp, yg, ys, yp, ygi, ypi, ysi;
  float w,l,skillavg;
  srand (time(NULL));
  int skill = 1;
  skillavg=0.;
  w=l=0.;
  ypi=0;
  std::cout<<" Wins: "<<" Losses: "<<" Percent: "<<" Starting Score Sets: "<<" Games: "<<" Points: "<<" Final Skill: "<<std::endl;
  for(ysi=0; ysi<3; ++ysi){
    for(ygi=0; ygi<6; ++ygi){
      for(ypi=0; ypi<4; ++ypi){
        for(int att=0; att<1000000; ++att){
          rg=rs=rp=0;
          yp=ypi;
          yg=ygi;
          ys=ysi;
          skill=1;
          while (rs<3&&ys<3&&abs(ys-rs)<=2){
            r1 = rand() % 100;
            //    std::cout<<r1<<std::endl;
            //point increment
            if(r1<skill){
              ++yp;
            }
            else{
              ++rp;
              if(skill<50){
                ++skill;
              }
            }
            //games increment
            if(yp>=4&&abs(rp-yp)>=2){
              ++yg;
              //              std::cout<<"Rodger Points: "<<rp<<" Your Points: "<<yp<<std::endl; 
              yp=0;
              rp=0;
            }
            else if(rp>=4&&abs(rp-yp)>=2){
              ++rg;
              //              std::cout<<"Rodger Points: "<<rp<<" Your Points: "<<yp<<std::endl; 
              yp=0;
              rp=0;
            }
            else{}
            //set increment
            if(yg>=6&&abs(rg-yg)>=2){
              ++ys;
              //              std::cout<<" [R: "<<rg<<" Y: "<<yg<<"]"; 
              yg=0;
              rg=0;
            }
            else if(rg>=6&&abs(rg-yg)>=2){
              ++rs;
              //              std::cout<<" [R: "<<rg<<" Y: "<<yg<<"]"; 
              yg=0;
              rg=0;
            }
            else{}
          }
          //      std::cout<<" Final: "<<rs<<" "<<ys<<std::endl;
          if(ys>rs){++w;}
          else{++l;}
          skillavg = skillavg+skill;
        }
        std::cout<<w<<" "<<l<<" "<<100.*(w/1000000)<<" "<<ysi<<" "<<ygi<<" "<<ypi<<" "<<skillavg/1000000.<<std::endl;
        w=l=0.;
        skillavg=0;
      }
    }
  }
}
