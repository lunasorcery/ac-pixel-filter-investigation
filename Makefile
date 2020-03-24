bin/tool: main.cpp xbrz1.8/*.h xbrz1.8/*.cpp
	mkdir -p bin
	clang -o bin/tool xbrz1.8/xbrz.cpp main.cpp -std=c++17 -DNDEBUG -lstdc++

clean:
	rm -f bin/*