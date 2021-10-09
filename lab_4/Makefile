install:
	@for file in *.cpp; do \
		g++ $$file -o ./build/$${file: 0: $${#file}-4}; \
		echo Compiling $${file: 0: $${#file}-4}: Done; \
	done

