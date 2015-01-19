all:
	mkdir -p object
	cd object && cmake ../
	cd object && make -j4
clean:
	rm -rf object
test:
	cd approot && ../object/wator/wator
	
