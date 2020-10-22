MAX = 100; 
  
def descompLU(mat, n): 
  
    inferior = [[0 for x in range(n)]  
                for y in range(n)]; 
    superior = [[0 for x in range(n)]  
                for y in range(n)]; 
                  
    for i in range(n): 
  
        ## Matriz triangular superior 
        for k in range(i, n):   
            sum = 0; 
            for j in range(i): 
                sum += (inferior[i][j] * superior[j][k]); 

            superior[i][k] = mat[i][k] - sum; 
  
        ## Matriz triangular superior inferior
        for k in range(i, n): 
            if (i == k): 
                inferior[i][i] = 1;
            else:  
                sum = 0; 
                for j in range(i): 
                    sum += (inferior[k][j] * superior[j][i]);
                    
                inferior[k][i] = int((mat[k][i]-sum)/superior[i][i]);

    ##Imprimimos las matrices
    print("Matriz Triangular inferior\t Matriz Triangular inferior");   
 
    for i in range(n): 
        for j in range(n): 
            print(inferior[i][j], end = "\t");  
        print("", end = "\t");
        
        for j in range(n): 
            print(superior[i][j], end = "\t"); 
        print(""); 

matriz = [[2, -3, 5], 
       [6, -1, 3], 
       [-4, 1, -2]];

##Damos como parametros la matriz y su tamaño
descompLU(matriz, 3); 
  

