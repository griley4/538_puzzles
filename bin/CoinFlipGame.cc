#include <string>
#include <random>
#include <stdlib.h>
#include <iostream>
#include <time.h>

int main(){
        double r1;
        int x,y,i,count;
        srand (time(NULL));
        i=count=0;
        x = rand() % (10000 + 1) * -1;
        y = rand() % (10000 + 1);

        while(i!=x && i!=y){
                r1=rand() % 2;
                if(r1<1){
                        i = i-1;
                }
                if(r1>=1){
                        i = i+1;
                } 
                ++count;
        }
        if(i==x){
                std::cout<<"X Wins!!!"<<std::endl;
        }
        if(i==y){
                std::cout<<"Y Wins!!!"<<std::endl;
        }

        std::cout<<"X: "<<x<<" Y: "<<y<<" Flips: "<<count<<std::endl;



}
