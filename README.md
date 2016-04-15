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

1. Character(unsigned char (*myimage)[256], int ulr, int ulc, int h, int w) - constructor for initializing character object.
-> myimage is a pointer to the 2D array image and each pixel in it is acessible.
-> ulr stands for the upper left row of the bounding box of the character.
-> ulc stands for the lower right row of the bounding box of the character.
-> h stands for the height of the bounding box of the character.
-> w stands for the width of the bounding box of the character.
