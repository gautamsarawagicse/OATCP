
1. For finding the largest number , we want that most significant bit (MSB) is occupied by larger number.
2. To do this we will make a custom sort function which will check if the addition of two numbers in string format i.e. we will do the concatenation of two strings and check if the concatenation of first with second is greater than the  second concatenated with first.
3. i.e. if string(a)+string(b) > string(b)+string(a)
4. After making the comparator function we will pass this custom made comparator function into the sort function.
5. After the custom sort based on larger numbers, we will concatenate every element of the nums by converting every elements into answer string.
6. (Corner Case):- before traversing the custom sorted nums array , we will check if the number of 0th place is 0, if yes then we will print 0 and return.
7. else Print the answer string.
