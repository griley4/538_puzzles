#include <string>
#include <random>
#include <stdlib.h>
#include <iostream>
#include <time.h>

int main(){

  double Pi=3.141592653589793238463;
  double r1,r2,x1,x2,y1,y2,xi[3],yi[3];
  int ncuts=3;
  int niterations=100;
  srand (time(NULL));
  for(int t=0; t<niterations; ++t){
  double m[ncuts],b[ncuts];
  int nintersections=0;
  for(int i=0; i<ncuts; ++i){
    r1 =rand() % 360;
    r2 =rand() % 360;
    x1 = cos(r1*(2*Pi/360.));
    y1 = sin(r1*(2*Pi/360.));
    x2 = cos(r2*(2*Pi/360.));
    y2 = sin(r2*(2*Pi/360.));
    if (!(x1==x2)){
        m[i]=((y2-y1)/(x2-x1));
        b[i]=-((y2-y1)/(x2-x1))*x1+y1;
    }
    else{std::cout<<"NOPE"<<std::endl;}
    // std::cout<<"One: ("<<x1<<","<<y1<<")  Two: ("<<x2<<","<<y2<<")"<<std::endl; 
  }

  for(int j=0; j<ncuts; ++j){
    for(int k=j+1; k<ncuts; ++k){
      if((m[j]==m[k])){continue;}
      xi[nintersections] = ((b[k]-b[j])/(m[j]-m[k]));
      yi[nintersections] = m[j]*xi+b[j];
      if(xi[nintersections]*xi[nintersections]+yi[nintersections]*yi[nintersections]>=1){continue;}
      ++nintersections;
      }
    }
  for(int l=0; l<nintersections; ++l){
    for(int n=l+1; n<nintersections; ++n){

  std::cout<<"Pizza N: "<<t<<"  Intersections: "<<nintersections<<std::endl;
  }
  return(0);

}
