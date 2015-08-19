CFLAGS = -Wall -g -O0 --std=gnu99
BIN = phonebook_test phonebook_v1 phonebook_v2 benchmark

benchmark: benchmark.c findGCD.h
	$(CC) $(CFLAGS) -o $@ $^

run-benchmark: benchmark
	./benchmark

phonebook_test: phonebook_testbench.c phonebook_v1.h phonebook_v2.h
	$(CC) $(CFLAGS) -o $@ $^
	./$@

phonebook_v1: phonebook_v1.c phonebook_v1.h 
	$(CC) $(CFLAGS) -o $@ $^

phonebook_v2: phonebook_v2.c phonebook_v2.h 
	$(CC) $(CFLAGS) -o $@ $^

test: phonebook_v1 phonebook_v2
	perf stat -e cache-misses,cache-references ./phonebook_v1
	perf stat -e cache-misses,cache-references ./phonebook_v2

cache-misses: 
	perf stat -e cache-misses,cache-references ./$^

clean:
	rm -f *.o $(BIN) perf.*
