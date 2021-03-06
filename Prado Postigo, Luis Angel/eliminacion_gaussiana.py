import numpy


def gaussian_elimination(A: numpy.array, b: numpy.array) -> numpy.array:
    n = len(A)
    A, b = numpy.asarray(A, dtype=numpy.float64), numpy.asarray(b, dtype=numpy.float64)
    Ab = numpy.asarray(numpy.c_[A, b], dtype=numpy.float64)

    for k in range(n):
        for i in range(k + 1, n):
            if abs(Ab[i][k]) > abs(Ab[k][k]):
                Ab[[k, i]] = Ab[[i, k]]
            else:
                pass

        for j in range(k + 1, n):
            q = float(Ab[j][k]) / Ab[k][k]
            for m in range(k, n + 1):
                Ab[j][m] -= q * Ab[k][m]

    x = numpy.zeros(n)

    x[n - 1] = float(Ab[n - 1][n]) / Ab[n - 1][n - 1]
    for i in range(n - 1, -1, -1):
        z = 0.0
        for j in range(i + 1, n):
            z = z + float(Ab[i][j]) * x[j]
        x[i] = float(Ab[i][n] - z) / Ab[i][i]
    return x


A = [
    [4, 1, 2, -3, 5],
    [-3, 1, -1, 4, -2],
    [-1, 2, 50, 1, 3],
    [5, 0, 3, -1, 2],
    [1, -2, 3, -4, 5],
]
b = [[-16], [20], [-4], [-10], [3]]

print(gaussian_elimination(A, b))
