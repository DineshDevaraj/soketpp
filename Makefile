
GPP = g++

FLG = -g

HDR = soketpp.h

LIB = soketpp.cpp

SRV = server.cpp

CLN = client.cpp

all : server.x client.x

server.x : $(HDR) $(LIB) $(SRV)
	$(GPP) $(FLG) $(LIB) $(SRV) -o $@

client.x : $(HDR) $(LIB) $(CLN)
	$(GPP) $(FLG) $(LIB) $(CLN) -o $@

clean :
	rm server.x client.x
