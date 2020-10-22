import numpy as np

m=int(input("Introduce el valor de m: "))
n=int(input("Introduce el valor de n: "))
matriz=np.zeros([m,n]) 
vector = np.zeros((n))
x = np.zeros((m))
u=np.zeros([m,n])
l=np.zeros([m,n])

print('Introduce los elementos de la matriz:')
for r in range(0,m):
    for c in range(0,n):
        matriz[r,c]=(input("Elemento a["+str(r+1)+","+str(c+1)+"] = "))
        matriz[r,c]=(float(matriz[r,c]))
        u[r,c]=matriz[r,c]
    vector[(r)]=(input('b['+str(r+1)+']: '))

for k in range(0,m):
    for r in range(0,m):
        if(k==r):
            l[k,r]=1
        if(k<r):
            factor=(matriz[r,k]/matriz[k,k])
            vector[r] = vector[r] - (factor * vector[k])
            l[r,k]=factor
            for c in range(0,n):
                matriz[r,c]=matriz[r,c]-(factor*matriz[k,c])
                u[r,c]=matriz[r,c]
print("Mostrando las matrices LU...")
print("Matriz L:")
print(l)
print("Matriz U:")
print(u)

#Sustitucion hacia atr?s
x[m-1]=vector[m-1]/matriz[m-1,m-1]
print (x[m-1])

for r in range(m-2,-1,-1):
    suma=0
    for c in range(0,n):
        suma=suma+matriz[r,c]*x[c]
    x[r]=(vector[r]-suma)/matriz[r,r]

print ('Resultados: ')
print(x)

#Comprobacion
print ("Comprobando...")
matrizr=np.zeros([m,n])
for r in range (0,m):
    for c in range(0,n):
        for k in range(0,m):
            matrizr[r,c] += (l[r,k]*u[k,c])
print(matrizr)
a=np.dot(l,u)
print(a)




