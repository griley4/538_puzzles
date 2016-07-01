#! /usr/bin/env python

import sys
import matplotlib.pyplot as pyplot
import pandas as pd

for filename in sys.argv[1:]:
  with open(filename,'rt') as sf:
    data = pd.read_csv(sf, header=None, delim_whitespace=True)
#    print(data.iloc[4,0])
#  pyplot.plot(data[2],ms=1.5,marker='o',mec='r',mfc='r',ls='None')
  pyplot.plot(data[6],ms=1.5,marker='o',mec='b',mfc='b',ls='None')
  pyplot.axvspan(0,1,color='b',alpha=0.5)
  pyplot.axvspan(0,3,color='g',alpha=0.5)
  pyplot.axvspan(0,23,color='y',alpha=0.3) 
  pyplot.axvspan(23.5,47,color='y',alpha=0.4) 
  pyplot.axvspan(47.5,71,color='y',alpha=0.5) 
pyplot.show()
