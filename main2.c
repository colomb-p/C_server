#include	<sys/types.h>
#include	<sys/socket.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<arpa/inet.h>
#include	<unistd.h>

#define		PORT 8083
#define		BUFFER_SIZE 4096

void		my_perror(char *err)
{
  perror(err);
  exit(EXIT_FAILURE);
}

int		main(int argc, char *argv[])
{
  int		s;
  int		res;
  int		new_socket;
  struct sockaddr_in address;
  socklen_t	addr_len;
  char		buffer[BUFFER_SIZE];
  size_t	len;
  
  addr_len = sizeof(address);  
  s = socket(AF_INET, SOCK_STREAM, 0);
  if (s < 0)
    my_perror("Socket error");
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(PORT);
  res = bind(s, (struct sockaddr *)&address, (socklen_t)sizeof(address));
  if (res < 0)
    my_perror("Bind error");
  res = listen(s, 1);
  if (res < 0)
    my_perror("Listen erro");
  new_socket = accept(s, (struct sockaddr *)&address, &addr_len);
  len = read(new_socket, buffer, BUFFER_SIZE);
  printf("%s\n", buffer);
  close(new_socket);
  close(s);
  return (0);
}
