test: NameNormalizerTest
	./NameNormalizerTest

NameNormalizer.o: NameNormalizer.c include/NameNormalizer.h
	g++ -x c -I$(CPPUTEST_HOME)/include -Iinclude -c -Wall -g $<

NameNormalizerTest.o: NameNormalizerTest.cpp NameNormalizer.c include/NameNormalizer.h
	g++ -I$(CPPUTEST_HOME)/include -Iinclude -c -Wall -g $<

main.o: main.cpp
	g++ -I$(CPPUTEST_HOME)/include -c -Wall -g $<

NameNormalizerTest: main.o NameNormalizerTest.o NameNormalizer.o
	g++ -L$(CPPUTEST_HOME)/lib -lCppUTest -lCppUTestExt -o NameNormalizerTest $^

clean:
	rm *.o
	rm NameNormalizerTest

#  $@ target
#  $< first prereq
#  $^ all prereqs
#  $* target w/o extension
#  $+ all preqeqs including duplicates
#  $? all prereqs newer than target
