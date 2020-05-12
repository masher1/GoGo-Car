# GoGo-Car
Control a car with the IR remote control which avoids obstacles automatically

# Inspiration
Just like many children, we have grown up with remote control cars and as engineers, it was time for us to re-imagine the way RC cars work.

# What it does
We used Arduino to code a microcontroller which waits for a signal from the IR remote and then follows the direction depending on which direction we have chosen. Then, while it is riding it also keeps the ultrasonic sensor running and continuously measuring how far the objects in front of it are. If they get closer than 10 cm it will notify the user through the buzzer and then turn 50 degrees to the right and keep scanning and going if we tell it to.

# How we built it
We used electrical components that came with a starter kit and then placed them onto a frame and attached wheels from another car onto them. We then experimented with different speeds and extra components like batteries and sensors to see the best possible combination to make the car run efficiently and reliably.

# Challenges we ran into
Limited hardware was available to us. Also, the motors have refused to follow the code and didn't turn around. Because of the motor we used for this project, we were not able to make it go back so instead when a user requests the car to go back it will make 180 degrees turn and then go forward in that direction.

# Accomplishments that we're proud of
We were able to make the wheels turn and have the ultrasonic sensor recognize at what distance it should start signaling about a potential accident.

# What we learned
This was a fun experience to learn how to balance time management and efficiency. We also learned that hardware might just not work all the time so you have to be prepared with replacements.

# What's next for GoGo Car
Putting all the components under one roof and maybe one day you will see it in the toy store.
