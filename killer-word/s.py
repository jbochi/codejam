import sys

def best(D, L):
	best = ""
	nbest = -1
	for solution in D:
		n = n_attemps(solution, D, L)
		#print solution, n
		if n > nbest:
			nbest = n
			best = solution
	
	return best

def matches(known, guess, founds, not_found):
	return len(known) == len(guess) and \
	       all(letter not in guess for letter in not_found) and \
	       all((known[i] == "_" and guess[i] not in founds) or known[i] == guess[i] for i in xrange(len(guess)))
	

def n_attemps(solution, D, L):
	known = ["_" for i in xrange(len(solution))]
	founds = []
	not_found = []
	attemps = 0
	for letter in L:
		if any(matches(known, guess, founds, not_found) for guess in D if letter in guess):
			found = False
			done = True
			for i in xrange(len(solution)):
				if solution[i] == letter:
					found = True
					known[i] = letter
				if known[i] == "_":
					done = False

			#sys.stdout.write("%s %s %s\n" % (known, attemps, letter))

			if done:
				return attemps
			elif not found:
				not_found.append(letter)
				attemps += 1
			else:
				founds.append(letter)

	raise ValueError("bosta")


def main():
	cases = int(raw_input())
	for case in xrange(1, cases + 1):
		nD, nL = map(int, raw_input().split(" "))
		sys.stdout.write("Case #%s:" % (case, ))
		D = []
		for i in xrange(nD):
			D.append(raw_input())

		for i in xrange(nL):
			L = raw_input()
			solution = best(D, L)
			sys.stdout.write(" %s" % (solution, ))
		
		sys.stdout.write("\n") 

if __name__ == '__main__':
	main()
