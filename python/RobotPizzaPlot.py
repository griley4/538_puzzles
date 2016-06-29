#! /usr/bin/env python

import sys
import matplotlib.pyplot as pyplot
import pandas as pd

for filename in sys.argv[1:]:
  with open(filename,'rt') as sf:
    data = pd.read_csv(sf, header=None, delim_whitespace=True)
#    print (data[2])
    pyplot.hist(data[2])
pyplot.show()
