#Lisa Carter Section 1
# build an executable named huffman 
all: huffman

huffman: testbin.cpp StanfordCPPLib/bitstream.cpp StanfordCPPLib/strlib.cpp StanfordCPPLib/error.cpp
	g++ testbin.cpp StanfordCPPLib/bitstream.cpp  StanfordCPPLib/strlib.cpp StanfordCPPLib/error.cpp -o huffman

clean: 
	$(RM) huffman
