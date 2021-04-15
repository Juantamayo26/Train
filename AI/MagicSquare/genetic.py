import random 
import numpy as np
from statistics import plot

pressure = 30
mutation_chance = 0.4

def compare(x, y):
  return x[0] - y[0]

def individual():
  matrix = np.array(random.sample(range(1,N*N+1), N*N), dtype=int)
  return matrix

def createPopulation(quantity):
  return [individual() for i in range(quantity)]

def fitness(individual):
  fitness = diagonal1 = diagonal2 = 0
  cloneIndi = individual.reshape((N,N))
  for i in range(0, N):
    fitness+= abs(magic_num - sum(cloneIndi[i, :]))
    diagonal1+= cloneIndi[i,i]
    diagonal2+= cloneIndi[N-i-1, i]
    fitness+= abs(magic_num - sum(cloneIndi[:, i]))
  fitness+= abs(magic_num - diagonal1)
  fitness+= abs(magic_num - diagonal2)
  plot_fitness.append(fitness)
  plot(plot_fitness)
  if(fitness == 0):
    print(cloneIndi)
  return -fitness

def selection_and_reproduction(population):
  puntuados = [ (fitness(i), i) for i in population] 
  #puntuados = [i[1] for i in sorted(puntuados)] 
  puntuados = [i[1] for i in sorted(puntuados, key=lambda a: a[0])] #Ordena los pares ordenados y se queda solo con el array de valores

  population = puntuados
  
  selected =  puntuados[(len(puntuados)-pressure):]

  for i in range(len(population)-pressure):
    punto = random.randint(1,N*N-1) 
    padre = random.sample(selected, 2)  
    aux = []
    for j in padre[0]:
      if j not in padre[1][punto:]:
        aux.append(j)
    aux[punto:] = padre[1][punto:]
    aux = np.array(aux)
    #print("PADRE 0")
    #print(padre[0])
    #print("PADRE 1")
    #print(padre[1][punto:])
    #print("HIJO")
    #print(aux)
    #population[i][:punto] = padre[0][:punto] 
    #population[i][punto:] = padre[1][punto:]
    population[i] = aux
  return population

def mutation(population):
  #prob = random.random()
  #if(probability >= prob):
  for i in range(len(population)-pressure):
    if random.random() <= mutation_chance:
      point1 = random.randint(0,N*N-1) 
      point2 = random.randint(0,N*N-1) 
      while point1 == point2:
        point1 = random.randint(0,N*N-1)
      aux = population[i][point1]
      population[i][point1] = population[i][point2]
      population[i][point2] = aux 
  return population

def mutation2(population):
  #prob = random.random()
  #if(probability >= prob):
  for i in range(len(population)-pressure):
    if random.random() <= mutation_chance:
      point1 = random.randint(0,N*N-1) 
      point2 = random.randint(0,N*N-1) 
      while point1 == point2:
        point1 = random.randint(0,N*N-1)
      value = population[i][point1]
      population[i] = np.delete(population[i], point1)
      population[i] = np.insert(population[i], point2, value)
  return population

N = int(input("Digite el N: "))
magic_num = int(N*(N*N + 1)/2)
population = createPopulation(100)
plot_fitness = []
for i in range(1000):
  print("Generacion: ", i+1)
  population = selection_and_reproduction(population)
  population = mutation(population)
