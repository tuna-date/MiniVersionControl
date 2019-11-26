#include <sqlite3.h>
#include <stdio.h>

int main(void)
{
    sqlite3 *db;
    char *err_msg = 0;

    int rc = sqlite3_open("test.db", &db);

    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);

        return 1;
    }

    char *user_table = "DROP TABLE IF EXISTS users;"
                       "CREATE TABLE users(id INTEGER PRIMARY KEY, name TEXT, password TEXT, email TEXT);"
                       "INSERT INTO users(name, password, email) VALUES('hanhnguyen', '123456', 'hanh.shin.1998@gmail.com');"
                       "INSERT INTO users(name, password, email) VALUES('tuna', '111111', 'tu.na@gmail.com');";

    char *repository_table = "DROP TABLE IF EXISTS repositories;"
                             "CREATE TABLE repositories(id INTEGER PRIMARY KEY, main_account_id INT, contributor_id INT, name TEXT);"
                             "INSERT INTO repositories(main_account_id, contributor_id, name) VALUES (1, 2, 'programming-network');";

    rc = sqlite3_exec(db, user_table, 0, 0, &err_msg);
    rc = sqlite3_exec(db, repository_table, 0, 0, &err_msg);

    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "SQL error: %s\n", err_msg);

        sqlite3_free(err_msg);
        sqlite3_close(db);

        return 1;
    }

    sqlite3_close(db);
    return 0;
}