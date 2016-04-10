#ifndef CHARACTER_H
#define CHARACTER_H

class Character {
 public:
  Character();
  // the first parameter should just be passed in and saved to 
  //  the 'image' data member as in ( image = myimage; )
  Character(unsigned char (*myimage)[256], int ulr, int ulc, int h, int w );
  ~Character();


  void perform_tests();
  void classify();
  char get_classification();
  // returns upper-left point and lower-right point of bounding box
  //  DOES NOT compute bounding box...it's already in your data members
  //  just returns the bounding box if a user wants the bounds
  void get_bounding_box(int &ulr, int &ulc, int &lrr, int &lrc);
  void print_calculations();

 private:
  //==============
  // Helper Functions
  //==============

  void calc_bit_quads();
  int calc_area();
  int calc_perimeter();
  void calc_euler_number();
  void calc_spatial_moment(); // calcs the horizontal & vertical centroids
  void calc_sym();            // calcs horizontal and vertical symmetry
  void calc_aspect_ratio();
  void calc_area_ratio();

  //==============
  // Data Members
  //==============
 private: 
  int ul_r, ul_c;
  int height, width;
  
  // feel free to add functions here.
  int Euler;
  //bit quads
  int q1, q3, qd;
  //Aspect Ratio
  double aspect;
  //vertical centroid
  int vscore, vcnt;
  double vcentroid;
  //horizontal centroid
  int hscore, hcnt;
  double hcentroid;
  //vertical symmetry 
  int vscnt, vsmatch;
  double vs;
  //horizontal symmetry
  int hscnt, hsmatch;
  double hs;
  //Shifted vertical centroid
  double svcentroid;
  //Shifted horizontal centroid
  double shcentroid;
  //Area ratio
  double arear;
  int area; 
  int areacnt;
  
  char recognized_char;
  unsigned char (*image)[256];


};

#endif

