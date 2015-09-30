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
	MYSQL *con = mysql_init(NULL);
  
  if (con == NULL)
  {
      fprintf(stderr, "mysql_init() failed\n");
      exit(1);
  }
  
  if (mysql_real_connect(con, "localhost", "user12", "34klq*", 
          "testdb", 0, NULL, 0) == NULL) 
  {
      finish_with_error(con);
  }   
  
  if (mysql_query(con, "DROP TABLE IF EXISTS Writers"))
  {    
      finish_with_error(con);    
  }
  
  char sql[] = "CREATE TABLE Writers(Id INT PRIMARY KEY AUTO_INCREMENT, Name TEXT)";
  
  if (mysql_query(con, sql))
  {    
      finish_with_error(con);    
  }
  
  if (mysql_query(con, "INSERT INTO Writers(Name) VALUES('Leo Tolstoy')"))
  {    
      finish_with_error(con);    
  }
  
  if (mysql_query(con, "INSERT INTO Writers(Name) VALUES('Jack London')"))
  {    
      finish_with_error(con);
  }
  
  if (mysql_query(con, "INSERT INTO Writers(Name) VALUES('Honore de Balzac')"))
  {    
      finish_with_error(con);
  }
  
  int id = mysql_insert_id(con);
  
  printf("The last inserted row id is: %d\n", id);

  mysql_close(con);
  exit(0);
	return 0;
} 
