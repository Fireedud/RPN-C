"""A RPN Calculator

	Arguments are separated by spaces or tabs"""

import operator
import math

ops = {"+": operator.add,
		"-": operator.sub,
		"*": operator.mul,
		"/": operator.truediv,
		"sin": math.sin,
		"cos": math.cos,
		"tan": math.tan,
		"!": math.factorial}

#I might be able to remove this function if I use partials
def num_args(op):
		"""Returns the number of arguments an operation requires"""
		num = 0
		if op in "+-*/":
				num = 2
		elif op in ["sin", "cos", "tan", "!"]:
				num = 1
		if num:
				return num
		else:
				raise NotImplementedError

def parse(args):
	"""Takes an Iterable"""
	stack = []
	for arg in args:
		try:
			stack.append(float(arg))
			#only do floats if it is not an int
		except ValueError:
			num = num_args(arg)
			if num==1:
					stack.append(ops[arg](stack.pop()))
			elif num==2:
				m = stack.pop()
				n = stack.pop()
				stack.append(ops[arg](n,m))
			else:
					raise NotImplementedError
					#I don't anticipate on having functions
					#that take >2 args, but it can't hurt
					#to have this
	return stack.pop()

if __name__ == "__main__":
	expr = input()
	while expr:
		print(parse(expr.split()))
		expr = input()
