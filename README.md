# randomize-by-probability

This program is my attempt to solve the below problem.

## Problem
A certain company has different sized servers that process documents in its data centers. To load balance jobs across the
servers, each job is assigned to a random server such that if server X is three times as big as server Y, then server
X gets assigned three times as often as server Y. So server X would be assigned approximately 75% of the time and
server Y would be assigned 25% of the time.
Write a program in any programming language that takes server names and sizes as arguments and outputs the
name of a random server based on the algorithm described above. For instance:

```
bash-3.2$ program X:3 Y:1
X

bash-3.2$ program X:3 Y:1
Y

bash-3.2$ program X:3 Y:1
X

bash-3.2$ program X:3 Y:1
X
```

There can be any number of servers passed on the command-line:
```
bash-3.2$ program A:3 B:2 C:4 D:4 E:1
C

bash-3.2$ program X:3 Y:1 Z:3
X
```

## Run
To run the program:
```
git clone https://github.com/itodotimothy6/randomize-by-probability.git

cd randomize-by-probability/

./run.sh X:3 Y:1
```
**P.S:** You can change the args. For instance:
```
./run.sh A:3 B:2 C:4 D:4 E:1
```
