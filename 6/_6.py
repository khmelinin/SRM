import math

func_glob = lambda x: (x**4) -2*(x**3) - 9 * (x ** 2) - 3*x - 1
func_glob1 = lambda x: 4 * (x**3)-6*(x**2) - 18 * x-3
func_glob2 = lambda x: 12*(x**2)-12*x-18


a0, b0 = -2.0, -1.0
c0, d0 = 4.0, 5.0
eps = 0.000001


def half_divide_method(a, b, f, it1_global=0):
    x = (a + b) / 2
    while math.fabs(f(x+eps)) >= eps and math.fabs(b - a) > eps:
        x = (a + b) / 2
        a, b = (a, x) if f(a) * f(x) < 0 else (x, b)
        it1_global += 1

    print("HalfDivide method iterations:", it1_global)
    return (a + b) / 2


# ----------------------------------------------------------------------------------
def method_h(func, s, e, it2_global=0):
    while True:
        it2_global += 1
        fa = func(s)
        fb = func(e)
        c = s - fa * (e - s) / (fb - fa)
        fc = func(c)
        if fa * fc < 0:
            e = c
        else:
            e = s
            s = c
        if (math.fabs(e - s) <= eps and fc <= eps):
            break

    print("MethodCoord iterations:", it2_global)
    return c


#------------------------------------------------------------------------------------
def newton(a,b,f,f1,counter=0):
    x_prev=(a+b)/2
    x=x_prev-f(x_prev)/f1(x_prev)
    while math.fabs(x-x_prev) >=  eps or math.fabs(f(x)) >= eps:
        x=x_prev-f(x_prev)/f1(x_prev)
        x_prev=x
        counter+=1
    print("Newton method iterations:", counter)
    return x

counter1 = 0
counter2 = 0

x1 = half_divide_method(a0, b0, func_glob, counter1)
x2 = half_divide_method(c0, d0, func_glob)


_x1 = method_h(func_glob, a0, b0, counter2)
_x2 = method_h(func_glob, c0, d0)

x_1 = newton(a0,b0,func_glob, func_glob1)
x_2 = newton(c0,d0,func_glob, func_glob1)

print("HalfDivide method:")
print("x1:", x1)
print("x2:", x2)

print("MethodCord:")
print("_x1:", _x1)
print("_x2:", _x2)

print("Newton's method:")
print("x_1:",x_1)
print("x_2:",x_2)