CSCI 103 Programming Assignment 3, Path-so-logical, Fall 2014

Name: Josue Campos

Email Address: jrcampos@usc.edu

NOTE: You can delete the questions, we only need your responses.

=============================== Prelab =======================================

1. What data structure will you use to remember which locations have
already been added to the queue or not?

I used a dynamically allocated 2D array of pointers to keep track of were I visited.
Within my while I set my visited spaces to 1 in the array and then checked that I 
didnt previously visit those locatios in various if statements.

2. At what step of the BFS algorithm do you have to mark a cell as visited?

When you find a neighbor you immmediately set it as visited. That way you ensure
the program won't mistakenly visit that spot again.

================================== Review ===================================

1. Describe your "mymaze.txt" test file. It should have multiple paths
of different distances. When you ran your program on it, did your program 
behave as expected?

I made a maze with various paths. Two of length 22 and one of length 26. 
This is to make sure that the program chooses the shortest path and also 
that we give the north direction priority as stated in the write up.

================================ Remarks ====================================

Filling in anything here is OPTIONAL.

Approximately how long did you spend on this assignment?

:12 hours

Were there any specific problems you encountered? This is especially useful to
know if you turned it in incomplete.

: The process for predecessor was not well explained. Most of the time in 
this lab was figuring out how to do it. I heard many different strategies
 from many different people so there was no consensuswhich made it really 
 difficult to get help.

Do you have any other remarks?

:There should be some discussion with CP's regarding how to deal with 
certain strateies. My TA said to not use tail and heads in my predecessor
array as indexes but I heard otherwise from a professor.
