## Specification file
# sends a message of new trial specific details, on send

# reward amount
# reward occurance
# pause time
# trial number
# repition number
# force vector
# directions
# distances to force targets

# on init reads in last state file
# when changes saves file for current parameter state.
# sends a message of the appropriate update on send()


# getting yaml data into python
import yaml
with open('filename.yaml') as yamlFile:
  data = yaml.safe_load(yamlFile)


#saving yaml data
with open('filename.yaml') as yamlFile:
  yaml.dump(data, yamlFile)

class Experiment(object):
  def __init__(self, *data, **kwargs):
      for dictionary in data:
          for key in dictionary:
              setattr(self, key, dictionary[key])
      for key in kwargs:
          setattr(self, key, kwargs[key])
  
  def sendParam():
    #send whole self
    pass
    
  def saveExperiment():
    pass

# This calss defines how to update/ change the force thresholds required 
# and     
class ForceParam(Experiment):
  def __init__(self):
    Experiment.__init__(self)

# This class defines the states at which a reward should be given
# as well as how much reward
class RewardParam(Experiment):
  def __init__(self):
    Experiment.__init__(self)

# This class defines the structure of the experiment -> logic and flow through 
# The states  
class ExpFormat(Experiment):
  def __init__(self):
    Experiment.__init__(self)
