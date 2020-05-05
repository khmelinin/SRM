import math
def my_func(x):
    return math.sin((1/2)*x)+math.pow((x*1),1/3)

def u_cal(u, n):
    temp = u;
    for i in range(1, n):
        temp = temp * (u - i);
    return temp;

def fact(n):
    f = 1;
    for i in range(2, n + 1):
        f *= i;
    return f;

n = 5;
x = [21, 22, 24, 26, 28];

# y[][] is used for difference table
# with y[][0] used for input
y = [[0 for i in range(n)]
     for j in range(n)];
y[0][0] = my_func(x[0]);
y[1][0] =my_func(x[1]);
y[2][0] = my_func(x[2]);
y[3][0] = my_func(x[3]);
y[4][0] = my_func(x[4]);

for i in range(1, n):
    for j in range(n - i):
        y[j][i] = y[j + 1][i - 1] - y[j][i - 1];

    # Displaying the forward difference table
for i in range(n):
    print(x[i], end="\t")
    for j in range(n - i):
        print(y[i][j], end="\t")
    print("")

# Value to interpolate at
value = 0.5;

# initializing u and sum
sum = y[0][0];
u = (value - x[0]) / (x[1] - x[0])
for i in range(1, n):
    sum = sum + (u_cal(u, i) * y[0][i]) / fact(i)

print("\nValue at", value,
      "is", sum)
print('true value for ',value,my_func(0))