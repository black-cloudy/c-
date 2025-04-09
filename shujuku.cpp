#include <iostream>
#include <sqlite3.h> // 包含 SQLite3 头文件
#include <cstring>    // 包含 C 风格字符串操作头文件
using namespace std;

// 回调函数，用于打印查询结果
int printQueryResult(void* data, int argc, char** argv, char** colName) {
    cout << static_cast<const char*>(data) << endl;
    for (int i = 0; i < argc; i++) {
        cout << colName[i] << ": " << (argv[i] ? argv[i] : "NULL") << endl;
    }
    cout << endl;
    return 0;
}

int main() {
    sqlite3* db;                      // SQLite3 数据库指针
    char* errorMessage = nullptr;     // 错误信息
    int resultCode;                   // 返回的操作结果码
    const char* data = "Query Result:";

    // 打开或创建数据库
    resultCode = sqlite3_open("example.db", &db);
    if (resultCode != SQLITE_OK) {
        cerr << "Database open failed: " << sqlite3_errmsg(db) << endl;
        return -1;
    }
    cout << "Database opened successfully!" << endl;

    // 创建表SQL语句
    const char* createTableSQL =
        "CREATE TABLE IF NOT EXISTS Students("
        "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
        "Name TEXT NOT NULL, "
        "Age INTEGER, "
        "Grade TEXT);";

    resultCode = sqlite3_exec(db, createTableSQL, 0, 0, &errorMessage);
    if (resultCode != SQLITE_OK) {
        cerr << "Error creating table: " << errorMessage << endl;
        sqlite3_free(errorMessage);
    } else {
        cout << "Table created successfully!" << endl;
    }

    // 插入数据SQL语句
    const char* insertSQL =
        "INSERT INTO Students (Name, Age, Grade) "
        "VALUES ('Alice', 20, 'A'), ('Bob', 22, 'B'), ('Charlie', 18, 'A');";

    resultCode = sqlite3_exec(db, insertSQL, 0, 0, &errorMessage);
    if (resultCode != SQLITE_OK) {
        cerr << "Error inserting data: " << errorMessage << endl;
        sqlite3_free(errorMessage);
    } else {
        cout << "Data inserted successfully!" << endl;
    }

    // 查询数据
    const char* selectSQL = "SELECT * FROM Students;";
    resultCode = sqlite3_exec(db, selectSQL, printQueryResult, (void*)data, &errorMessage);
    if (resultCode != SQLITE_OK) {
        cerr << "Error querying data: " << errorMessage << endl;
        sqlite3_free(errorMessage);
    } else {
        cout << "Query executed successfully!" << endl;
    }

    // 更新数据
    const char* updateSQL = "UPDATE Students SET Grade = 'A+' WHERE Name = 'Bob';";
    resultCode = sqlite3_exec(db, updateSQL, 0, 0, &errorMessage);
    if (resultCode != SQLITE_OK) {
        cerr << "Error updating data: " << errorMessage << endl;
        sqlite3_free(errorMessage);
    } else {
        cout << "Data updated successfully!" << endl;
    }

    // 删除数据
    const char* deleteSQL = "DELETE FROM Students WHERE Name = 'Charlie';";
    resultCode = sqlite3_exec(db, deleteSQL, 0, 0, &errorMessage);
    if (resultCode != SQLITE_OK) {
        cerr << "Error deleting data: " << errorMessage << endl;
        sqlite3_free(errorMessage);
    } else {
        cout << "Data deleted successfully!" << endl;
    }

    // 关闭数据库
    sqlite3_close(db);
    cout << "Database closed successfully!" << endl;

    return 0;
}
