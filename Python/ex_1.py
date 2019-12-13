def h(x):
  (m,a) = (1,0)
  while m <= x:
      (m,a) = (m*2,a+1)
  return(a)

print (h(3231))
