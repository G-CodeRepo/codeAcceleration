CFLAGS = 

default: app

run:
	./app 0.18

app: main.cpp
	g++ $(CFLAGS) main.cpp -o app

clean:
	/bin/rm -f */*.o *.o app GHZ_output.txt
