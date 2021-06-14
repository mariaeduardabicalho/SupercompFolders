import subprocess
import time



def roda(ex, in_f):
    with open(in_f) as f:
        start = time.perf_counter()
        proc = subprocess.run([ex], input=f.read(), text=True, capture_output=True)
        end = time.perf_counter()


    return proc.stdout, end-start

proc =roda('./busca-local-1', 'entradas-busca-local/in-0.txt')

print(proc)
