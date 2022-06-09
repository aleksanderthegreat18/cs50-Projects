# TODO
from cs50 import SQL
import sys
import csv
if len(sys.argv) == 2:
    house = sys.argv[1]
    db = SQL("sqlite:///students.db")
    rows = db.execute("SELECT first, middle, last, birth FROM students WHERE house = ? ORDER BY last, first", house)
    for row in rows:
        temp = []
        for i, a in row.items():
            temp.append(str(a))
        if temp[1] == "None":
            print(str(temp[0]) + " " + str(temp[2]) + ", born " + str(temp[3]))
        else:
            print(str(temp[0]) + " " + str(temp[1]) + " " + str(temp[2]) + ", born " + str(temp[3]))
else:
    print("2 arguements required")