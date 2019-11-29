
Ir al contenido
Uso de Gmail con lectores de pantalla
2 de 58
Fwd: Contar lineas pares software
Recibidos
	x
Juan José Quintero Hípola <juanjosequinterohipola@gmail.com>
	
Archivos adjuntos18 nov. 2019 14:59 (hace 11 días)
	
para mí
   
Traducir mensaje
Desactivar para: inglés


---------- Forwarded message ---------
De: Juan José Quintero Hípola <juanjosequinterohipola@gmail.com>
Date: mar., 4 dic. 2018 a las 11:40
Subject: Contar lineas pares software
To: Carlos Barroso <barrosocarlos98@gmail.com>




Zona de los archivos adjuntos
	
QUE TE PARECE?
GRACIAS!
LISTO!
	
	

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>


int *crear_hijos(int num_hijos, int *hijos){
	int i;
	for (i=0; i<num_hijos; i++){
		hijos[i]= fork();
		if(hijos[i]==-1){
			printf("Error fork");
		}else if (hijos[i]==0){
			break;
		}
	}return hijos;
}
void comprobar_pipe(int fd){
	if (fd == -1){
		perror("Error al crear el pipe");	
	} 
} 

int main(int argc, char *argv[])
{
	//int pid;
	int fd_origen;
	int fd_destino;
	int contador = 1;
	char buffer [2];
	int num_bytes;
	int pipe_1[2];
	int salida_exec;
	int status;
	int num_hijos = 1;
	pid_t hijos[num_hijos];
	
	if(argc != 3){
	perror("Usa el nombre del programa, fichero origen y fichero destino");
	}else{
		comprobar_pipe(pipe(pipe_1));
		crear_hijos(num_hijos,hijos);
		if (hijos[0]==0){
				fd_destino = open(argv[2],O_CREAT|O_WRONLY); 
				if(fd_destino<0){
					perror("Error al abrir el fichero origen");
				}
				dup2(fd_destino,1);
				close(pipe_1[1]);
				dup2(pipe_1[0],0);
				close(pipe_1[0]);
				salida_exec = execlp("wc","wc",NULL);
				if(salida_exec == 1){
					perror("Error exec");
				}
		}
		else{
			close(pipe_1[0]);
			fd_origen = open(argv[1],O_RDWR);
			if(fd_origen<0){
				perror("Error al abrir el fichero origen");
			}
			do{
				if (contador % 2 == 0){
					do{
						num_bytes = read(fd_origen, buffer, 1);
						write(pipe_1[1],buffer,num_bytes);
					}while(buffer[0] != '\n');
					contador++; 
				}else{
					do{
						num_bytes = read(fd_origen, buffer, 1);
					}while(buffer[0] != '\n');
					printf("linea impar \n");
					contador++; 
				}
			}while(num_bytes != 0);
			close(pipe_1[1]);			
		}
		wait(&status);	
	}
}

contar_lineas.c
Mostrando contar_lineas.c.
