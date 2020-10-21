def swapBits(x, b1, b2, n): 
  
    set1 =  (x >> b1) & ((1<< n) - 1) 
   
    set2 =  (x >> b2) & ((1 << n) - 1) 
    
    xor = (set1 ^ set2) 

    xor = (xor << b1) | (xor << b2) 
   
    result = x ^ xor 
   
    return result 
  
test = swapBits(1, 0, 1, 2) 
print("Swap =", test) 
  