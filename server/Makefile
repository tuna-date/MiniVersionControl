HELPER = ../helper
SOCKET_VALIDATE = socket_validate.c
MESSAGE_HANDLER = message_handler.c
TRANSFER_HANDLER = transfer_handler.c
FILE_HANDLER = file_handler.c
SERVER_RQ_HANDLER = server_request_handler.c
ACCOUNT_HANDLER = account_handler.c -lsqlite3 
MIGRATE_DB = migrate_db.c -lsqlite3

all:
	make server

server:
	gcc -o th-server th-server.c $(HELPER)/$(SERVER_RQ_HANDLER) $(HELPER)/$(TRANSFER_HANDLER) $(HELPER)/$(SOCKET_VALIDATE)\
								 $(HELPER)/$(MESSAGE_HANDLER) $(HELPER)/$(ACCOUNT_HANDLER) $(HELPER)/$(FILE_HANDLER) -lsqlite3
	gcc -o th-test th-test.c $(HELPER)/$(FILE_HANDLER)
	