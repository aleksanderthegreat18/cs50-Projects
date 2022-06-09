import sys
import csv
if len(sys.argv) == 3:
    s = str(open(sys.argv[2]).read())
    
    with open(sys.argv[1]) as csv_file:
        csv_reader = csv.reader(csv_file, delimiter=',')
        rc = 0
        str = []
        ppl = []
        for row in csv_reader:
            if rc == 0:
                str.append(row[1:])
            else:
                ppl.append(row)
            rc += 1
    mc = 0
    sc = 0
    rep = []
    strc = 0
    oor = 0
    for i in str:
        for a in i:
            strc += 1
    for i in str:
        for a in i:
            reps = []
            for l in range(0, len(s)):
                
                if a in s[l:l + len(a)]:
                    d = l
                    while a in s[d:d + len(a)]:
                        sc += 1
                        d = d + len(a)
                    reps.append(sc)
                else:
                    sc = 0
                d = l
            try:
                reps.sort()
                rep.append(reps[-1])
            except IndexError:
                oor += 1
    printed = 0
    for i in ppl:
        gc = 0
        count = 0
        for a in i[1:]:
            for num in rep:
                if int(a) == num:
                    gc += 1
                    break
        if gc == strc:
            print(i[0])
            printed = 1
    if printed == 0:
        print("No match")
else:
    print("Usage: python dna.py data.csv sequence.txt")