#METODO DE JACOBI
#Alumna: Evelyn Lizbeth Cusi Hancco
from math import *
def mostrarMatriz(M,n):
    print("\nMatriz A")
    for i in range(n):
        for j in range(n):
            print(M[i][j],end="  ")
        print()

def ingresarMatriz(M,n):
    for i in range(n):
        for j in range(n):
            M[i][j]=float(input("Ingrese valores para A ["+str(i+1)+","+str(j+1)+"] : "))
        
def ingresarB(b,n):
    for i in range(n):
        for j in range(1):
            b[i][j]=float(input("Ingrese valor para b : "))

def ingresarX(x,n):
    for i in range(n):
        for j in range(1):
            x[i][j]=float(input("Ingrese valor para x(0) : "))

def mostrarB(b,n):
    for i in range(n):
        for j in range(1):
            print(b[i][j])

def diagonalD(M,n):
    MD=[]
    for i in range(n):
        MD.append([0]*n)

    for i in range(n):
        for j in range(n):
            if i==j:
                MD[i][i]=M[i][i]
    return MD

def inferiorD(M,n):
    MDI=[]
    for i in range(n):
        MDI.append([0]*n)

    for i in range(n):
        for j in range(i):
            MDI[i][j]=M[i][j]*(-1)
    return MDI

def superiorD(M,n):
    MDS=[]
    for i in range(n):
        MDS.append([0]*n)

    for i in range(n):
        for j in range(i+1,n):
            MDS[i][j]=M[i][j]*(-1)
    return MDS

def inversaD(D,n):
    DInv=[]
    for i in range(n):
        DInv.append([0]*n)

    for i in range(n):
        for j in range(n):
            if i==j:
                DInv[i][j]=1/D[i][j]
    return DInv
            

def multipDinv_b(ID,b,n):
    multDIxB=[]
    for i in range( n):
        multDIxB.append([0]*1)

    for i in range(n):

                multDIxB[i][0]=round(ID[i][i]*b[i][0],4)
    return multDIxB

def Dinv_L_U(ID,L,U,n):
    multDIxLU=[]
    for i in range( n):
        multDIxLU.append([0]*n)

    for i in range(n):
        for j in range(n):
            multDIxLU[i][j]=ID[i][i]*(L[i][j]+U[i][j])
    return multDIxLU



def convergente(M,n):
    matPosit=[]
    for i in range(n):
        matPosit.append([0]*n)


    for i in range(n):
        for j in range(n):
            if M[i][j]<0:
                matPosit[i][j]=M[i][j]*(-1)
            else:
                matPosit[i][j]=M[i][j]
    return matPosit

def diagDom(PoS,n):
    d=0
    for i in range(n):
        s=0
        for j in range(n):
            s=s+PoS[i][j]
        if 2*PoS[i][i]-s>=0:
            d=d+1
    if d==n:
        return True


def iterando(ID_L_U,IDxB,x,n,b):
    multEspecial=[]
    for i in range(n):
        multEspecial.append([0]*1)

    sumNew=[]
    for i in range(n):
        sumNew.append([0]*1)
    
    comprob=[]
    for i in range(n):
        comprob.append([0]*1)

    error=[]


    cambio=[]
    for i in range(n):
        cambio.append([0]*1)

    Seguimiento=[]
    for i in range(n):
        Seguimiento.append([0]*1)

    

    a=0
    while a<iteraciones:
        a=a+1
        for i in range(n):
            for j in range(1):
                for k in range(n):
                    multEspecial[i][j]+=(ID_L_U[i][k]*x[k][j])

        for i in range(n):
            for j in range(1):
                sumNew[i][j]=multEspecial[i][j]+IDxB[i][j]

        #restando por el anterior
        for i in range(n):
            for j in range(1):
                cambio[i][j]=x[i][j]
                Seguimiento[i][j]=sumNew[i][j]-cambio[i][j]

        #absoluto de 3 del restando por el anterior
        mayorcito=abs(Seguimiento[0][0])
        for i in range(n):
            for j in range(1):
                if abs(Seguimiento[i][j])>mayorcito:
                    mayorcito=abs(Seguimiento[i][j])



        #absoluto maximo de las iteraciones
        may=abs(sumNew[0][0])
        for i in range(n):
            for j in range(1):
                if abs(sumNew[i][j])>may:
                    may=abs(sumNew[i][j])



        #division final
        divF=mayorcito/may

        print()
        if divF<=tol:
            print("LA RESPUESTA ES: ",sumNew)
            break
            print()
            

        for i in range(n):
            for j in range(1):
                x[i][j]=sumNew[i][j]

        
                
        
        print ("La iteracion ",a,"es:   ",x)


        reiniciando=[]
        for i in range(n):
            reiniciando.append([0]*1)
            multEspecial[i][j]=reiniciando[i][j]
            
        

n=int(input("Ingresar el orden de la matriz: "))
M=[]
for i in range(n):
    M.append([0]*n)

b=[]
for i in range(n):
    b.append([0]*1)

x=[]
for i in range(n):
    x.append([0]*1)

D=[]
for i in range(n):
    D.append([0]*n)

L=[]
for i in range(n):
    L.append([0]*n)

U=[]
for i in range(n):
    U.append([0]*n)

ID=[]
for i in range(n):
    ID.append([0]*n)

IDxB=[]
for i in range(n):
    IDxB.append([0]*n)

ID_L_U=[]
for i in range(n):
    ID_L_U.append([0]*n)



PoS=[]
for i in range(n):
    PoS.append([0]*n)



ingresarMatriz(M,n)
mostrarMatriz(M,n)
ingresarB(b,n)
mostrarB(b,n)
diagonalD(M,n)
ingresarX(x,n)
print("Los valores de x(0) ")
mostrarB(x,n)

iteraciones=int(input("Ingrese numero de iteraciones : "))
tol=float(input("Ingrese tolerancia en decimales: "))

#Matriz diagonal
D=diagonalD(M,n)

#Matriz diagonal inferior por -1
L=inferiorD(M,n)

#Matriz diagonal superior por -1
U=superiorD(M,n)

#Matriz Inversa de la diagonal
ID=inversaD(D,n)

#Matriz Inversa de la diagonal POR b
IDxB=multipDinv_b(ID,b,n)

#Matriz ID *(L+U)
ID_L_U=Dinv_L_U(ID,L,U,n)

#Matriz positivizada
PoS=convergente(M,n)


if diagDom(PoS,n):
    print("Si tiene diagonal dominante")
else:
    print("No tiene diagonal dominante")


print()
print(">>>>>>>>>>>ITERACIONES<<<<<<<<<<<<")
iterando(ID_L_U,IDxB,x,n,b)
print()
print("**Nota: Las iteraciones acaban cuanto se cumpla la tolerancia")


