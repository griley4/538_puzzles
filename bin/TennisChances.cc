#include <string>
#include <random>
#include <stdlib.h>
#include <iostream>
#include <time.h>

int main(){
  int r1, rg, rs, rp, yg, ys, yp, ygi, ypi, ysi, over, under;
  float w,l;
  srand (time(NULL));
  int skill = 1;
  w=l=0.;
  ypi=0;ygi=0;ysi=0;
  over=under=0;
  std::cout<<" Wins: "<<" Losses: "<<" Percent: "<<" Starting Score Sets: "<<" Games: "<<" Points"<<std::endl;
  for(ysi=0; ysi<3; ++ysi){
    for(ygi=0; ygi<6; ++ygi){
      for(ypi=0; ypi<4; ++ypi){
        for(int att=0; att<1000000; ++att){
          rg=rs=rp=0;
          yp=ypi;
          yg=ygi;
          ys=ysi;
          while (rs<3&&ys<3&&abs(ys-rs)<=2){
            r1 = rand() % 100;
            //    std::cout<<r1<<std::endl;

            //point increment
            if(r1<skill){
              ++yp;
              ++under;
            }
            else{++rp;++over;}
            //games increment
            if(yp>=4&&(yp-rp)>=2){
              ++yg;
              //              std::cout<<"Rodger Points: "<<rp<<" Your Points: "<<yp<<std::endl; 
              yp=0;
              rp=0;
            }
            else if(rp>=4&&(rp-yp)>=2){
              ++rg;
              //              std::cout<<"Rodger Points: "<<rp<<" Your Points: "<<yp<<std::endl; 
              yp=0;
              rp=0;
            }
            else{}
            //set increment
            if(yg>=6&&(yg-rg)>=2){
              ++ys;
              //              std::cout<<" [R: "<<rg<<" Y: "<<yg<<"]"; 
              yg=0;
              rg=0;
            }
            else if(rg>=6&&(rg-yg)>=2){
              ++rs;
              //              std::cout<<" [R: "<<rg<<" Y: "<<yg<<"]"; 
              yg=0;
              rg=0;
            }
            else{}
          }
          //      std::cout<<" Final: "<<rs<<" "<<ys<<std::endl;
          if(ys>rs){++w;
//                std::cout<<" Final: "<<rs<<" "<<ys<<std::endl;
          }
          else{++l;}
        }
        //std::cout<<w<<" "<<l<<" "<<100.*(w/1000000)<<" "<<ysi<<" "<<ygi<<" "<<ypi<<" Total Points R: "<<over<<" Total Points Y: "<<under<<std::endl;
        std::cout<<w<<" "<<l<<" "<<100.*(w/1000000)<<" "<<ysi<<" "<<ygi<<" "<<ypi<<std::endl;
        w=l=0.;
        over=under=0;
      }
    }
  }
}
