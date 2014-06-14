PROGRAM_SIZE ?= 2048

$(PROGRAM): $(PROGRAM_OBJS)
	sneslink -fsmc -s $(PROGRAM_SIZE) -o $@ $^

%.o65: %.a65
	snescom -J -Wall -o $@ $<

%.ips: %.a65
	snescom -I -J -Wall -o $@ $<

clean:
	rm -f *.ips *.o65 $(PROGRAM)

.PHONY: clean