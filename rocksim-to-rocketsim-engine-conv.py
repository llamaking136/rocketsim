# i hate xml

import sys
import os
import xml.etree.ElementTree as ET

tree = ET.parse(sys.argv[1])

root = tree.getroot()

if root[0].tag != "engine-list":
    print("error: file inputted is incorrect!")
    exit(1)

engine_data = []

for i in root[0][0][1]:
    if i.tag != "eng-data":
        print("error: cannot find engine data!")
        exit(1)
    engine_data.append(i.attrib)

f = open(sys.argv[1] + ".csv", "w")
f.write("Time,Thrust\n")

for i in engine_data:
    f.write(str(round(float(i["t"]), 2)) + "," + str(float(i["f"])) + "\n")

f.close()

print("done, saved as " + sys.argv[1] + ".csv")
