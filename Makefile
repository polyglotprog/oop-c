CC ?= gcc

demo:
	@$(CC) -o demo src/*.c
	@echo "Built demo"
