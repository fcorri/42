import sys
import os

if (len(sys.argv) == 1):
	print("File non specificato!")
	exit(1)

className = sys.argv[1].split('.')[0].split('/')[-1]
privateAttributes = []

def findPrivateAttributes(input, output):
	inAttributes = False
	for line in input:
		output.write(line)
		stripped = line.strip()
		if stripped == "private:":
			inAttributes = True
		elif inAttributes:
			if len(stripped) == 0:
				break
			else:
				privateAttributes.append(stripped[0:-1].split('\t'))

def declareConstructor(output):
	output.write("\tpublic:\n")
	output.write("\t\t" + className + "\n")
	output.write("\t\t(\n")
	for attribute in privateAttributes[:-1]:
		output.write("\t\t\t" + attribute[0] + "\t" + attribute[1] + ",\n")
	attribute = privateAttributes[-1]
	output.write("\t\t\t" + attribute[0] + "\t" + attribute[1] + "\n")
	output.write("\t\t);\n")

def declareGetters(output):
	output.write("\n")
	for attribute in privateAttributes:
		nameOfAttribute = attribute[1]
		output.write("\t\t" + attribute[0] + "\t" + "get" + nameOfAttribute[1].upper() + nameOfAttribute[2:] + "(void) const;\n")
    
def declareSetters(output):
	output.write("\n")
	for attribute in privateAttributes:
		nameOfAttribute = attribute[1]
		output.write("\t\tvoid\t" + "set" + nameOfAttribute[1].upper() + nameOfAttribute[2:] + "(" + attribute[0] + " " + nameOfAttribute[1:] + ");\n")

def writeLastLines(output):
	output.write("};\n")
	output.write("\n")
	output.write("#endif\n")

def defineConstructor(output):
	output.write("#include \"" + className + ".hpp\"\n\n")
	output.write(className + "::" + className + "\n")
	output.write("\t(\n")
	for attribute in privateAttributes[:-1]:
		output.write("\t\t" + attribute[0] + "\t" + attribute[1][1:] + ",\n")
	attribute = privateAttributes[-1]
	output.write("\t\t" + attribute[0] + "\t" + attribute[1][1:] + "\n")
	output.write("\t)\n")
	output.write("\t:\n")
	for attribute in privateAttributes[:-1]:
		nameOfAttribute = attribute[1]
		output.write("\t" + nameOfAttribute + "(" + nameOfAttribute[1:] + "),\n")
	nameOfAttribute = privateAttributes[-1][1]
	output.write("\t" + nameOfAttribute + "(" + nameOfAttribute[1:] + ")\n")
	output.write("\t{\n")
	output.write("\t\t\n")
	output.write("\t}\n")

def defineGetters(output):
	output.write("\n")
	for attribute in privateAttributes:
		nameOfAttribute = attribute[1]
		output.write("\t" + attribute[0] + "\t" + className + "::get" + nameOfAttribute[1].upper() + nameOfAttribute[2:] + "(void) const {\n")
		output.write("\t\treturn " + nameOfAttribute + ";\n")
		output.write("\t}\n\n")

def defineSetters(output):
	for attribute in privateAttributes:
		nameOfAttribute = attribute[1]
		output.write("\tvoid\t" + className + "::set" + nameOfAttribute[1].upper() + nameOfAttribute[2:] + "(" + attribute[0] + " " + nameOfAttribute[1:] + ") {\n");
		output.write("\t\t" + nameOfAttribute + " = " + nameOfAttribute[1:] + ";\n")
		output.write("\t}\n\n")

copy = sys.argv[1].replace(className, "copyOf" + className)
output = open(copy, "w")
findPrivateAttributes(open(sys.argv[1], 'r'), output)
declareConstructor(output)
declareGetters(output)
declareSetters(output)
writeLastLines(output)
os.remove(sys.argv[1])
os.rename(copy, sys.argv[1])
output = open(sys.argv[1].replace("build/inc/" + className + ".hpp", "src/" + className + ".cpp"), "w")
defineConstructor(output)
defineGetters(output)
defineSetters(output)
exit(0)
