all:
	@echo 'Build unit tests ...'
ifeq (,$(wildcard ./catch2.hpp))
	@wget https://raw.githubusercontent.com/catchorg/Catch2/3701c2e2e645df69e28914c72bf5c75158fa6613/single_include/catch2/catch.hpp -O catch2.hpp
endif
	@mkdir -p bin
	@g++ unit.cpp -o bin/unit 
run:
	@echo 'Run tests ...'
	@./bin/unit
clean:
	@rm -r ./bin
rebuild:
	@make clean
	@make all