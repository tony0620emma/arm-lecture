CFLAGS = -Wall -g -O0 --std=gnu99
BIN = test_v1 test_v2
MAIN = bitmap.c bitmap.h

test_v1: $(MAIN)
	$(CC) $(CFLAGS) -o $@ $^ -DVERSION1
	./$@

test_v2: $(MAIN)
	$(CC) $(CFLAGS) -o $@ $^ -DVERSION2
	./$@

.PHONY: clean

clean:
	rm -f $(BIN) *.o version_*.png
