# compile the C program with the -g flag, which allows
# the compiler to collect debugging information
cc -std=c99 -Wall -g $1 -o build/$2

# start the debugger
gdb /build/$2

# ref: https://u.osu.edu/cstutorials/2018/09/28/how-to-debug-c-program-using-gdb-in-6-simple-steps/