#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

//Proyecto que genera una Matriz dispersa y puede realizar todas sus TDA
//Finalizado el 27/7/2022

int a[10][10], b[10][10], count=0, row, col, row2, col2, alt[3][60], altb[3][60], altc[3][60];
float altf[3][60];

void menu(){
   printf("**********BIENVENIDO**********\n");
   printf("********MATRIZ DISPERSA******\n\n");
   printf("*OPCIONES:\n\n");
   printf("1. Generar Matriz Dispersa A.\n");
   printf("2. Imprimir Matriz Dispersa A.\n");
   printf("3. Generar Matriz Dispersa B.\n");
   printf("4. Imprimir Matriz Dispersa B.\n");
   printf("5. SUMAR.\n");
   printf("6. MULTIPLICAR.\n");
   printf("7. PRODUCTO POR ESCALAR.\n");
   printf("8. TRANSPONER.\n");
   printf("9. DETERMINANTE.\n");
   printf("10. INVERSA.\n");
   printf("11. SALIR.\n");
}

void generarMatriz(){
   
   int decision=0, i, j;
   bool verif=false;
   
   system("cls");
   
   printf("\n*****...GENERANDO MATRIZ DISPERSA...*****\n\n");
	
   //dimensiones de la matriz
   printf("Ingrese Nro de Filas:\n");
   scanf("%d",&row);
   printf("Ingrese Nro de Columnas:\n");
   scanf("%d",&col);
   
   //llenar la matriz de 0
   for(i = 0; i < row; i++){
      for(j = 0; j < col; j++){
      	a[i][j]=0;	
      }
   }
   count=0;
   //ingresamos datos diferentes de 0;
   do{
   	   noSobreescribir:
       system("cls");
       printf("\n*****...GENERANDO MATRIZ DISPERSA %d x %d...*****\n\n", row, col);
   	   i=0; j=0;
	   printf("\nINDICAR POSICION:\n");
	   
	   //evitamos que coloque numeros de mas
	   count++;
	   if(count == ((row * col)/2)){
	   		printf("**\nNO PUEDES INGRESAR MAS VALORES**\n");
      		printf("**(De lo contrario no seria Matriz Dispersa)**\n");
      		goto sepaso;
      	}
	   //ingresamos posicion-fila
	   do{
	   		verif=false;
	   		printf("\nIngrese Fila: ");
		   	scanf("%d",&i);
		   	if((i>=row) or (i<0))
		   	  printf("Por favor acoplarse al tamano de la matriz\n");
		   	else
		   	  verif=true;
		   	  
	   }while(verif!=true);
	   
	   //ingresamos posicion-columna
	   do{
	   	   verif=false;
		   printf("\nIngrese columna: ");
		   scanf("%d",&j);
		   if((j>=col) or (j<0))
		   	 printf("Por favor acoplarse al tamano de la matriz\n");
	   	   else
	   	   	verif=true;
 
	   }while(verif!=true);
	   
	   //puede existir sobreescritura
	   if (a[i][j]!=0){
	   		printf("\nEsta Posicion ya tiene un Valor Asignado...");
	   		Sleep(1500);
	   		do{
		   		printf("\nDesea SOBREESCRIBIR dicho Valor? 1/si 0/no: ");
		   		scanf("%d",&decision);
		
		   		if((decision<0) or (decision>1)){
		   			printf("Por favor, ingresar 1 o 0\n");
				}
				if (decision==1)
					goto sobreescribir;
				if (decision==0)
					goto noSobreescribir;
	   			
			}while((decision!=0) and (decision!=1));
	   }
	   
	   //Ingresamos Valor
	   sobreescribir:
	   printf("\nIngrese Valor DISTINTO DE 0: ");
	   do{
	   	scanf("%d",&a[i][j]);
	   	if (a[i][j]==0)
	   		printf("Por favor ingresar un dato diferente de 0: ");
	   	else
	   		printf("***Dato Ingresado Correctamente***\n");
	   }while(a[i][j]==0);
	   
	   //decidimos si ingresar otro dato
		do{
	   		printf("\nDesea Ingresar otro Dato? 1/si 0/no: ");
	   		scanf("%d",&decision);
	
	   		if((decision<0) or (decision>1)){
	   			printf("Por favor, ingresar 1 o 0\n");
			}
			
			if (decision==1)
				verif=false;
	   			
		}while((decision!=0) and (decision!=1));
	   
	}while(verif!=true);
	
	sepaso:
	printf("\nPresiona 1 y ENTER para volver al MENU...");
   	scanf("%d", &i);
}

void generarMatrizB(){
   
   int decision=0, i, j;
   bool verif=false;
   
   system("cls");
   
   printf("\n*****...GENERANDO MATRIZ DISPERSA B...*****\n\n");
   
   //dimensiones de la matriz b
   printf("Ingrese Nro de Filas:\n");
   scanf("%d",&row2);
   printf("Ingrese Nro de Columnas:\n");
   scanf("%d",&col2);
   
   //llenar la matriz b de 0
   for(i = 0; i < row2; i++){
      for(j = 0; j < col2; j++){
      	b[i][j]=0;	
      }
   }
   
   //ingresamos datos diferentes de 0
   do{
   	   noSobreescribir:
       system("cls");
       printf("\n*****...GENERANDO MATRIZ DISPERSA B %d x %d...*****\n\n", row2, col2);
   	   i=0; j=0;
	   printf("\nINDICAR POSICION:\n");
	   
	   //evitamos que coloque numeros de mas
	   count++;
	   if(count == ((row2 * col2)/2)){
		   	printf("**\nNO PUEDES INGRESAR MAS VALORES**\n");
	      	printf("**(De lo contrario no seria Matriz Dispersa)**\n");
      		goto sepaso;
      	}
      	
	   //ingresamos posicion-fila
	   do{
	   		verif=false;
		   	printf("\nIngrese Fila: ");
		   	scanf("%d",&i);
		   	if((i>=row2) or (i<0))
		   	  printf("Por favor acoplarse al tamano de la matriz\n");
		   	else
		   	  verif=true;
		   	  
	   }while(verif!=true);
	   
	   //ingresamos posicion-columna
	   do{
	   	   verif=false;
		   printf("\nIngrese columna: ");
		   scanf("%d",&j);
		   if((j>=col2) or (j<0))
		   	 printf("Por favor acoplarse al tamano de la matriz\n");
	   	   else
	   	   	verif=true;
 
	   }while(verif!=true);
	   
	   //puede existir sobreescritura
	   if (b[i][j]!=0){
	   		printf("\nEsta Posicion ya tiene un Valor Asignado...");
	   		Sleep(1500);
	   		do{
		   		printf("\nDesea SOBREESCRIBIR dicho Valor? 1/si 0/no: ");
		   		scanf("%d",&decision);
		
		   		if((decision<0) or (decision>1)){
		   			printf("Por favor, ingresar 1 o 0\n");
				}
				if (decision==1)
					goto sobreescribir;
				if (decision==0)
					goto noSobreescribir;
	   			
			}while((decision!=0) and (decision!=1));
	   }
	   
	   //Ingresamos Valor
	   sobreescribir:
	   printf("\nIngrese Valor DISTINTO DE 0: ");
	   do{
	   	scanf("%d",&b[i][j]);
	   	if (b[i][j]==0)
	   		printf("Por favor ingresar un dato diferente de 0: ");
	   	else
	   		printf("***Dato Ingresado Correctamente***\n");
	   }while(b[i][j]==0);
	   
	   //decidimos si ingresar otro dato
		do{
	   		printf("\nDesea Ingresar otro Dato? 1/si 0/no: ");
	   		scanf("%d",&decision);
	
	   		if((decision<0) or (decision>1)){
	   			printf("Por favor, ingresar 1 o 0\n");
			}
			
			if (decision==1)
				verif=false;
	   			
		}while((decision!=0) and (decision!=1));
	 	   
	}while(verif!=true);
	
   sepaso:
    printf("\nPresiona 1 y ENTER para volver al MENU...");
    scanf("%d", &i);
   
}

void imprimirA(){
   int i,j;
   
   count=0;
	//imprimimos
	printf("\n\n***IMPRIMIENDO MATRIZ DISPERSA A***:\n");
    for(i = 0; i < row; i++){
      for(j = 0; j < col; j++){
      	 if (a[i][j]!=0){
	      	 printf("posicion-fila: %d\n",i);
	      	 alt[0][count]=i;
			 printf("posicion-columna: %d\n",j);
			 alt[1][count]=j;
			 printf("Valor Campo: %d\n",a[i][j]);
			 alt[2][count]=a[i][j];
			 count++;
		 }
      }
      printf("\n");
   }
   
   printf("\n  LEYENDA  \n");
   printf("fila  \n");
   printf("columna  \n");
   printf("valor  \n");
   for(i = 0; i < 3; i++){
      for(j = 0; j < count; j++){
      	 printf("  %d\t",alt[i][j]);
      }
      printf("\n");
   }	
  
   printf("\nPresiona 1 y ENTER para volver al MENU...");
   scanf("%d", &i);
}
		
void imprimirB(){
	int i,j;
   
   count=0;
	//imprimimos de forma alternativa
	printf("\n\n***IMPRIMIENDO MATRIZ DISPERSA B***:\n");
    for(i = 0; i < row2; i++){
      for(j = 0; j < col2; j++){
      	 if (b[i][j]!=0){
	      	 printf("posicion-fila: %d\n",i);
	      	 altb[0][count]=i;
			 printf("posicion-columna: %d\n",j);
			 altb[1][count]=j;
			 printf("Valor Campo: %d\n",b[i][j]);
			 altb[2][count]=b[i][j];
			 count++;
		 }
      }
      printf("\n");
   }
   
   printf("\n  LEYENDA  \n");
   printf("fila  \n");
   printf("columna  \n");
   printf("valor  \n");
   for(i = 0; i < 3; i++){
      for(j = 0; j < count; j++){
      	 printf("  %d\t",altb[i][j]);
      }
      printf("\n");
   }
	
   
   printf("\nPresiona 1 y ENTER para volver al MENU...");
   scanf("%d", &i);
   
}

void suma(){
	
	int i,j,op[10][10];
	
	//comprobamos las propiedades de la suma de matrices   m=n
	if ((row==row2) and (col==col2)){
		//inicializamos el operador
		for(i = 0; i < row; i++){
		    for(j = 0; j < col; j++){
		      	op[i][j]=0;	
		    }
		}
		//sumamos
		for (i = 0; i < row; ++i){
    		for (j = 0; j < col; ++j) {
      			op[i][j] = a[i][j] + b[i][j];
    		}
    	}
    	
    	count=0;
		//imprimimos
		printf("\n\n***IMPRIMIENDO RESULTADO***:\n");
	    for(i = 0; i < row; i++){
	      for(j = 0; j < col; j++){
	      	 if (op[i][j]!=0){
		      	 printf("posicion-fila: %d\n",i);
		      	 altc[0][count]=i;
				 printf("posicion-columna: %d\n",j);
				 altc[1][count]=j;
				 printf("Valor Campo: %d\n",op[i][j]);
				 altc[2][count]=op[i][j];
				 count++;
			 }
	      }
	      printf("\n");
	   }
	   
	   printf("\n  LEYENDA  \n");
	   printf("fila  \n");
	   printf("columna  \n");
	   printf("valor  \n");
	   for(i = 0; i < 3; i++){
	      for(j = 0; j < count; j++){
	      	 printf("  %d\t",altc[i][j]);
	      }
	      printf("\n");
	   }	
	  
    	
	}else{
		printf("\n\nPor favor verifique que las matrices sean del mismo ORDEN N*M");
	}
	
	printf("\nPresiona 1 y ENTER para volver al MENU...");
    scanf("%d", &i);
}

void mult(){
	
	int i,j,k,op[10][10],suma;
	
	//comprobamos las propiedades de la multiplicacion de matrices  ca=fb
	if (col==row2){
		if ((row==row2 and col==col2) or (row!=col and row2!=col2)){
			for(i=0;i<row;i++){
	            for(j=0;j<col2;j++){
	                op[i][j]=0;
	                for(k=0;k<row2;k++){
	                    op[i][j]+=a[i][k]*b[k][j];
	                }
	            }  
	        }
			
	    	count=0;
			//imprimimos
			printf("\n\n***IMPRIMIENDO RESULTADO***:\n");
		    for(i = 0; i < row; i++){
		      for(j = 0; j < col2; j++){
		      	 if (op[i][j]!=0){
			      	 printf("posicion-fila: %d\n",i);
			      	 altc[0][count]=i;
					 printf("posicion-columna: %d\n",j);
					 altc[1][count]=j;
					 printf("Valor Campo: %d\n",op[i][j]);
					 altc[2][count]=op[i][j];
					 count++;
				 }
		      }
		      printf("\n");
		   }
		   
		   printf("\n  LEYENDA  \n");
		   printf("fila  \n");
		   printf("columna  \n");
		   printf("valor  \n");
		   for(i = 0; i < 3; i++){
		      for(j = 0; j < count; j++){
		      	 printf("  %d\t",altc[i][j]);
		      }
		      printf("\n");
		   }	
  		}else{
  			printf("\n\nTiene que ser CUADRADA con CUADRADA o RECTANGULAR con RECTANGULAR");
		  }
	}else{
		printf("\n\nPor favor verifique que COLUMNA A=%d sea igual a FILA B=%d",col,row2);
	}
	
	printf("\nPresiona 1 y ENTER para volver al MENU...");
    scanf("%d", &i);
	
}

void transpose(){
	
	int i,j,op[10][10];
	
		//inicializamos el operador
		for(i = 0; i < row; i++){
		    for(j = 0; j < col; j++){
		      	op[i][j]=0;	
		    }
		}
		
		for (int i = 0; i < row; ++i)
  			for (int j = 0; j < col; ++j) {
    			op[j][i] = a[i][j];
  		}
    	
    	count=0;
		//imprimimos
		printf("\n\n***IMPRIMIENDO RESULTADO***:\n");
	    for(i = 0; i < row; i++){
	      for(j = 0; j < col; j++){
	      	 if (op[i][j]!=0){
		      	 printf("posicion-fila: %d\n",i);
		      	 altc[0][count]=i;
				 printf("posicion-columna: %d\n",j);
				 altc[1][count]=j;
				 printf("Valor Campo: %d\n",op[i][j]);
				 altc[2][count]=op[i][j];
				 count++;
			 }
	      }
	      printf("\n");
	   }
	   
	   printf("\n  LEYENDA  \n");
	   printf("fila  \n");
	   printf("columna  \n");
	   printf("valor  \n");
	   for(i = 0; i < 3; i++){
	      for(j = 0; j < count; j++){
	      	 printf("  %d\t",altc[i][j]);
	      }
	      printf("\n");
	   }	
	
	printf("\nPresiona 1 y ENTER para volver al MENU...");
    scanf("%d", &i);
	
	
}

void getCofactor(int mat[10][10], int temp[10][10], int p,
                 int q, int n) {
    int i = 0, j = 0;
 
    // para cada elemento de la matriz
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            //  copiando en matriz temporal aquellos
            //  que no estan en la fila y columna
            if (r != p && c != q)
            {
                temp[i][j++] = mat[r][c];
 
                // la fila esta llena, se incrementa el index
                // se resetea el index de columna
                if (j == n - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

int determinantOfMatrix(int mat[10][10], int n){
    int D = 0; // Se inicializa el resultado
 
    //  Base case : si la matriz contiene 1 solo elemento
    if (n == 1)
        return mat[0][0];
 
    int temp[10][10]; 
 
    int sign = 1; 
 
    for (int f = 0; f < n; f++)
    {
        getCofactor(mat, temp, 0, f, n);
        D += sign * mat[0][f]
             * determinantOfMatrix(temp, n - 1);
 
        sign = -sign;
    }
 
    return D;
}

void adjoint(int A[10][10],int adj[10][10]){
    
	if (row == 1)
    {
        adj[0][0] = 1;
        return;
    }
 
    int sign = 1, temp[10][10];
 
    for (int i=0; i<row; i++)
    {
        for (int j=0; j<row; j++)
        {
            getCofactor(A, temp, i, j, row);
 
            sign = ((i+j)%2==0)? 1: -1;
 
            adj[j][i] = (sign)*(determinantOfMatrix(temp, row-1));
        }
    }
}

bool inverse(int A[10][10], float inverse[10][10]){
	
    // Se busca el determinante
    int det = determinantOfMatrix(A, row);
    if (det == 0)
    {
        printf("Matriz Singular, no se puede encontrar su Inversa");
        return false;
    }
 
    // Se busca la adjunta
    int adj[10][10];
    adjoint(A, adj);
 
    // Se busca la inversa con la formula "inverse(A) = adj(A)/det(A)"
    for (int i=0; i<row; i++)
        for (int j=0; j<row; j++)
            inverse[i][j] = adj[i][j]/float(det);
 
    return true;
}

void escalar(){
	int i,j,op[10][10];
	
		//inicializamos el operador
		for(i = 0; i < row; i++){
		    for(j = 0; j < col; j++){
		      	op[i][j]=0;	
		    }
		}
		
		int num;
		/*  Determinamos un K */
	    printf("Ingresa el Numero K: \n");
	    scanf("%d", &num);
	    
	    /* Multiplicamos cada campo por K */
	    for(i = 0; i < row; i++){
	        for(j = 0; j < col; j++){
	            op[i][j] = a[i][j]*num;
	        }
	    }
	    
    	count=0;
		//imprimimos
		printf("\n\n***IMPRIMIENDO RESULTADO***:\n");
	    for(i = 0; i < row; i++){
	      for(j = 0; j < col; j++){
	      	 if (op[i][j]!=0){
		      	 printf("posicion-fila: %d\n",i);
		      	 altc[0][count]=i;
				 printf("posicion-columna: %d\n",j);
				 altc[1][count]=j;
				 printf("Valor Campo: %d\n",op[i][j]);
				 altc[2][count]=op[i][j];
				 count++;
			 }
	      }
	      printf("\n");
	   }
	   
	   printf("\n  LEYENDA  \n");
	   printf("fila  \n");
	   printf("columna  \n");
	   printf("valor  \n");
	   for(i = 0; i < 3; i++){
	      for(j = 0; j < count; j++){
	      	 printf("  %d\t",altc[i][j]);
	      }
	      printf("\n");
	   }	
	
	printf("\nPresiona 1 y ENTER para volver al MENU...");
    scanf("%d", &i);
	
}

int main(){
	
   int i,j, opciones;
   float inv[10][10];
   
   do{
   	
	   do{
	   	
	   	system("cls");
	   	
	   	menu();
	   	
	   	printf("\nSELECCIONAR OPCION: ");
	   	
	   	scanf("%d", &opciones);
	   	
	   	if ((opciones<1) or (opciones>11))
	   		printf("Por Favor, Ingresar una opcion Disponible.\n\n");
	   	
	   	Sleep(1500);
	   	
	   }while((opciones<1) or (opciones>11));
	   
	   switch(opciones){
	   	case 1: generarMatriz();
	   			break;
	   	case 2: imprimirA();
	   			break;
	   	case 3: generarMatrizB();
	   			break;		
	   	case 4: imprimirB();
		        break;
	    case 5: suma();
	    		break;
	    case 6: mult();
	    		break;
	    case 7: escalar();
	    		break;
	    case 8: transpose();
	    		break;
	    case 9: if (row==col){
					 printf("El Determinante de la Matriz A es : %d", determinantOfMatrix(a, row));
		    		 printf("\nPresiona 1 y ENTER para volver al MENU..."); scanf("%d", &i);
		    		 break;
		    	 }else{
		    	 	printf("Para poder calcular el determinante la matriz DEBE ser cuadrada");
		    	 	printf("\nPresiona 1 y ENTER para volver al MENU..."); scanf("%d", &i);
		    		break;
				 }
		case 10: if (inverse(a, inv)){
					for (int i=0; i<row; i++){
				        for (int j=0; j<row; j++){
				        	printf("%.2f ",inv[i][j]);
						}
				        printf("\n");
				    }
				    count=0;
					//imprimimos
					printf("\n\n***IMPRIMIENDO MATRIZ INVERSA***:\n");
				    for(i = 0; i < row; i++){
				      for(j = 0; j < row; j++){
				      	 if (inv[i][j]!=0){
					      	 printf("posicion-fila: %d\n",i);
					      	 altf[0][count]=i;
							 printf("posicion-columna: %d\n",j);
							 altf[1][count]=j;
							 printf("Valor Campo: %.2f\n",inv[i][j]);
							 altf[2][count]=inv[i][j];
							 count++;
						 }
				      }
				      printf("\n");
				   }
				   
				   printf("\n  LEYENDA  \n");
				   printf("fila  \n");
				   printf("columna  \n");
				   printf("valor  \n");
				   for(i = 0; i < 3; i++){
				      for(j = 0; j < count; j++){
				      	 printf("  %.2f\t",altf[i][j]);
				      }
				      printf("\n");
				   }	
				  
				}
				printf("\nPresiona 1 y ENTER para volver al MENU..."); scanf("%d", &i);
			    break;
				
		}
    }while(opciones!=11);
    
    if (opciones==11)
    	printf("\n\n*********GRACIAS POR PROBAR MI PROGRAMA*********");
    	Sleep(1000);
    	
   return 0;
    
}