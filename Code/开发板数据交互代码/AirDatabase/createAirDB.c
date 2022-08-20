#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sqlite3.h>

static int callback(void *NotUsed,int argc, char **argv, char **azColName)
{
	int i;
	for(i = 0;i<argc;i++)
	{
		printf("%s = %s\n",azColName[i],argv[i]?argv[i]:"NULL");
	}
	printf("\n");
	return 0;
}

int main(int argc, char *argv[])
{
	char DBfilename[256] = {0};
	char temp[100];
	sqlite3 *db;
	char *zErrMsg = 0;
	char *sql;
	int ret;

	strcpy(DBfilename, "AirData.db");
	
	if(argc < 2)
	{
		printf("Instruction:\n\n"\
		"Run with argument '-o' to create database and table\n"\
		",if the table is exist, it will do nothing\n\n"\
		"Run with argument '-d' to create database and table\n"\
		",if the table is exist, it will drop the table first "\
		"(Reset the table)\n\n");
		exit(0);
	}
	else if(argc > 2)
	{
		printf("wrong argument\n");
		exit(0);
	}
	else if(strcmp(argv[1],"-d") == 0)
	{
		printf("Are you sure?"\
		" You will lost all the data in the table (y/n)");
		scanf("%s", temp);
		
		while(strcmp(temp,"y")!=0 && strcmp(temp,"n")!=0)
		{
			printf("please input y or n:");
			scanf("%s", temp);
		}
		
		if(strcmp(temp, "y") == 0)
		{
			
		}
		else if(strcmp(temp, "n") == 0)
		{
			exit(0);
		}
	}
	else if(strcmp(argv[1],"-o") == 0)
	{
		
	}

	ret = sqlite3_open(DBfilename, &db);

	if(ret)
	{
		printf("open error, %s\n",sqlite3_errmsg(db));
		exit(0);
	}
	else
	{
		printf("open database successfully\n");
	}

	//delete table
	if(strcmp(argv[1],"-d") == 0)
	{
		sql = "drop table Data;";
		ret = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
		if(ret != SQLITE_OK)
		{
			printf("SQL:%s\n",zErrMsg);
			sqlite3_free(zErrMsg);
		}
		else
		{
			printf("droped the table Data\n");
		}
	}

	//create sql statement
	sql = "CREATE TABLE Data(\n"\
	"time INTEGER PRIMARY KEY NOT NULL,\n"\
	"temperature REAL NOT NULL,\n"\
	"humidity REAL NOT NULL,\n"\
	"ammonia REAL NOT NULL);";
	
	//execute sql statement
	ret = sqlite3_exec(db,sql,callback,0,&zErrMsg);
	if(ret != SQLITE_OK)
	{
		printf("SQL:%s\n",zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else
	{
		printf("table create success\n");
	}

	sqlite3_close(db);
	
	return 0;
}

