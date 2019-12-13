def f(n): 
      s=0
      for i in range(1,n+1):
         if n%i == 0:
              s = s+1
      return(s%2 == 1)
print (f(19))
print (f(14))
print (f(5))
print (f(100))
