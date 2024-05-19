import multiprocessing as mp 
import numpy as np 

def integrarR(inicio, fin, npuntos):
   
    paso = (fin - inicio) / npuntos 
    total = 0.0  
    for i in range(npuntos):
        x = inicio + i * paso  
        total += np.sqrt(1 - x * x) * paso  
    return total 

def calculoPI(npuntos, nprocesos):
    
    tampaso = npuntos // nprocesos 
    pool = mp.Pool(processes=nprocesos) 

    
    rangos = [(i * tampaso / npuntos, (i + 1) * tampaso / npuntos, tampaso)
              for i in range(nprocesos)]
    
    resultados = pool.starmap(integrarR, rangos)
    
    stotal = sum(resultados)  
    return 4 * stotal 

if __name__ == "__main__":
    npuntos = 10**7 
    nprocesos = mp.cpu_count()  
    
    pi = calculoPI(npuntos, nprocesos)  
    print(f"Calculo de Pi: {pi}")  
