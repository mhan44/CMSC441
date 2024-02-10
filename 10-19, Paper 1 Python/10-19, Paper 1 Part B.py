import random
import timeit
from random import randrange
from timeit import default_timer as timer
def main():
    print("Enter size of array: ")
    n = input()
    A = []
    for i in range(0,int(n)):
        A.append(randrange(0,100))
    #print(A)

    start = timer()
    B = []
    count = 0
    for i in range(0, int(n), 2):
        if(A[i] > A[i+1]):
            B.append(A[i])
            count += 1
        else:
            B.append(A[i+1])
            count += 1

    max = B[0]
    for i in range(0, int((int(n)/2))):
        if(B[i] > max):
            max = B[i]

    print("Max of input array = ", max, '\n')
    end = timer()
    seconds = end - start
    print("Time in micro seconds: ", seconds * float(10^6))


if __name__ == "__main__":
    main()
