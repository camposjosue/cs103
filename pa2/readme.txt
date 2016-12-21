CSCI 103 Programming Assignment 2, Chroma Key, Fall 2014

Name:Josue Campos

Email Address: jrcampos@usc.edu

NOTE: You can delete the questions, we only need your responses.

=============================== Prelab =======================================

Pixel                |    RGB Value     |  Distance from Chroma Key
-------------------------------------------------------------------
Top-left background  | (69  ,138 , 19   )  |  n/a
Arm                  | (255 ,163 ,122 )  | 214.1
Vest                 | (27  ,32  ,28  )  | 114.4
Shirt                | (255 ,218 ,243 )  | 301.9

================================== Review ===================================
1. Discuss and justify which pixels you chose to compute the average 
background value for method 1. Was there a reason not to choose more or
fewer pixels?

Response 1:I sample the leftmost colum and the highest row to obtain my average.
I also used a diagonal to add some differentiation to the all green samples I 
originally had.

2. For method 1, do some experiments to find the range of distance thresholds 
for which the program seems to operate the best. You may use different 
thresholds for the two different sample images (Colbert and Bird). 
Note: threshold values that are too low will cause certain portions of the 
chroma key to stay in the picture; values that are too high will cause parts 
of the foreground image to disappear.

Response 2:I felt that bird only need one row and one column form the edges to get a good
sample but with colber i added an extra row and column inlcuding a diagonal to get a good 
average to use in my function.

3. For method 2, explain what you implemented and why.  How did you go about 
implementing it? Walk us through a high-level description of what you did in 
your code (and use comments in the actual .cpp file to fill in the details). 
What other alternatives did you consider either before or after you
implemented your selected method?  What are the relative pros and cons of 
these methods? [This question is open-ended!]

Response 3:I was able to find the max of the averages and use that as my threshold.

================================ Remarks ====================================

Filling in anything here is OPTIONAL.

Approximately how long did you spend on this assignment?

:11 hours

Were there any specific problems you encountered? This is especially useful to
know if you turned it in incomplete.

:Seg Fault (core dumped)

Do you have any other remarks?

:Instructions were really scattered in PDF
