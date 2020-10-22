from math import sqrt
tamanio = int(input("Ingrese el tamanio de la matriz cuadrada: "))
print("Ingrese los datos de la Matriz: ")

def error(Vector1, Vector2):
	subtotal = 0
	for k,p in zip(Vector1, Vector2):
		subtotal += (k-p)**2

	return sqrt(subtotal)


# Se ingresa los datos de la matriz A, linea por linea, donde 
# cada linea es una fila, por ejemplo:
#  3 -1 -1
#  -1 3 1
#  2 1 4

A = []
for k in range(tamanio):
	A.append([])
	fila = input()
	elementos_fila = fila.split()
	for p in range(tamanio):
		A[k].append(float(elementos_fila[p]))


#Se ingresan los datos de b, separados por espacios, por ejemplo:
#   1 3 7

b = []
print("\nIngrese los datos de b:")
fila_ = input()
elementos_fila_ = fila_.split()
for p in range(tamanio):
	b.append(float(elementos_fila_[p]))

#Se ingresa la cantidad de iteraciones
iteraciones = int(input("\nIteraciones: "))

#Se ingresa la tolerancia en decimales
# por ejemplo 0.000001
tolerancia = float(input("\nTolerancia: "))

#Se ingresan los valores iniciales separados por espacios, por ejemplo:
# 0 0 0

print("\nIngrese los valores iniciales de X0: ")
X0 =input()
X0 = X0.split()
X = []
for p in range(tamanio):
	X.append( float (X0[p]) )
	
#Se realiza una copia temporal de los valores iniciales
temp_list = X[:]

for k  in range(iteraciones):
	print("____________________")
	
	for i in range(tamanio):
		temp = 0.0
		#Se realiza una sumatoria
		for j in range(tamanio):
			if j != i:
				temp = temp + A[i][j]*X[j]

		#Se aplica la fórmula
		temp_list[i] = (b[i] - temp) / A[i][i]

	
	#Se imprimen los valores de X0 en la k-ésima iteración
	for k in range(tamanio):
		print(round(temp_list[k], 6))


	if error(temp_list, X) < tolerancia:
		break

	#Se actualizan los datos de X de acuerdo a la k-ésima iteración
	X = temp_list[:]