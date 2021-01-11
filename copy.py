file1 = open("original.txt", "r")
file2 = open("duplicate.txt", "w")
l = file1.readline()
while l:

        file2.write(l)
        l = file1.readline()

file1.close()
file2.close()

# log = open("/Users/divyamsolanki/Documents/Semester 4/CS206/lab/duplicate.txt", "r")
# for line in log:
#     print(line)
