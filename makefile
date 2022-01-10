all: bin/app

bin/app: obj/main.o obj/shape.o obj/tensor.o
	gcc $^ -o $@

obj/%.o: src/%.c
	gcc -c $^ -o $@

clean:
	rm bin/* obj/*
run:
	./bin/app
