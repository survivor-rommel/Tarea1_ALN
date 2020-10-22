# Primero ordenamos el sistema de forma diagonalmente dominante

##(3x-y-z)  = 1
##(2x+y+4z) = 7
##(-x+3y+z) = 3

##(3x-y-z)  = 1
##(-x+3y+z) = 3
##(2x+y+4z) = 7

## Y ordenamos las ecuaciones de la sgte manera

f1 = lambda x,y,z: (1+y+z)/3
f2 = lambda x,y,z: (3+x-z)/3
f3 = lambda x,y,z: (7-2*x-y)/4

x0 = 0
y0 = 0
z0 = 0
contador = 1

##Dependera de nosotros darle un margen muy pequeño
##o grande para tener muchas o pocas iteraciones
margen = float(input('Ingresa margen de error: '))

print('\nCount\tx\ty\tz\n')

condicionMargen = True
## Se empieza a iterar
while condicionMargen:
    x1 = f1(x0,y0,z0)
    y1 = f2(x0,y0,z0)
    z1 = f3(x0,y0,z0)
    print('%d\t%0.4f\t%0.4f\t%0.4f\n' %(contador, x1,y1,z1))
    margen1 = abs(x0-x1);
    margen2 = abs(y0-y1);
    margen3 = abs(z0-z1);
    
    contador += 1
    x0 = x1
    y0 = y1
    z0 = z1
    
    condicionMargen = margen1>margen and margen2>margen and margen3>margen

print('x=%0.3f, y=%0.3f and z = %0.3f\n'% (x1,y1,z1))
