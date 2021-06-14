import numpy as np
import numpy.random

x=1
y=0

arqs = [f"in/in{i}.txt" for i in range(12)]

for i in range(50):

    f = open(arqs[i] , "wb")


    n = 2**i
    m=3
    f.write("%s %s\n" % (n,m))
    for i in range(n):
        for i in range(m):
            x = np.random.uniform(0 , 1)
            f.write("%s " % (x))
        f.write("\n")

    f.close()





