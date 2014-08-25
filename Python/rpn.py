"""A RPN Calculator

	Arguments are separated by spaces or tabs"""

from collections import deque
import operator

ops = {"+": operator.add,
		"-": operator.sub,
		"*": operator.mul,
		"/": operator.truediv}

def parse(args):
	"""Takes an Iterable"""
	stack = []
	for arg in args:
		try:
			stack.append(int(arg))
		except ValueError:
			m = stack.pop()
			n = stack.pop()
			stack.append(ops[arg](n,m))
	return stack.pop()

if __name__ == "__main__":
	expr = input()
	while expr:
		print(parse(expr.split()))
		expr = input()
