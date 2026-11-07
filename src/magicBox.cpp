
#include <iostream>
using namespace std;
#include <ctime>
#include "../include/magicBox.h"


void goToXY(int x,int y){
 
 std::cout<<"\033["<<x+1<<";"<<y+1<<"H"<<std::flush;
 
}

int takeInput(){
     int boxSize=0;
 cout<<"Enter the size of the box: \n";
   cin>>boxSize;
   if(boxSize%2==0){
    cout<<"Order must be an odd number!\n";
    return 0;
   }
   return boxSize;
}

void delay(int delayMs){
    int start=clock();
    int delayS=delayMs* (CLOCKS_PER_SEC/1000);
    while((clock()-start)<delayS){

    }
}

void displayMagicBox( int boxSize){
   int prevRow,prevCol;
   int row=0;
   int col=boxSize/2;
  


   

goToXY((row+6),(col*4)+15);
   cout<<1<<" ";
   for(int i=2;i<=boxSize*boxSize;i++){
    prevRow=row;
    prevCol=col;


  row=(row-1+boxSize)%boxSize;
  col=(col+1)%boxSize;

  if((i-1) % boxSize==0){
    row=(prevRow+1)%boxSize;
    col=prevCol;
  }
 
delay(500);
goToXY((row+6),(col*4)+15);
   cout<<i<<" ";


   }
}