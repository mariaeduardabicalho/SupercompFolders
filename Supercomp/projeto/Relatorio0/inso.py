import numpy as np
import numpy.random

x=1
y=0

# arqs = [f"in/in{i}.txt" for i in range(25)]

for i in range(300):
# for item in items:
    with open("ino/in{}.txt".format(i), "wb") as f:

    # f = open(arqs[i] , "wb")
        m = 5 + int(i/2)
        n=2*i
        f.write("%s %s\n" % (n,m))
        for i in range(n):
            
            x = np.random.random_integers(1,100)
            f.write("%s " % (x))

        f.close()





