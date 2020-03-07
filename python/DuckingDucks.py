#! /usr/bin/env/python
import sys
import matplotlib.pyplot as pyplot
import random
import numpy as np
results = []
def move(duckspos):
    for duck,rock in enumerate( duckspos):
        if rock == 1:
            duckspos[duck] = random.choice([2,4])
        if rock == 2:
            duckspos[duck] = random.choice([1,3,5])
        if rock == 3:
            duckspos[duck] = random.choice([2,6])
        if rock == 4:
            duckspos[duck] = random.choice([1,5,7])
        if rock == 5:
            duckspos[duck] = random.choice([2,4,6,8])
        if rock == 6:
            duckspos[duck] = random.choice([5,3,9])
        if rock == 7:
            duckspos[duck] = random.choice([4,8])
        if rock == 8:
            duckspos[duck] = random.choice([7,5,9])
        if rock == 9:
            duckspos[duck] = random.choice([8,6])
    return(duckspos)
def onegame():
    time=0
    duckpos = [5,5,5,5]
    while time < 1000:
        newpos = move(duckpos)
        time+=1
#        print(time,newpos)
        if newpos[0]==newpos[1]==newpos[2]==newpos[3]:
            #print(time)
            return(time)
    return(-999)
for i in range (0,10000):
    results.append( onegame())
#print(results)
bins = np.arange(1,200)
hist = pyplot.hist(results,bins)
vals = hist[0]
print(max(results))
print(sum(vals*bins[:-1]))
print(sum(vals))
print(sum(vals*bins[:-1])/sum(vals))
pyplot.show()
