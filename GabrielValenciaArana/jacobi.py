
f1 = lambda x,y,z: (30-y+5*z)/20
f2 = lambda x,y,z: (-18-4*x+z)/20
f3 = lambda x,y,z: (25-1*x+7*y)/20

x0 = 0
y0 = 0
z0 = 0
count = 1

e = float(input('Error tolerable: '))


print('\nCount\tx\ty\tz\n')

condition = True

while condition:
    x1 = f1(x0,y0,z0)
    y1 = f2(x0,y0,z0)
    z1 = f3(x0,y0,z0)
    print('%d\t%0.4f\t%0.4f\t%0.4f\n' %(count, x1,y1,z1))
    e1 = abs(x0-x1);
    e2 = abs(y0-y1);
    e3 = abs(z0-z1);
    
    count += 1
    x0 = x1
    y0 = y1
    z0 = z1
    
    condition = e1>e and e2>e and e3>e

print('\nSolucion: x=%0.3f, y=%0.3f and z = %0.3f\n'% (x1,y1,z1))