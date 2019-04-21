default:
	gcc -g -o run matmul_opt.c

go:
	./run 5 5 5 >> test.txt

test:
	diff correct.txt test.txt
clean:
	rm run
