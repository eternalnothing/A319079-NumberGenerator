# A319079-NumberGenerator
The 3n+1 problem is a well known problem is mathematics. Start with any number. Then, divide the number by 2 if it is even or multiply the number by 3 and add 1 to it if it is odd. Continue this procedure with the resulting number. The Collatz Conjecture states that every starting number will eventually reach 1. For example, the sequence that starts with 13 is given below:
13 -> 40 -> 20 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1 -> 4 -> 2 -> 1 -> ...

This number generator looks at a more generalized form of the 3n+1 problem which is kn+c problem. In this problem k is a fixed integer but c may change at every step of the sequence. The value of c at a step is chosen such that adding it would make the next number in the sequence divisible by (k-1). 3n+1 problem is a special case where the c is constant because to make an odd number divisible by 2, you would always need to add 1 to it.

For example, let k=6, then the sequence that starts with 13 goes like below:
13 -> 80 -> 16 -> 100 -> 20 -> 4 -> 25 -> 5 -> 1 -> ...

This generator finds the numbers k, for which there exists a sequence that does not include 1. For example, this number generator would find k=4 because if you start a sequence with 7 and k=4, then the sequence is given below:
7 -> 30 -> 10 -> 42 -> 14 -> 7 -> 30 -> ...

As you can see this repeating sequence does not include 1. Hence, when k=4 there exists a sequence that does not include 1.
