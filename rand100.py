import random
import sys

randoms = []

size = 100;

if len(sys.argv) == 3:
    while len(randoms) < int(100):
        l_ran = random.randint(int(sys.argv[1]),int(sys.argv[2]))
        if l_ran not in randoms:
            randoms.append(l_ran)
    
    for l_ran in randoms:
        print(l_ran)
