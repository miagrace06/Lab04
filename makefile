all: anagrams stats

anagrams: anagrams.cpp
	g++ anagrams.cpp -o anagrams -std=c++11 -Wall

stats: stats.cpp
	g++ stats.cpp -o stats

clean:
	rm *.o anagrams stats
