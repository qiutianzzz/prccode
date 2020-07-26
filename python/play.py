import os
import sys
import math

# numgroup = [[1] * 2 for i in range (4)]
numlist = [[]*3 for i in range (3) ]
numstr = [[] *3 for i in range (3)] 
for i in range (3):
    print(i)
    numstr[i] = input().split('\n')

for i in range (3):
    numlist[i] = list(map(int, numstr[i][0].split(' ')))
print(numlist)
    

#     numlist = list(map(numlist.split(' ')))
#     numgroup[j] = numlist[j]

# print(numgroup)

