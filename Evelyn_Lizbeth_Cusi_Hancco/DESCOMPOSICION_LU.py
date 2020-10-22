#DESCOMPOSICION LU
#Alumna: Evelyn Lizbeth Cusi Hancco
def mostrarMatriz(M,n):

    for i in range(n):
        for j in range(n):
            print(M[i][j],end="      ")
        print()

def ingresarMatriz(M,n,U):
    for i in range(n):
        for j in range(n):
            M[i][j]=int(input("Ingrese valor para A["+str(i+1)+","+str(j+1)+"] : "))
            U[i][j]=M[i][j]
            
def matrizL(M,n,U):
    L=[]
    for i in range(n):
        L.append([0]*n)

    for i in range(n):
        for j in range(n):
            if (i==j):
                L[i][j]=1

            if (i<j):
                factor=(M[j][i]/M[i][i])
                L[j][i]=factor
                for k in range(n):
                    M[j][k]=M[j][k]-(factor*M[i][k])
                    U[j][k]=M[j][k]
    
    return L

def matrizU(M,n,ML,U):

    
    
    for i in range(n):
        for j in range(n):
            if (i==j):
                ML[i][j]=1

            if (i<j):
                factor=(M[j][i]/M[i][i])
                ML[j][i]=factor
                for k in range(n):
                    M[j][k]=M[j][k]-(factor*M[i][k])
                    U[j][k]=M[j][k]
    return U


n=int(input("Ingresar el orden de la matriz: "))
M=[]
for i in range(n):
    M.append([0]*n)

U=[]
for i in range(n):
    U.append([0]*n)

ML=[]
for i in range(n):
    ML.append([0]*n)

MU=[]
for i in range(n):
    MU.append([0]*n)



ingresarMatriz(M,n,U)
print("\nLa matriz ingresada es  ")
mostrarMatriz(M,n)


print("\nMostrando descomposicion LU")
ML=matrizL(M,n,U)
print("\nMostrando Matriz L")
mostrarMatriz(ML,n)

MU=matrizU(M,n,ML,U)
print("\nMostrando Matriz U")
mostrarMatriz(MU,n)