import sys

cases = int(raw_input())

def best(list):
	m = -1
	l = len(list)
	for i in xrange(1, pow(2, l) - 1):
		total = 0
		wrong_total = 0;
		wrong_total2 = 0;

		mask = int(i)
		taken = []
		not_taken = []
		for j in xrange(l):
			if mask & 1:
				#sys.stdout.write("%d " % (list[j],))
				total += list[j]
				wrong_total ^= list[j]
			else:
				wrong_total2 ^= list[j]
			mask = mask >> 1

		#sys.stdout.write("\n")
		if (wrong_total == wrong_total2) and (total > m):
			m = total
	
	return m
		

def main():
	for case in range(1, cases + 1):
		n = int(raw_input())
		elements = [int(e) for e in raw_input().split(' ')]
		t = best(elements)
		
		sys.stdout.write("Case #%s: %s\n" % (case, t if t > 0 else 'NO'))

if __name__ == '__main__':
	main()
