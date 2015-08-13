num = (50 , 100 , 200 , 400 , 800)

osFile = open("trec.sh" , "w")
for i in num:
    for j in num:
        osFile.write(r"SimpleProcess/5_trec/trec_eval.8.1/trec_eval -q -c -M100 corpus/test.gold corpus/WordVec2/test_" + str(i) + "_" + str(j) + r".result > corpus/re_2/re_" + str(i) + "_" + str(j) + r".txt" + "\n")
osFile.close()
