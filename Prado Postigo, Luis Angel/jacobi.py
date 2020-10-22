import numpy


def jacobi(
    A: numpy.array,
    b: numpy.array,
    x_0: numpy.array,
    epsilon: float,
    max_iterations: int,
) -> numpy.array:
    D = numpy.diag(numpy.diag(A))
    LU = A - D
    x_k = x_0
    for i in range(max_iterations):
        D_inverse = numpy.diag(1 / numpy.diag(D))
        x_k_1 = numpy.dot(D_inverse, b - numpy.dot(LU, x_k))
        if numpy.linalg.norm(x_k_1 - x_k) < epsilon:
            return x_k_1
        x_k = x_k_1
    return x_k


A = numpy.array([[2, 1, 1], [3, 20, 1], [2, 1, 2]])

b = numpy.array([10, 1, 1])

x_0 = numpy.zeros(len(b))
x = jacobi(A, b, x_0, 1e-10, 1000)

print(x)
