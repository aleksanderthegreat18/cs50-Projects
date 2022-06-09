# TODO
from cs50 import SQL
import sys
import csv
if len(sys.argv) == 2:
    db = SQL("sqlite:///students.db")
    with open(sys.argv[1]) as csv_file:
        csv_reader = csv.reader(csv_file, delimiter=',')
        rc = 0
        sc = 0
        for row in csv_reader:
            name = row[0]
            name_list = name.split()

            if len(name_list) == 2:
                first_name = name_list[0]
                last_name = name_list[1]
                db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)",
                           first_name, None, last_name, row[1], row[2])
            elif len(name_list) == 3:
                first_name = name_list[0]
                middle_name = name_list[1]
                last_name = name_list[2]
                db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)",
                           first_name, middle_name, last_name, row[1], row[2])
                    
                        
else:
    print("2 arguements required")