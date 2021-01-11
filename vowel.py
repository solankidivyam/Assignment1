file1 = open("original.txt", "r")
l = file1.readline()



def remove_vowel(string): 
    vowels = ('a', 'e', 'i', 'o', 'u')  
    for x in string.lower(): 
        if x in vowels: 
            string = string.replace(x, "") 
    return string          
    


while l:
    k = remove_vowel(l)
    l = file1.readline()
    print(k)



     

