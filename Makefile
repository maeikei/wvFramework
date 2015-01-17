all:
	mkdir -p object
	cd object && cmake ../
	cd object && make 
clean:
	rm -rf object
