BIN_FOLDER=./bin
CS_SRC_FOLDER=./src/client_server
CLIENT_OBJ=$(CS_SRC_FOLDER)/client/client.cpp $(CS_SRC_FOLDER)/client/TCPClient.cpp $(CS_SRC_FOLDER)/client/TCPClient.h
SERVER_OBJ=$(CS_SRC_FOLDER)/server/server.cpp $(CS_SRC_FOLDER)/server/TCPServer.cpp $(CS_SRC_FOLDER)/server/TCPServer.h

client_server: client server

client: $(CLIENT_OBJ)
	g++ -o $(BIN_FOLDER)/client.bin $(CLIENT_OBJ)

server: $(SERVER_OBJ)
	g++ -o $(BIN_FOLDER)/server.bin $(SERVER_OBJ)

clean:
	@rm $(BIN_FOLDER)/*