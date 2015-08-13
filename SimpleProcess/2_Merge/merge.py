import os
import os.path

langSet = ["en","fr"]

for lang in langSet:
    mergeEn = open(r"E:\Word2Vec\corpus\\" + lang + ".txt" , "w" , encoding = "utf-8")

    for root , dirs , files in os.walk("E:\Word2Vec\corpus\\" + lang):
        for file in files:
            if(file.endswith("utf8")):
                en = open(os.path.join(root , file) , encoding = "utf-8")
                for line in en:
                    mergeEn.write(line)
                en.close()
    mergeEn.close()
