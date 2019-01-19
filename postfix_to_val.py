def result(f,s,i):
	if i is '^':
		return f**s
	elif i is '/':
		return f/s
	elif i is '*':
		return f*s
	elif i is '%':
		return f%s
	elif i is '+':
		return f+s
	elif i is '-':
		return f-s


def postfix_to_value(expr):
	value = [];no = 0
	for i in expr:
		if i >='0' and i<= '9':
			no += no*10+int(i)
			continue
		if no>0:
			value.append(str(no));no=0
		if i in ['+','-','^','*','/','%']:
			s = value[-1];f = value[-2]
			value.pop();value.pop()
			value.append(str(result(float(f),float(s),i)))
	return value[0]
if __name__ == '__main__':
	post = open("postfix", "r")
	expr = post.readline()
	value = postfix_to_value(expr)
	v = open("value","w")
	v.write(value);v.close()

