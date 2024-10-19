def main():
   height = get_n()

   p = 0
   if p > height:
     return 1
# hight here is the number prompt from the user
   for h in range(height):
     # printing spaces to dcoot over the hash in sights
     for space in range(height-p-1):
       print(" " , end= "")
     # printing hashes after the spaces in the same
     for j in range(p+1):
       print("#" , end="")
     p += 1
     print()

def get_n():
  while True:
    n = int(input("n: "))
    if n > 0 or n < 8:
      break
  return n

main()

