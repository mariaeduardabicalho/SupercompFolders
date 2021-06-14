
import subprocess
import time
import matplotlib.pyplot as plt


# #include <iostream>
# #include <chrono>

# int main(){
#     auto start = std::chrono::steady_clock::now();
#     int n;
#     std::cin >> n;
#     double b = double (n)/2;
#     std::cout << "Saída " << b << "\n";  
#     auto end = std::chrono::steady_clock::now();
#     std::chrono::duration<double> elapsed_seconds = end-start;
#     std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
# }


def roda(ex, in_f):
    with open(in_f) as f:
        start = time.perf_counter()
        proc = subprocess.run([ex], input=f.read(), text=True, capture_output=True)
        end = time.perf_counter()
    return proc.stdout, end-start



arqs = [f"in/in{i}.txt" for i in range(12)]

heuristica = [roda('./heuristica', arq)[1] for arq in arqs]
print("sai heuristica")
local = [roda('./local', arq)[1] for arq in arqs]
# exaustiva = [roda('./exaustiva', arq)[1] for arq in arqs]

# N = []
# for arq in arqs:
#     with open(arq) as f:
#         n = int(f.readlines()[0])
#         N.append(n)
# print(N)

print(heuristica)
print(local )
plt.plot(heuristica)
plt.show()
plt.plot(local)
plt.show()
# plt.plot(exaustiva)

