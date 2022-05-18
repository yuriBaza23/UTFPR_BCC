all:
	gcc ./ED1/$(pasta)/$(run).c -o ./ED1/$(pasta)/executaveis/$(run)
	./ED1/$(pasta)/executaveis/$(run)

compile: 
	gcc -c ./ED1/$(pasta)/$(bin).c -o ./ED1/$(pasta)/bin/$(bin).o
	gcc ./ED1/$(pasta)/$(main).c ./ED1/$(pasta)/bin/$(bin).o -o ./ED1/$(pasta)/executaveis/$(main)
	./ED1/$(pasta)/executaveis/$(main)