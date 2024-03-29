/*******************
* SERVER REQUEST HANDLER
********************
*
* Hanlder request for server and more
*
********************/

#include "../helper/network_config.h"
#include "../helper/transfer_handler.h"

/* < Authentication Handler >
* @sockfd (input): socket file descriptor
* @buffer (input): request buffer sent from client
* @email (return value): store email return from handler
* @username (return value): store username return from handler
*/
int auth_handler(int sockfd, char* buffer, char* email, char* username);

/* < Signup Handler >
* @sockfd (input): socket file descriptor
* @buffer (input): request buffer sent from client
*/
void signup_handler(int sockfd, char* buffer);

/* < Create Repository Handler >
* @sockfd (input): socket file descriptor
* @buffer (input): request buffer sent from client
*/
void create_repo_handler(int sockfd, char* buffer, char *username, char*email);

/* < List of Repository Handler >
* @sockfd (input): socket file descriptor
* @buffer (input): request buffer sent from client
* @username (input): parse by server, use to query database
*/
void list_repo_handler(int sockfd, char* buffer, char *username);

/* < Logout Handler >
* @sockfd (input): socket file descriptor
* @buffer (input): request buffer sent from client
*/
int logout_handler(int sockfd, char* buffer);

/* < Clone Repository Handler >
* @sockfd (input): socket file descriptor
* @buffer (input): request buffer sent from client
* @username (input): parse by server, use to query database
*/
void clone_repo_handler(int sockfd, char* buffer, char *username);

/* < Compare Commits between Server and Client Handler >
* 
* @sockfd (input): socket file descriptor
* @buffer (input): request buffer sent from client
* @username (input): use for query db
*/
int get_server_commits_handler(int sockfd, char* buffer, char* username);

/* < Push Commits handler >
* 
* @sockfd (input): socket file descriptor
* @buffer (input): request buffer sent from client
* @username (input): use for query db
*/
int push_commits_handler(int sockfd, char* buffer, char* username);

/* < Define name of repository will be pulled  >
* 
* @sockfd (input): socket file descriptor
* @buffer (input): request buffer sent from client
* @username (input): use for query db
* @head (return value): list of commits that server will later send back to client
*/
int pull_commits_handler(int sockfd, char* buffer, char* username);

/* < Transfer a folder to client >
* @sockfd (input): socket file descriptor
* @folder_absolute_path (input): absolute path to transfer folder
* @folder_name: (input): name of transfer folder 
*/
int transfer_a_folder(int sockfd, char* folder_absolute_path, char* folder_name);