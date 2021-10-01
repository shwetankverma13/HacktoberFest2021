# provide any string
def string_splosion(str):
  emp = ""
  for i in range(len(str)):
    emp += str[:i+1]
  return emp
# for "apple" return as: "aapappapplapple"
