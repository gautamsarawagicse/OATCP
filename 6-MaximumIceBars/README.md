
1. To find the maximum number of ice creams the boy can buy, he can start picking the cheapest ice creams.
2. By picking the cheapest ice creams , he can buy the more number of ice creams, as he may be left with some coins.
3. To perform this we will sort the costs array, then will loop through the cost array.
4. At every elements of the costs array, we will check if we can buy the ice cream, if we can we will increase our answer by 1 and also decrease the remaining coins with us at the same time.
5. If at any point , we find the cost of the icecream is more than the coins we currently have, then we will break through the loop as the ice cream after this will also have higher cost then the coins we currently hold as it is sorted in increasing order.
6. After performing the above operations , we will print the number of ice creams we have and that will be the maximum number of icecream bars we can buy from the whole cost array. 
 
