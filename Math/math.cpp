/*
Picks theorem
Given a certain lattice polygon with non-zero area.

We denote its area by S, the number of points with integer coordinates lying strictly inside the polygon by I and the number of points lying on polygon sides by B.

Then, the Pick's formula states:

S=I+B/2−1


Burnsides Lemma
Let G be the finite group of operations we can perform on X
The number of orbits of X is the average of the number of fixed points for each g in G
G must be closed, associative, have identity, and inverses
A fixed point wrt g is an element of X such that g.x = x, That is, x is unchanged by the group operation.
For an element x, the orbit G.x is the set of all possible results of transforming x. Orbits partition X.

Example: color a square under rotation
G has 4 elements: rotate by x clockwise
X contains 16 colorings if rotations are distinct
Count number of fixed points = 16+2+2+4=24
Number of distinct colorings = 24/4=6

Nim
Win if xor of pile sizes is not zero

Sprague-Grundy theorem
Let's consider a state v of a two-player impartial game and let vi be the states reachable from it (where i∈{1,2,…,k},k≥0). To this state, we can assign a fully equivalent game of Nim with one pile of size x. The number x is called the Grundy value or nim-value of state v.

Moreover, this number can be found in the following recursive way:

x=mex {x1,…,xk}, where xi is the Grundy value for state vi and the function mex (minimum excludant) is the smallest non-negative integer not found in the given set.

Viewing the game as a graph, we can gradually calculate the Grundy values starting from vertices without outgoing edges. Grundy value being equal to zero means a state is losing.

Number Theory

Totient function is the number of positive integers no more than n which is coprime with n.
Formula is n * (product over p|n)(1 - 1/p)
Sum (d|n) totient(n) = n

Mobius function
What is mobius function? This function has lots of definitions.
However, the main definition is the following.

\mu (n) is 1 if n=1 or n is square-free and has even number of prime divisors.
\mu (n) is -1 if n is square-free and has odd number of prime divisors.
\mu (n) is 0 if n is not square-free.

\mu (n) also has a lot of interesting properties that make \mu (n) so important.

\sum_{d|n} \mu (d) = 0 for all n>1, and \mu (n) is multiplicative.
(A function f is multiplicative if f(mn)=f(m)f(n) for all (m,n)=1.)

Enumberating submasks in O(3^n)
for (int m=0; m<(1<<n); ++m)
    for (int s=m; s; s=(s-1)&m)
 ... s and m ...

Catalan numbers
The first few numbers Catalan numbers, Cn (starting from zero):
1,1,2,5,14,42,132,429,1430,…
C_n = (2n choose n)/(n+1)
The Catalan number Cn is the solution for:
Number of correct bracket sequence consisting of n opening and n closing brackets.
The number of rooted full binary trees with n+1 leaves (vertices are not numbered). A rooted binary tree is full if every vertex has either two children or no children.
The number of ways to completely parenthesize n+1 factors.
The number of triangulations of a convex polygon with n+2 sides (i.e. the number of partitions of polygon into disjoint triangles by using the diagonals).
The number of ways to connect the 2n points on a circle to form n disjoint chords.
The number of non-isomorphic full binary trees with n internal nodes (i.e. nodes having at least one son).
The number of monotonic lattice paths from point (0,0) to point (n,n) in a square lattice of size n×n, which do not pass above the main diagonal (i.e. connecting (0,0) to (n,n)).
Number of permutations of length n that can be stack sorted (i.e. it can be shown that the rearrangement is stack sorted if and only if there is no such index i<j<k, such that ak<ai<aj ).
The number of non-crossing partitions of a set of n elements.
The number of ways to cover the ladder 1…n using n rectangles (The ladder consists of n columns, where ith column has a height i).
*/