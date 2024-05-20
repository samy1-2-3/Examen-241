import multiprocessing

def fibonacci(n):
    if n <= 1:
        return n
    else:
        return fibonacci(n-1) + fibonacci(n-2)

def calPor(inicio, fin, cola):
    resultado = [fibonacci(i) for i in range(inicio, fin)]
    cola.put(resultado)

def main():
    num = 1000
    cantPro = multiprocessing.cpu_count()
    divTer = num // cantPro

    procesos = []
    cola = multiprocessing.Queue()

    for i in range(cantPro):
        ini = i * divTer
        fin = (i+1) * divTer if i < cantPro - 1 else num
        pro = multiprocessing.Process(target=calPor, args=(ini, fin, cola))
        procesos.append(pro)
        pro.start()

    for pro in procesos:
        pro.join()

    resultados = []
    while not cola.empty():
        resultados.extend(cola.get())

    return resultados

if __name__ == "__main__":
    secFib= main()
    print(secFib)
