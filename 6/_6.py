import math

func_glob = lambda x: x**4 * -2*x ** 3 - 9 * x ** 2 - 3*x - 1
func_glob1 = lambda x: 4 * x ** 3 - 18 * x
func_glob2 = lambda x: 12*x**2-18
#func_glob3 = lambda x: (1612/147) * x +(26/49)

a0, b0 = -2.0, -1.0
c0, d0 = 4.0, 5.0
#e0, g0 = 2.0, 3.0
eps = 0.000001


def half_divide_method(a, b, f, it1_global=0):
    x = (a + b) / 2
    while math.fabs(f(x+eps)) >= eps and math.fabs(b - a) > eps:
        x = (a + b) / 2
        a, b = (a, x) if f(a) * f(x) < 0 else (x, b)
        it1_global += 1

    print("Half_divide_method called.Number of iterations:", it1_global)
    return (a + b) / 2


# --------------------------------------- not used
def method_chord(a, b, f, it2_global=0):
    while math.fabs(b - a) > eps and math.fabs(f(a)) > eps:
        a = a - f(a) * (b - a) / (f(b) - f(a))
        b = a - f(a) * (b - a) / ((f(b) - f(a)))
    it2_global += 1
    print(it2_global)
    return a


# ---------------------
def method_h(func, s, e, it2_global=0):
    # k = 0
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

    print("Method_coord called.Number of iterations:", it2_global)
    return c


# условие на сходимость f(x)*f''(x)>0
def method_n(func, a, b, it3_global=0):
    x0=0
    if func(a) * func_glob2(a) > 0:
        x0 = a
    else:
        x0 = b
    xn = x0
    xn1 = xn - func(xn) / func_glob1(xn)
    it3_global+=1
    while  abs(xn1 - xn)>eps and abs(func(xn1))>eps:
     it3_global+=1
     xn = xn1
     xn1 = xn - func(xn) / func_glob1(xn)
    print("Newton's method called.Number of iterations:",it3_global)
    return xn1


def bisection(f,a,b,N):
    
    if f(a)*f(b) >= 0:
        print("Bisection method fails.")
        return None
    a_n = a
    b_n = b
    for n in range(1,N+1):
        m_n = (a_n + b_n)/2
        f_m_n = f(m_n)
        if f(a_n)*f_m_n < 0:
            a_n = a_n
            b_n = m_n
        elif f(b_n)*f_m_n < 0:
            a_n = m_n
            b_n = b_n
        elif f_m_n == 0:
            print("Found exact solution.")
            return m_n
        else:
            print("Bisection method fails.")
            return None
    return (a_n + b_n)/2

counter1 = 0
counter2 = 0
counter3 = 0

x1 = half_divide_method(a0, b0, func_glob, counter1)
x2 = half_divide_method(c0, d0, func_glob)
#x3 = half_divide_method(e0, g0, func_glob)

_x1 = method_h(func_glob, a0, b0, counter2)
_x2 = method_h(func_glob, c0, d0)
#_x3 = method_h(func_glob, e0, g0)

x_1 = method_n(func_glob, a0, b0)
x_2 = method_n(func_glob, c0, d0)
#x_3 = method_n(func_glob, e0, g0)

print("Using half_divide_method:")
print("x1:", x1)
print("x2:", x2)
#print("x3:", x3)

print("Using method_cord:")
print("x1:", _x1)
print("x2:", _x2)
#print("x3:", _x3)

print("Using Newton's method:")
print("x1:",x_1)
print("x2:",x_2)
#print("x3:",x_3)

