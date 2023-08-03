bin/perceptron.o: bin/in_node.o bin/node.o
	g++ -c src/perceptron.cc -o bin/perceptron.o
bin/in_node.o:
	g++ -c src/in_node.cc -o bin/in_node.o
bin/node.o:
	g++ -c src/node.cc -o bin/node.o
clean:
	rm bin/*
