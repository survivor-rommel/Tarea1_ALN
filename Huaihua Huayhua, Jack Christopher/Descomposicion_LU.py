# Se ingresa los datos de la matriz A, linea por linea, donde 
# cada linea es una fila, por ejemplo:
#  3 -1 -1
#  -1 3 1
#  2 1 4

print("Ingrese los datos de la Matriz : ")
Matriz = [[], [], []]
for k in range(3):
	fila = input()
	elementos_fila = fila.split()
	for p in range(3):
		Matriz[k].append(int(elementos_fila[p]))

#Se ingresan los datos de b, separados por espacios, por ejemplo:
#   1 3 7

b = []
print("\nIngrese los datos de b:")
fila_ = input()
elementos_fila_ = fila_.split()
for p in range(3):
	b.append(float(elementos_fila_[p]))

#Paso 1 , Mediante las fórmulas se obtiene la Matriz U
U = Matriz

valor1 = (U[1][0] / U[0][0])  * (-1)
temp_list = [U[0][0] * valor1, U[0][1] * valor1, U[0][2] * valor1]
temp_list = [temp_list[0] + U[1][0], temp_list[1] + U[1][1],temp_list[2] + U[1][2]]
U[1] = temp_list


valor2 = (U[2][0] / U[0][0])  * (-1)
temp_list2 = [U[0][0] * valor2, U[0][1] * valor2, U[0][2] * valor2]
temp_list2 = [temp_list2[0] + U[2][0], temp_list2[1] + U[2][1],temp_list2[2] + U[2][2]]
U[2] = temp_list2



valor3 = (U[2][1] / U[1][1])  * (-1)
temp_list3 = [U[1][0] * valor3, U[1][1] * valor3, U[1][2] * valor3]
temp_list3 = [temp_list3[0] + U[2][0], temp_list3[1] + U[2][1],temp_list3[2] + U[2][2]]
U[2] = temp_list3


#Se imprime la Matriz U
print("\nU:")
for k in range(3):
	print(U[k])

#Paso 2, Mediante las fórmulas se obtiene la Matriz L
L = [ [1,0,0],
	  [valor1*-1,1,0],
	  [valor2*-1 ,valor3*-1,1] ]

#Se imprime la Matriz L
print("\nL:")
for k in range(3):
	print(L[k])

#Se obtiene la solución a la ecuación: Ly = b
Y = [0,0,0]
Y[0] = b[0]
Y[1] = b[1] - L[1][0]*Y[0]
Y[2] = b[2] - L[2][0]*Y[0] - L[2][1]*Y[1] 

#Una vez que ya se tiene y
#Se obtiene la solución a la ecuación: Ux = y
X = [0,0,0]
X[2] = round(Y[2]/ U[2][2], 5)
X[1] = round((Y[1] - U[1][2]*X[2])/U[1][1], 5)
X[0] = round((Y[0] - U[0][2]*X[2] - U[0][1]*X[1])/U[0][0], 5)

#Se imprimen los valores de Y, y la solución: X
print()
print("Y: ", Y)
print("X: ", X)