#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the freqQuery function below.
def freqQuery(queries):
    op_arr=[]
    numandfreqmap={}
    freqandlistmap={}
    def insertinmap(num):
        if not(num in numandfreqmap):
            numandfreqmap[num]=0
        numandfreqmap[num]+=1
        if not(numandfreqmap[num] in freqandlistmap):
            freqandlistmap[numandfreqmap[num]]=set([])
        freqandlistmap[numandfreqmap[num]].add(num)
        if(numandfreqmap[num]-1 in freqandlistmap):
            if num in freqandlistmap[numandfreqmap[num]-1]:
                freqandlistmap[numandfreqmap[num]-1].remove(num)
    def deloneof(num):
        if num in numandfreqmap:
            oldfreq=numandfreqmap[num]
            numandfreqmap[num]-=1
            if numandfreqmap[num]==0 :
                del numandfreqmap[num]
                freqandlistmap[oldfreq].remove(num)
            else:
                freqandlistmap[oldfreq].remove(num)
                freqandlistmap[oldfreq-1].add(num)
                
                
    def checkfreqold(num):
        for i in numandfreqmap:
            if numandfreqmap[i]==num:
                return 1
        return 0
    
    def checkfreq(freq):
        if freq in freqandlistmap:
            return 1
        return 0
        
    
    for q in queries:
        if q[0]==1:
            insertinmap(q[1])
        elif q[0]==2:
            deloneof(q[1])
        elif q[0]==3:
            res=checkfreq(q[1])
            op_arr.append(res)
    return op_arr
            
            

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(input().strip())

    queries = []

    for _ in range(q):
        queries.append(list(map(int, input().rstrip().split())))

    ans = freqQuery(queries)

    fptr.write('\n'.join(map(str, ans)))
    fptr.write('\n')

    fptr.close()