import matplotlib.pyplot as plt
from matplotlib.widgets import Button

plt.ion()

def plot(scores):
  plt.clf()
  plt.title('Statistics')
  plt.xlabel('Games')
  plt.ylabel('Score')
  plt.plot(scores)
  plt.text(len(scores)-1, scores[-1], str(scores[-1]))
  plt.ylim(ymin=0)
  #axnext = plt.axes([0.81, 0.05, 0.1, 0.075])
  #bnext = Button(axnext, 'Next')
  #bnext.on_clicked(plot(scores, mean))
  plt.pause(0.0001)
  plt.show()

