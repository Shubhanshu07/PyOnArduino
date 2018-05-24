def get_US() -> int:
    #   Instead of reading the distance from keyboard we should get the measurement from the actual ultrasonic
    #   sensor
    return int(input('Distance: '))

def set_engine(direction):
    #   Instead of just printing the direction the engines will have, we should actually set it within this function
    if direction == 0:
        print('STOP! ')
    elif direction == 1:
        print('Forward')

# This is the part that should go inside loop
while True:
    if get_US() < 10:
        set_engine(0)
    else:
        set_engine(1)
