f  = open("main.cpp", "r")
n = open("clean.cpp", "w")
for s in f:
    if("std::cout" not in s and "std::cout << best << '\n';" not in s):
        n.write(s)
f.close()
n.close()