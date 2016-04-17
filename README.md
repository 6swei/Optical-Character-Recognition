# Optical-Character-Recognition

![Image of Yaktocat](http://gedocx.com/wp-content/uploads/2014/04/OCR.jpg)

###Introduction:

Optical character recognition, as it is defined in WIKI, is the mechanical or electronic conversion of images of typed,
handwritten or printed text into machine-encoded text. Simply put, it is a common method that enables you to convert different types of 
documents, such as scanned paper documents, PDF files or images captured by a digital camera into editable and searchable data.
Image that your friend sent you a picture of the notes of a class that you missed. Normally, you would use youe eyes to regonize the contents and retype them 
into your computer. However, with a software that has OCR function, you could simply just import the file and get the result in
digitalized form. 


In this OCR program, it will only be able to recognize a set of decimal number from 0 to 9 in a black and white(8 bits grayscale)
image. The program first read in a bmp file(256*256, 8-bit grayscale) that contains some decimal numbers, then scan through each 
rows and columns and start a BFS when encountring a first and unvisited black pixel, and lastly perform calssification test
such as Euler number test and mass centroid test to recognize each digit.

A example of a 256*256, 8-bit grayscale bmp file: 

![Image of Yaktocat](https://raw.githubusercontent.com/6swei/Optical-Character-Recognition/master/ocr1.bmp)

###Classification technique:

1. Euler number: Number of unique components to the character -> # of components - # of holes = 1 - # of holes
('8' has 2 holes, '0' has 1, '2' has none)

    E=1 => {1, 2, 3, 5, 7}

    E=0 => {0, 4, 6, 9}

    E=-1 => {8}
    
   Computing the Euler number using Bit quads:
   
   there are 16 possible bit quads and we simply count how many bit quads that each character contains.
   
   ![Image of Yaktocat](https://github.com/6swei/Optical-Character-Recognition/blob/master/quad1.png)
   
   ![Image of Yaktocat](https://github.com/6swei/Optical-Character-Recognition/blob/master/quad2.png)
   
   Simple formula for finding Euler number: 𝐸 = 1/4 ∗ [𝑛{𝑄1} − 𝑛{𝑄3} − 2 ∗ 𝑛{𝑄𝑑}])
   
   We can also calculate the exact area and approximate perimeter of a character object by using
   
   Area = 1/4 * (𝑛{𝑄1} + 2 ∗ 𝑛{𝑄2} + 2 ∗ 𝑛{𝑄𝑑} + 3 ∗ 𝑛{𝑄3} + 4 ∗ 𝑛{𝑄4})

   Perimeter = (𝑛{𝑄1} + 𝑛{𝑄2} + 2 ∗ 𝑛{𝑄𝑑} + 𝑛(𝑄3})
   
2. Aspect Ratio: Height of the character divided by the width of the character.

3. Vertical centroid: (∑ i ∗ 𝑖𝑠𝑏𝑙𝑎𝑐𝑘(𝑖,𝑗)
𝐻,𝑊
𝑖,𝑗=0,0
) / [∑ 𝑖𝑠𝑏𝑙𝑎𝑐𝑘(𝑖,𝑗)
𝐻,𝑊
𝑖,𝑗=0,0
]

4. Horizontal centroid:  (∑ j ∗ 𝑖𝑠𝑏𝑙𝑎𝑐𝑘(𝑖,𝑗)
𝐻,𝑊
𝑖,𝑗=0,0
) / [∑ 𝑖𝑠𝑏𝑙𝑎𝑐𝑘(𝑖,𝑗)
𝐻,𝑊
𝑖,𝑗=0,0
]𝑘(𝑖,𝑗)]

5. Vertical Symmetry:  pixels in the upper half divided by pixel in the lower half. 1 indicates a perfect match of the upper and lower half.

6. Horiontal Symmetry: pixels in the left half divided by pixel in the right half. 1 indicates a perfect match of the upper and lower half. 

###Main Methods:

1)  Character(unsigned char (*myimage)[256], int ulr, int ulc, int h, int w) - constructor for initializing character object.

-> myimage is a pointer to the 2D array image and each pixel in it is acessible.

-> ulr stands for the upper left row of the bounding box of the character.

-> ulc stands for the lower right row of the bounding box of the character.

-> h stands for the height of the bounding box of the character.

-> w stands for the width of the bounding box of the character.


2)  void Classify() - It will use the result given by each classification tests to figure out the character.


3)  void perform_tests - Call any member functinos to perform classification tests.


4)  void get_bounding_box(int &sr, int &sc, int &er, int &ec) - Return two points that represents the top-left and bottom-right of the bounding box of the character.

-> sr stands for a reference to argument from caller that should be filled in with upper-leftmost row

-> sc stands for a reference to argument from caller that should be filled in with upper-leftmost column

-> er stands for a reference to argument from caller that should be filled in with bottom-rightmost row

-> ec stands for a reference to argument from caller that should be filled in with bottom-rightmost column

5)  void print_calculations() - Prints out the calssification result to the screem.

