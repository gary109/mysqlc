#include <mysql.h>
#include <stdio.h>
#include <stdlib.h>

void finish_with_error(MYSQL *con)
{
  fprintf(stderr, "%s\n", mysql_error(con));
  mysql_close(con);
  exit(1);        
}

int main(void) 
{
	MYSQL *con;
	MYSQL_RES *res;
	MYSQL_ROW row;

	char server[] = "localhost";
	char user[] = "user12";
	char password[] = "34klq*"; 
	char database[] = "testdb";

	con = mysql_init(NULL);

 	if (con == NULL) 
	{
      	fprintf(stderr, "%s\n", mysql_error(con));
		exit(1);
  	}

	/* Connect to database */
	if (!mysql_real_connect(con, server,user, password, database, 0, NULL, 0)) 
		finish_with_error(con);
      	
	if (mysql_query(con, "DROP TABLE IF EXISTS Cars")) {
		finish_with_error(con);
	}
	  
	if (mysql_query(con, "CREATE TABLE Cars(Id INT, Name TEXT, Price INT)")) {      
	    finish_with_error(con);
	}
	  
	if (mysql_query(con, "INSERT INTO Cars VALUES(1,'Audi',52642)")) {
		finish_with_error(con);
	}
	  
	if (mysql_query(con, "INSERT INTO Cars VALUES(2,'Mercedes',57127)")) {
	    finish_with_error(con);
	}
	  
	if (mysql_query(con, "INSERT INTO Cars VALUES(3,'Skoda',9000)")) {
	    finish_with_error(con);
	}
	  
	if (mysql_query(con, "INSERT INTO Cars VALUES(4,'Volvo',29000)")) {
	    finish_with_error(con);
	}
	  
	if (mysql_query(con, "INSERT INTO Cars VALUES(5,'Bentley',350000)")) {
	    finish_with_error(con);
	}
	  
	if (mysql_query(con, "INSERT INTO Cars VALUES(6,'Citroen',21000)")) {
	    finish_with_error(con);
	}
	  
	if (mysql_query(con, "INSERT INTO Cars VALUES(7,'Hummer',41400)")) {
	    finish_with_error(con);
	}
	  
	if (mysql_query(con, "INSERT INTO Cars VALUES(8,'Volkswagen',21600)")) {
	    finish_with_error(con);
	}

	mysql_close(con);
	return 0;
} 
