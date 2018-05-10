#!usr/bin/python3

t = int(input())
while t:
	inp = input()
	inp_list = inp.split(' ')
	sub = 'machula'
	machu = s for s in inp_list if sub in s
	machu_index = inp_list.index(machu)
	
	t = t-1