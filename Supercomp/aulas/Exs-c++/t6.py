
x=1
y=0

f = open("innnnn.txt", "wb")


for i in range(10):
    for j in range(20):
        print("foi")
        l=[x,y]
        f.write("%s %s\n" % (x,y))
        y+=1
    x+=1

f.close()





