import sys

if (len(sys.argv) == 1):
	print("Non mi hai specificato il file")
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
	output.write("};\n")
	output.write("\n")
	output.write("#endif\n")
    
def defineConstructor(output):
	# rimuovi copyOf
	output.write("#include \"copyOf" + className + ".hpp\"\n\n")
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

output = open(sys.argv[1].replace(className, "copyOf" + className), "w")
findPrivateAttributes(open(sys.argv[1], 'r'), output)
declareConstructor(output)
output = open(sys.argv[1].replace("build/inc/" + className + ".hpp", "src/" + "copyOf" + className + ".cpp"), "w")
defineConstructor(output)
exit(0)
