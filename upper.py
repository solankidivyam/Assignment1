file1 = open("original.txt", "r")
file2 = open("upper.txt", "w")

#We are reading and writing from original.txt and writing in upper.txt

l = file1.readline()

while l:
    k = l.swapcase()
    #Swapcase is a function in Python which we can use directly
    file2.write(k)
    #Writing the line in the new file and thus it changes the case of the orginal final into the new one.
    l = file1.readline()

file1.close()
file2.close()



  
