
lang = "fr"
inputStream = open(r"E:\Word2Vec\corpus\\" + lang + ".pos" , encoding = "utf-8")
outputStream = open(r"E:\Word2Vec\corpus\\" + lang + ".corpus" , "w" , encoding = "utf-8")
for line in inputStream:
    if(line.find("SENT") != -1):
        outputStream.write("\n")
    else:
        if(len(line.split("\t")) < 3):
            continue
        word = line.split("\t")[2].lower().strip()
        if(word.isalnum()):
            outputStream.write(word + " ")

outputStream.close()
inputStream.close()
