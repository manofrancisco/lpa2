# lpa2
Problem B - Red and Yellow Tulips

Description

Zacarias has a huge cultivation of red and yellow tulips, for which he has to spread pesticide by plane. Unfortunately, red and yellow tulips cannot take the same type of perticide. Very unfortunately, the red and yellow tulips were cultivated in a random way over the field. Given that he can only afford to change between the two different types of pesticide a certain number of times while driving the plane over the field of tulips, he has to decide when to drop each pesticide such that the number of tulips taking the wrong pesticide is minimized.

Input

Assume that the tulips are cultivated are in a single line.
Each line describes a test case. The first positive integer is the maximum number of times that he is allowed to change between the two different types of pesticide. Then, a binary string follows, where 1 means a yellow tulip and 0 means a red tulip. Other test cases may follow in the next lines. There are at most 1500 tulips and the maximum number of changes is 300. Note: Assume that the first time that the pesticide is dropped counts as one change.
Output
For each test case, print the minimum number of tulips taking the wrong pesticide given the maximum number of changes of pesticide that Zacarias can do while driving the plane over the line of tulips.


Example Example input:


      1 11100001111
      
      
      2 11100001111
      
      
Example output:

  4 

  3
