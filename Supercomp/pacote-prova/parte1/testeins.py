import numpy as np
import numpy.random

x=1
y=0

f = open("in3.txt", "wb")

n = 5
f.write("%s \n" % (n))
for i in range(n):
    
    x = np.random.random_integers(1,10)
    f.write("%s " % (x))

    f.write("\n")

for i in range(n):
    
    x = np.random.random_integers(1,10)
    f.write("%s " % (x))
    
    f.write("\n")

f.close()





