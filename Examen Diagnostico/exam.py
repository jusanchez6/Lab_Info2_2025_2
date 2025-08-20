# primer punto 

def divisores (n):
    
    div = []
    
    for divisores in range(1, n):
        if (n % divisores == 0):
            div.append(divisores)

    return div

# Segundo punto 

def gen_fibonacci (n):
    
    fib = []
    dig = 0
    prev = 0
    for i in range(0, n):
        if i != n:
            
            fib.append(prev + dig)
            prev = dig
            dig += 1

    
    return fib

#tercer punto

def cal_promedio():
    # Abrir el archivo
    fichero = open('ventas.txt')

    prom_enero = []
    prom_febrero = []
    prom_marzo = []
    prom_abril = []
    prom_mayo = []


    sum_1 = 0
    sum_2 = 0
    sum_3 = 0
    sum_4 = 0
    sum_5 = 0

    lineas = fichero.readlines()

    for linea in lineas:
        
        if linea.count("Enero") != 0:
            vals = linea.split(",")
            prom_enero.append(vals[1].rstrip())
            
        elif linea.count("Febrero") != 0:
            vals = linea.split(",")
            prom_febrero.append(vals[1].rstrip())

        elif linea.count("Marzo") != 0:
            vals = linea.split(",")
            prom_marzo.append(vals[1].rstrip())
        
        elif linea.count("Abril") != 0:
            vals = linea.split(",")
            prom_abril.append(vals[1].rstrip())

        elif linea.count("Mayo") != 0:
            vals = linea.split(",")
            prom_mayo.append(vals[1].rstrip())

    for vals in range(0, len(prom_enero)):
        sum_1 += float(prom_enero[vals])

    for vals in range(0, len(prom_febrero)):
        sum_2 += float(prom_febrero[vals])

    for vals in range(0, len(prom_marzo)):
        sum_3 += float(prom_marzo[vals])

    for vals in range(0, len(prom_abril)):
        sum_4 += float(prom_abril[vals])

    for vals in range(0, len(prom_mayo)):
        sum_5 += float(prom_mayo[vals])


    # Escribir la lista que se quiere guardar
    lista_1 = ["Enero", str(sum_1/len(prom_enero))]
    lista_2 = ["Febrero", str(sum_1/len(prom_febrero))]
    lista_3 = ["Marzo", str(sum_1/len(prom_marzo))]
    lista_4 = ["Abril", str(sum_1/len(prom_abril))]
    lista_5 = ["Mayo", str(sum_1/len(prom_mayo))]

    print(lista_1)


    f = open("Promedios.txt", 'w')
    for linea in lista_1:
        f.write(linea)
        f.write(" : ")
    f.write("\n")

    for linea in lista_2:
        f.write(linea)
        f.write(" : ")
    f.write("\n")

    for linea in lista_3:
        f.write(linea)
        f.write(" : ")

    f.write("\n")

    for linea in lista_4:
        f.write(linea)
        f.write(" : ")

    f.write("\n")

    for linea in lista_5:
        f.write(linea)
        f.write(" : ")

    f.write("\n")

    

cal_promedio()