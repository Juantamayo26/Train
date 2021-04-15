Problem:
The problem can be seen as a KMP-like string search that allows for wildcard characters.
The wildcard would then match a single arbitrary character, so 'ABCD' matches 'A?CD' but not 'A?D' (if '?' is the wildcard).

Solution:
A fairly common problem is that of finding for each index in a large string S how many characters math a shorter string P.
This can be done in O(A*N*log(N)) by using FFT, where A is the size of the alphabet.
To let this solve our wildcard problem we use the above to count how many non-wildcard characters match and then add how many wilcard mathces there are.
If this adds up to the length of the shorter string, then there's a match.
To count how many wildcard matches there are we let 
	X be the number of wildcards in the substring of S that starts at the index in question and is the same length as P (sliding window),
	Y be the number of wildcards in P,
	and Z be the number of wildcard matches at the index in question (the FFT mentioned above gives us this).
The wildcard matches are then X + Y - Z.

This approaches would work for a small alphabet.
This can generally be improved.
Let A be the size of the alphabet and K be the smallest number of bits needed to represent each of the letters in the alphabet (cieling of the log).
We then change out each non-wildcard letter in the alphabet for the binary representation of it's index and the wildcard for K instances of '2'.
The increases the lengths of our strings by a factor of K, but reduces the size of the alphabet down to 3.
For example, if the alphabet is 'ABCD?', where '?' is the wildcard, S = 'AAB?CD?DC' then after the transformation S = '000001221011221110'.
We can now use the above, but only consider indexes in {K*I; where I is some natural number}.
This gives us a solution that's O(N*K*log(N)) = O(N*log(N)*log(A)).

Difficulty:
98/100

