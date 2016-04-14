#Lisa Carter Section 1
# build an executable named huffman 
all: huffman

huffman: main.cpp StanfordCPPLib/bitstream.cpp StanfordCPPLib/strlib.cpp StanfordCPPLib/error.cpp
	g++ -g main.cpp StanfordCPPLib/bitstream.cpp  StanfordCPPLib/strlib.cpp StanfordCPPLib/error.cpp -o huffman

clean: 
	$(RM) huffman
