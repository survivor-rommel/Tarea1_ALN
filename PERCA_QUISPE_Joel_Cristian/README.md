# Métodos numéricos

Como parte del trabajo del curso de Algebra Lineal Numerica - CSUNSA
se implmentó en el lenguaje de programación Python los siguientes
métodos:

1. Metodo de Eliminación Gaussiana con Pivoteo
2. Método de Jacobi

## Sobre el trabajo

El trabajo consta de dos archivos con extensión **.py**. Donde cada archivo
contiene la implementación del método respectivamente. Adicionalmente se testeó
los métodos con un sistema de ecuaciones lineales tipo:

```
El sistema es de la forma:
    
    10x - y + 2z = 6
    -x + 11y - z + 3w = 25
    2x -y + 10z - w = -11
    3y - z + 8w = 15

    Cuya solución es:
    x = 1
    y = 2
    z = -1
    w = 1
```

Cada caso de testeo se encuenta al final de cada archivo.

## Dependencias
Para ejecutar correctamente los archivos con el comando en Windows:
```python metodox.py```

se requiere la instalación de la la libreria `numpy`. Ya que se usó 
para definir estructuras de tipo arreglo y matriz.

### Instlación de numpy
Con el comando:
```
pip install numpy
```
