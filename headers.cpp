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
	  
	  if (mysql_query(con, "SELECT * FROM Cars LIMIT 3"))
	  {  
		  finish_with_error(con);
	  }
	  
	  MYSQL_RES *result = mysql_store_result(con);

	  if (result == NULL) 
	  {
		  finish_with_error(con);
	  }  

	  int num_fields = mysql_num_fields(result);

	  MYSQL_ROW row;
	  MYSQL_FIELD *field;
	  
	  while ((row = mysql_fetch_row(result))) 
	  { 
		  for(int i = 0; i < num_fields; i++) 
		  { 
		      if (i == 0) 
		      {              
		         while(field = mysql_fetch_field(result)) 
		         {
		            printf("%s ", field->name);
		         }
		         
		         printf("\n");           
		      }
		      
		      printf("%s  ", row[i] ? row[i] : "NULL"); 
		  } 
	  }
	  
	  printf("\n");
	  
	  mysql_free_result(result);
	  mysql_close(con);
	return 0;
} 
