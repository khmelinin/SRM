################################## trapez ################################
import scipy.optimize as opt
import scipy.integrate as integrate
from sympy import *
import math

aa=0.5
bb=1.4


def tintegrate(f, a, b, n):
    g = 0
    
    h = (b - a) / float(n)
    
    for i in range(0, n):
        k = 0.5 * h * (f(a + i * h) + f(a + (i + 1) * h))
        g = g + k

    return g


def f(x):
    
    return math.log((math.pow(x,2)+1),10)/x


max_x =opt.fminbound(lambda x: -f(x), aa, bb)


################################## gauss ################################
dict_c = {
    1: [2],
    2: [1, 1],
    3: [0.555555, 0.888889, 0.555555],
    4: [0.347855, 0.652145, 0.652145, 0.347855],
    5: [0.236927, 0.478629, 0.568889, 0.478629, 0.236927],
    6: [0.171324, 0.360761, 0.467914, 0.467914, 0.360761, 0.171324],
    7: [0.129485, 0.279705, 0.381830, 0.417960, 0.381830, 0.279705, 0.129485],
    8: [0.101228, 0.222381, 0.313707, 0.362684, 0.362684, 0.313707, 0.222381, 0.101228]
}
dict_x = {
    1: [0.5],
    2: [-0.577350, 0.577350],
    3: [-0.774597, 0, 0.774597],
    4: [-0.861136, -0.339981, 0.339981, 0.861136],
    5: [-0.906180, -0.538470, 0, 0.538470, 0.906180],
    6: [-0.932470, -0.661210, -0.238620, 0.238620, 0.661210, 0.932470],
    7: [-0.949108, -0.741531, -0.405845, 0, 0.405845, 0.741531, 0.949108],
    8: [-0.960290, -0.796666, -0.525532, -0.183434, 0.183434, 0.525532, 0.796666, 0.960290]
}
def integrate(m, func=lambda x: 0.45*(math.log10(math.pow((0.45 * x + 0.95), 2) + 1) / float(0.45 * x + 0.95))):
    result = 0.0
    for i in range(1, m + 1):
        result += dict_c[m][i - 1] * func(dict_x[m][i - 1])
    return result

def find_m(m1, m2, eps):
    while not (abs(integrate(m1) - integrate(m2) )<= eps):
        m2 += 1

    return m2
#######################################################################

trapez_integral = tintegrate(f, aa, bb, 29)
print('Trapez = ', trapez_integral)
m=find_m(8,1,0.0001)
print('m = ',m)
print('max = ',max_x)
gauss_integral=integrate(m)
print('Gauss = ',gauss_integral)
