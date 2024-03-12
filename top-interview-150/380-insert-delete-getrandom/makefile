# windows
all-cygwin: main-cygwin run-cygwin

main-cygwin: src/*.c src/main.h
	if not exist "target" mkdir target
	gcc ./src/*.c -o ./target/main.exe

run-cygwin: main-cygwin
	./target/main.exe

# linux/macos
all-gnu: main-gnu run-gnu

main-gnu: src/*.c src/main.h
	mkdir -p target
	gcc ./src/*/*.c ./src/main.c -o ./target/main

run-gnu: main-gnu
	./target/main


