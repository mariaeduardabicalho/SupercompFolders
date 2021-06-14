import subprocess
import time
import matplotlib.pyplot as plt
    
#Plotagem
def roda(ex, in_f):
    with open(in_f) as f:
        start = time.perf_counter()
        proc = subprocess.run([ex], input=f.read(), text=True, capture_output=True)
        end = time.perf_counter()
    return proc.stdout, end-start
arqs = [f"inp/in{i}.txt" for i in range(1,25)]


heuristica=[]
outsh=[]
outsl=[]

local=[]
for arq in arqs:
    heuristica.append(roda('./heuristica', arq)[1])
    with open("out.txt",'r') as f:
        line = f.readlines()
        outsh.append(int(line[0]))
import matplotlib.pyplot as plt
for arq in arqs:
    local.append(roda('./local', arq)[1])
    with open("out.txt",'r') as f:
        line = f.readlines()
        outsl.append(int(line[0]))

print(outsh)
plt.plot(outsh)
plt.plot(outsl)
print(outsl)
        
