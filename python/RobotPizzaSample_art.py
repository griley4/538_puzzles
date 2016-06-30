#! /usr/bin/env python

import sys
import matplotlib.pyplot as pyplot
import pandas as pd

for filename in sys.argv[1:]:
  with open(filename,'rt') as sf:
    data = pd.read_csv(sf, header=None, delim_whitespace=True)
#    print(data.iloc[4,0])
#  pyplot.hist(data[2], normed=1, bins=[3,4,5,6,7,8,9])
  for i in range(len(data[0])):
    plotN = i+1
    fig=pyplot.figure()
    ax=fig.add_subplot(1,1,1)  
    pyplot.plot([-1.,1],[data.iloc[i,4]-data.iloc[i,3],data.iloc[i,3]+data.iloc[i,4]])
    pyplot.plot([-1.,1],[data.iloc[i,6]-data.iloc[i,5],data.iloc[i,5]+data.iloc[i,6]])
    pyplot.plot([-1.,1],[data.iloc[i,8]-data.iloc[i,7],data.iloc[i,7]+data.iloc[i,8]])
    circ=pyplot.Circle((0, 0), radius=1, color='y', alpha=0.2)
    pyplot.ylim([-1,1])
    pyplot.xlim([-1,1])
    ax.add_patch(circ)
    pyplot.show()
