#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
#include <cstdlib>
#include "character.h"
#include "point.h"
#include "bmplib.h"

using namespace std;

#define THRESH 127

unsigned char image[SIZE][SIZE];		// Input Image Data Array
unsigned char explored[SIZE][SIZE];		// Explored

int main(int argc, char *argv[])
{
   if(argc != 3){
      cout << "wrong argument" << endl;
      return 1;
   }
   
   readGSBMP(argv[1], image);
   //setting threshold value
   const int threshold = 128;
   //for storing black pixels encountered.
   deque<Point> storage;
   //for storing the classify number
   vector<Character> target;
  
   for(int row=0; row<SIZE; row++){
      for(int col=0; col<SIZE; col++){
         if(image[row][col] < threshold){
            //color white
            image[row][col] = 0;
         }
         else{
            //color black
            image[row][col] = 255;
         }
         //initialize not explored grid
         explored[row][col] = 0;
      }
   }
   
   
   //inithilize the bounding box
   int boxsr, boxsc, boxer, boxec; 
     
   for(int r=0; r<SIZE; r++){
      for(int c=0; c<SIZE; c++){
      
         if(image[r][c] == 0 && explored[r][c] == 0){           
            Point startpoint;
            startpoint.r = r;
            startpoint.c = c;
            storage.push_back(startpoint); 
            explored[r][c] = 1;
            //set bounding box to starting location
            boxsr = r;
            boxsc = c;
            boxer = r;
            boxec = c;   
                  
            Point curr;
            Point N, W, S, E, NW, SW, SE, NE;
              
            while(!storage.empty()){
            
               curr.r = storage.front().r;
               curr.c = storage.front().c;
               storage.pop_front();
                        
               //for searching N
               N.r = curr.r - 1;
               N.c = curr.c;
               if(image[N.r][N.c] == 0 && explored[N.r][N.c] == 0){
                  storage.push_back(N);
                  explored[N.r][N.c] = 1;
               }
            
               //for searching W
               W.r = curr.r;
               W.c = curr.c-1;
               if(image[W.r][W.c] == 0 && explored[W.r][W.c] == 0){
                  storage.push_back(W);
                  explored[W.r][W.c] = 1;
               }
            
               //for searching S
               S.r = curr.r+1;
               S.c = curr.c;
               if(image[S.r][S.c] == 0 && explored[S.r][S.c] == 0){
                  storage.push_back(S);
                  explored[S.r][S.c] = 1;
               }  
            
               //for searching E
               E.r = curr.r;
               E.c = curr.c+1;
               if(image[E.r][E.c] == 0 && explored[E.r][E.c] == 0){
                  storage.push_back(E);
                  explored[E.r][E.c] = 1;
               }        
            
               //for searching NW
               NW.r = curr.r-1;
               NW.c = curr.c-1;
               if(image[NW.r][NW.c] == 0 && explored[NW.r][NW.c] == 0){
                  storage.push_back(NW);
                  explored[NW.r][NW.c] = 1;
               }       
            
               //for searching SW
               SW.r = curr.r+1;
               SW.c = curr.c-1;
               if(image[SW.r][SW.c] == 0 && explored[SW.r][SW.c] == 0){
                  storage.push_back(SW);
                  explored[SW.r][SW.c] = 1;
               }
            
               //for searching SE
               SE.r = curr.r+1;
               SE.c = curr.c+1;
               if(image[SE.r][SE.c] == 0 && explored[SE.r][SE.c] == 0){
                  storage.push_back(SE);
                  explored[SE.r][SE.c] = 1;
               }    
            
               //for searching NE
               NE.r = curr.r-1;
               NE.c = curr.c+1;
               if(image[NE.r][NE.c] == 0 && explored[NE.r][NE.c] == 0){
                  storage.push_back(NE);
                  explored[NE.r][NE.c] = 1;
               }
            
               //for finding the newest bounding box
               if(curr.r < boxsr){
                  boxsr = curr.r;
               }
               if(curr.c < boxsc){
                  boxsc = curr.c;
               }
               if(curr.r > boxer){
                  boxer = curr.r;
               }  
               if(curr.c > boxec){
                  boxec = curr.c;
               }            
                                                  
            }//end of while loop
            
            /*
            //for drawing box around the number
            for(int i=boxsr; i<boxer; i++){
               image[i][boxsc] = 128;
               image[i][boxec] =128;
            }
         
            for(int j=boxsc; j<boxec; j++){
               image[boxsr][j] = 128;
               image[boxer][j] =128;
            }                  
            showGSBMP(image); 
            */
            
            //store target number's bounding box in the vector array
            Character object(image, boxsr, boxsc, boxer-boxsr, boxec-boxsc);
            target.push_back(object);         
         
       }//end of if statement
  
     }
   }//end of for loop
   
  
   for(int i=0; i<target.size(); i++){ 
      target[i].perform_tests();
      target[i].classify(); 
      
      if(atoi(argv[2]) == 0){ 
         cout << target[i].get_classification()<<" ";
      }
      if(atoi(argv[2]) == 1){
         target[i].print_calculations();
      }
   }
   cout << endl;

  return 0;
}

