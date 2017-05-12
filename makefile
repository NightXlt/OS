all : sender receiver
.PHONY : clean



sender : sender.o commonHeader.o
	cc -pthread -o sender sender.o commonHeader.o

receiver : receiver.o commonHeader.o
	cc -pthread -o receiver receiver.o commonHeader.o



sender.o : commonHeader.h

receiver.o : commonHeader.h

clean : 
	rm	receiver
	rm	sender 
	rm	*.o


