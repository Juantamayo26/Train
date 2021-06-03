import tsplib95
import io, requests
import random
import sys
import numpy as np

class TSPProblem():
  def __init__(self, graph):
    '''
    Constructor de clases Problema del Agente Viajero
    '''
    self.graph = graph
    self.tour  = list(graph.nodes)

  def best_state(self, states):
    '''
    Funcion que retorna el mejor de los estados dados
    '''
    bestRouteLength = self.value(states[0])
    bestState = states[0]
    for state in states:
      currentRouteLength = self.value(state)
      if currentRouteLength < bestRouteLength:
        bestRouteLength = currentRouteLength
        bestState = state
    return bestState, bestRouteLength

  def get_states(self, state):
    '''
    Retorna una lista de estados, esto lo hago con el fin para tenga mas diversidad y asi luego escoger el mejor entre varios
    Cambio de un punto a otro generando varios estados
    '''
    states = []
    for i in range(len(state)):
      for j in range(i+1, len(state)):
        neighbour = state.copy()
        neighbour[i] = state[j]
        neighbour[j] = state[i]
        states.append(neighbour)
    return states 

  def value(self, state):
    '''
    retorna la longitud del recorrido
    '''
    return self.__tour_length(state)
      
  def best_val(self, i, j):
    return self.graph.edges[i,j]['weight']

  def NearestNeighbor(self, Graph, label):
    length = len(Graph)
    vertices = []
    H = []
    s = 0
    v = s
    while v not in vertices:
        w = 10000003
        index = -1
        for i in range(length):
            if i not in vertices and i != v and Graph[v][i] < w:
                w = Graph[v][i]
                index = i
        if w == 10000003 or index == -1:
            break
        H.append((label[v], label[index]))
        vertices.append(v)
        v = index
    return vertices

  def generate_best_state(self):
    '''
    Retorna el mejor estado
    '''
    state = []
    for i in range(0,len(self.tour)):
      aux = []
      for j in range(0, len(self.tour)):
        aux.append(self.best_val(i+1,j+1))
      state.append(aux)

    aux2 = self.NearestNeighbor(state, self.tour)
    for i in range(len(aux2)):
      aux2[i]+=1
    print(aux2)
    print(len(aux2))
    return random.sample(self.tour, len(self.tour))

  def __tour_length(self, state):
    '''
    Retorna la longitud de state o la distancia total del recorrido 
    '''
    return sum(self.graph.edges[state[i-1], state[i]]['weight'] 
               for i in range(len(state)))

  def hillClimbing(self):
    currentSolution = self.generate_best_state() #Genero un recorrido aleatorio
    currentRouteLength = self.value(currentSolution) #Evaluo cuanto es el valor del recorrido
    neighbors = self.get_states(currentSolution) #Genero un arreglo de diversidades del recorrido
    bestNeigbour, bestNeigbourRouteLength = self.best_state(neighbors) #Escojo el mejor de del arreglo de las diversidades y evaluo su recorrido

    while bestNeigbourRouteLength < currentRouteLength: # Hallo el maximo local
      currentSolution = bestNeigbour
      currentRouteLength = bestNeigbourRouteLength
      neighbors = self.get_states(currentSolution)
      bestNeigbour, bestNeigbourRouteLength = self.best_state(neighbors)

    return currentSolution, currentRouteLength


url = "http://www.math.uwaterloo.ca/tsp/world/wi29.tsp"
r= requests.get(url)
b= io.StringIO(r.text)
wi29 = tsplib95.read(b)
ESTE = wi29.get_graph()
problem = TSPProblem(ESTE)
print(problem.hillClimbing())
