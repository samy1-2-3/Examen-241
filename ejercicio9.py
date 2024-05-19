import multiprocessing

def generaR(ini, a, cont, res):
    res.extend([ini + a * i for i in range(cont)])

def main():
    tserie = int(input("Tamaño de la serie: "))
    nproces = int(input("Ingrese el número de procesadores a utilizar: "))

    a = 2 
    terpro = tserie // nproces
    terext= tserie % nproces

    pro = []
    manager = multiprocessing.Manager()
    res = manager.list()

    inicio = 2
    for i in range(nproces):
        cant = terpro + (1 if i < terext else 0)
        proceso = multiprocessing.Process(target=generaR, args=(inicio, a, cant, res))
        pro.append(proceso)
        proceso.start()
        inicio += a * cant

    for proceso in pro:
        proceso.join()

    resfin = sorted(res)
    print(resfin)

if __name__ == "__main__":
    main()
