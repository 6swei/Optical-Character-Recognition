#include "character.h"
#include <iostream>
#include "point.h"

using namespace std;

Character::Character(){

}

Character::Character(unsigned char (*myimage)[256], int ulr, int ulc, int h, int w){
   image = myimage;
   ul_r = ulr;
   ul_c = ulc;
   height = h;
   width = w;
}

Character::~Character(){

}

void Character::perform_tests(){
 
   calc_bit_quads();
   calc_euler_number();
   calc_spatial_moment(); 
   calc_sym();            
   calc_aspect_ratio();      
}

void Character::calc_bit_quads(){
  q1=0, q3=0, qd=0;
  for(int i=ul_r-1; i <= ul_r+height + 1; i++){
      for(int j=ul_c-1; j <= ul_c + width + 1; j++){
      
            
               if(image[i][j]==0 && image[i][j+1]==255 && image[i+1][j]==255 && image[i+1][j+1]==255){
                  q1++;   
               }
               if(image[i][j]==255 && image[i][j+1]==0 && image[i+1][j]==255 && image[i+1][j+1]==255){
                  q1++;   
               }    
               if(image[i][j]==255 && image[i][j+1]==255 && image[i+1][j]==0 && image[i+1][j+1]==255){
                  q1++;   
               }  
               if(image[i][j]==255 && image[i][j+1]==255 && image[i+1][j]==255 && image[i+1][j+1]==0){
                  q1++;   
               }   
               //for counting number of Q3     
               if(image[i][j]==0 && image[i][j+1]==0 && image[i+1][j]==0 && image[i+1][j+1]==255){
                  q3++;   
               }       
               if(image[i][j]==0 && image[i][j+1]==0 && image[i+1][j]==255 && image[i+1][j+1]==0){
                  q3++;   
               }     
               if(image[i][j]==0 && image[i][j+1]==255 && image[i+1][j]==0 && image[i+1][j+1]==0){
                  q3++;   
               }  
               if(image[i][j]==255 && image[i][j+1]==0 && image[i+1][j]==0 && image[i+1][j+1]==0){
                  q3++;   
               }  
               //for counting number of QD
               if(image[i][j]==0 && image[i][j+1]==255 && image[i+1][j]==255 && image[i+1][j+1]==0){
                  qd++;   
               }         
               if(image[i][j]==255 && image[i][j+1]==0 && image[i+1][j]==0 && image[i+1][j+1]==255){
                  qd++;   
               }                        
      }
   }   
}

void Character::calc_euler_number(){

   Euler = (q1 - q3 - 2*qd)/(4);
}

void Character::calc_sym(){
   vscnt=0, vsmatch=0;
   //Vertical symmetry method
   for(int i=ul_r; i <= ul_r+height/2; i++){
      for(int j=ul_c; j < ul_c + width; j++){
         vscnt++;
         if(image[i][j] == image[ul_r + height - (i-ul_r)][j]){
            vsmatch++;
         }   
      }
   } 
    vs = (double) vsmatch/vscnt;
   
   hscnt=0, hsmatch=0;
   //Horizontal symmetry method
   for(int i=ul_r; i <= ul_r+height; i++){
      for(int j=ul_c; j < ul_c + width/2; j++){
         hscnt++;
         if(image[i][j] == image[i][ul_c + width - (j-ul_c)]){
            hsmatch++;
         }   
      }
   } 
   hs = (double) hsmatch/hscnt;      
}

void Character::calc_spatial_moment(){
   //Vertical Centroid method
   vscore=0, vcnt=0;
   areacnt=0, area=0;
   for(int i=ul_r; i <= ul_r+height; i++){
      for(int j=ul_c; j <= ul_c + width; j++){
         areacnt++;
         if(image[i][j] == 0){
            vscore += (i-ul_r)*1;
            vcnt++;
            area++;
         }
      }
   }
   vcentroid = (double) vscore/vcnt;
   arear = (double) area/areacnt;
   
   //Shifted Vertical Centroid
   svcentroid = vcentroid - (height/2);

   //Horizontal Centroid method
   hscore=0, hcnt=0;
   for(int i=ul_r; i <= ul_r+height; i++){
      for(int j=ul_c; j <= ul_c + width; j++){
         if(image[i][j] == 0){
            hscore += (j-ul_c)*1;
            hcnt++;
         }
      }
   }
   hcentroid = (double) hscore/hcnt;
   
   //Shifted horizontal Centroid
   shcentroid = hcentroid - (width/2);
}

void Character::calc_aspect_ratio(){
   //Aspect Ratio method
   aspect = (double) height/width;
}



void Character::classify(){

   if(Euler == -1){
      recognized_char = '8';
   }
   
   if(Euler == 0){
      if(vs > 0.8 && hs > 0.8){
         recognized_char = '0';
      }
      else if(svcentroid > 0 && shcentroid < 0){
         recognized_char = '6';
      }
      else if(svcentroid < 0 && shcentroid > 0 && shcentroid < 2){
         recognized_char = '9';
      }
      else {
         recognized_char = '4';
      }
   }
   
   if(Euler == 1){
      if(aspect > 1.7){
         recognized_char = '1'; 
      }
      else if(svcentroid > 1 && shcentroid > 0 && vs > 0.58 && hs > 0.58){
         recognized_char = '2';
      }
      else if(shcentroid > 2){
         recognized_char = '3';
      }
      else if(svcentroid < -2){
         recognized_char = '7';
      }
      else{
         recognized_char = '5';
      }
   }

}
 
char Character::get_classification(){
   return recognized_char;
}

void Character::get_bounding_box(int &ulr, int &ulc, int &lrr, int &lrc){
   ulr = ul_r;
   ulc = ul_c;
   lrr = ul_r + height;
   lrc = ul_c + width;
}

void Character::print_calculations(){
   
   cout<<"Character in bounding box: "<<ul_r<<","<<ul_c<<" to "<<ul_r+height<<","<<ul_c+width<<endl;
   cout<< "===================================="<<endl;
   cout<<"BQ1 ="<<q1<<" BQ3 ="<<q3<<" BQD ="<<qd<<endl;
   cout<<"Euler number ="<<Euler<<endl;
   cout<<"Vcentroid ="<<vcentroid<<" / "<<"Hcentroid ="<<hcentroid<<endl;
   cout<<"shifted Vcentroid ="<<svcentroid<<" / "<<"shifted Hcentroid ="<<shcentroid<<endl;   
   cout<<"Vsym ="<<vs<<" / "<<"Hsym ="<<hs<<endl;
   cout<<"Aspect Ratio = "<<aspect<<endl; 
   cout<<"Area Ratio = "<<arear<<endl;
   cout<<"Character is "<<get_classification();  
   cout<<endl;
   cout<<endl;
}
