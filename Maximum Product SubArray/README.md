
1. **Initialization**: Initialize variables to keep track of the current maximum product, current minimum product, and global maximum product. Set these variables to the first element of the array.
   
2. **Iteration**: Iterate through the array, starting from the second element.
   
3. **Update Current Max and Min**: Update the current maximum and minimum products considering three possibilities:
   - Multiplying the current element with the current maximum product.
   - Multiplying the current element with the current minimum product.
   - Considering only the current element itself.
   
4. **Update Global Max**: Update the global maximum product with the maximum of the current maximum product and the current global maximum product.
   
5. **Continue Iteration**: Repeat steps 3 and 4 until the end of the array is reached.

6. **Return Result**: Return the global maximum product as the final result.
