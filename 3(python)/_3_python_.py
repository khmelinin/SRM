
a=[[1,0.206262,0.174954,0.243094,0.152855],[0,3.79899,1.92405,1.297735,0.738803],[0,1.92405,6.21379,1.05906,1.42479],[0,0.297735,1.05906,3.99912,1.04823],[0,0.738803,1.42479,1.04823,5.33313]]
b=[1.186,1.88168,2.6533,4.68447,4.21562]
eps=0.000001

#
c=[0]*5
d=[0]*5
for k in range(5):
    c[k]=[0]*5
for i in range(5):
    for j in range(5):
        if i==j:
            c[i][j]=0
        else:
            c[i][j]=-a[i][j]/a[i][i]
        d[i]=b[i]/a[i][i]
print("Матриця С:",c,"Вектор D:",d,sep="\n")
x0=b[:]
x1=[]

for i in range(5):
    kekw=0
    for j in range(5):
        kekw+=c[i][j]*x0[j]
    x1.append(kekw+d[i])

counter =0
x0=x1[:]
x1=[]

for i in range(5):
    kekw=0
    for j in range(5):
        kekw+=c[i][j]*x0[j]
    x1.append(kekw+d[i])
while True:
    x2=[]

    for i in range(5):
        kekw=0
        kekw2=0
        if i>0:
            for j in range(i-1):
                #if j!=0:
                    kekw+=a[i][j]/a[i][i]*x1[j]
        for j in range(5):
            if j>i:
                kekw2+=a[i][j]/a[i][i]*x0[j]
        x2.append(-kekw-kekw2+b[i]/a[i][i])
    counter+=1
    #print(x1)

    x0=x1[:]
    x1=x2[:]
    stop=False
    for i in range(5):
        if abs(x1[i]-x0[i])>eps:stop = True
    if stop==False:
        break
print("Кількість ітерацій алгоритму:",counter)
print("Вектор розв'язку:",x1,sep="\n")

r=[]
for i in range(5):
        kekw=0
        for j in range(5):
            kekw+=a[i][j]*x1[j]
        r.append(-kekw+b[i])
print("Вектор нев'язки:",r,sep="\n")

