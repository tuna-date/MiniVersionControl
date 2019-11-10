#include "fileHandler.h"

void folder_structure(char *root_path, FILE **fo){
    struct dirent *de;  // Pointer for directory entry

    // opendir() returns a pointer of DIR type
    DIR *dr = opendir(root_path);

    if (dr == NULL) {
        // printf("Could not open current directory");
        return;
    }

    char buffer[256];

    while ((de = readdir(dr)) != NULL) {
        bzero(buffer, sizeof(buffer));
        if (strcmp(root_path, ".") == 0)
            sprintf(buffer, "%s", de->d_name);
        else
            sprintf(buffer, "%s%s", root_path, de->d_name);
        if (isDirectory(buffer) && isValidDirectory(buffer)){
            sprintf(buffer, "%s/", buffer);
            folder_structure(buffer, &(*fo));
        }
        if(!isDirectory(buffer)){
            fprintf(*fo, "%s\n", buffer);
        }
    }

    closedir(dr);
    return;
}

int isDirectory(const char *path) {
   struct stat statbuf;
   if (stat(path, &statbuf) != 0)
       return 0;
   return S_ISDIR(statbuf.st_mode);
}

int isValidDirectory(const char *path) {
    if(strcmp(path, th_folder) == 0)
        return 0;
    int i = strlen(path) - 1;
    int valid_dir_flag = 0;

    while (path[i] != '/' && i >= 0){
        if (isalpha(path[i]) || isdigit(path[i]) || path[i] == '_')
            valid_dir_flag = 1;
        i--;
    }
    if (valid_dir_flag == 1)
        return 1;
    else 
        return 0;
}

void getUserInfo(char *filename, char *username, char *email) {
    FILE *fi;
    if((fi = fopen(filename, "r")) == NULL) {
        printf("Unable to open file %s\n", filename);
        return;
    }

    // Array of string to get info
    char strArr[10][MAXLEN];
    char str[MAXLEN];

    while(fgets(str, MAXLEN, fi) != NULL) {
        strTokenize(str, strArr, DELIM);
        if (strcmp("username:", strArr[0]) == 0) {
            strcpy(username, strArr[1]);
            username[strlen(username) - 1] = '\0';
        } else if (strcmp("email:", strArr[0]) == 0) {
            strcpy(email, strArr[1]);
            email[strlen(email) - 1] = '\0';
        }
    }

    return;
}

void strTokenize(char *string, char strArr[10][MAXLEN], char *delim) {
    int i = 0;
    char str[MAXLEN];
    char *token;

    token = strtok(string, delim);

    while( token != NULL ) {
        strcpy(strArr[i++], token);
        token = strtok(NULL, delim);
   }

   return;
}