quickshoppr: GroceryStore.o GroceryAisle.o GroceryItem.o GroceryList.o main.o
	g++ -g GroceryStore.o GroceryAisle.o GroceryItem.o GroceryList.o main.o -o quickshoppr
GroceryStore.o: GroceryStore.cpp GroceryStore.h
	g++ -c -g GroceryStore.cpp
GroceryAisle.o: GroceryAisle.cpp GroceryAisle.h
	g++ -c -g GroceryAisle.cpp
GroceryItem.o: GroceryItem.cpp GroceryItem.h
	g++ -c -g GroceryItem.cpp
GroceryList.o: GroceryList.cpp GroceryList.h
	g++ -c -g GroceryList.cpp
main.o: main.cpp GroceryStore.h
	g++ -c -g main.cpp
clean:
	rm -f *.o
	rm quickshoppr
run: quickshoppr
	./quickshoppr
debug: quickshoppr
	sudo gdb ./quickshoppr
valgrind:
	valgrind ./quickshoppr
