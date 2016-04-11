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
