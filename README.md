# COS 370 final logic game/game engine
requires SFML

Collider Structure - has variable options to pair a graphical shape with a collider structure
- shape 0 = circle
- shape 1 = square
- x = x position
- y = y poisiton
- radius = radius or width
- radius2 = heighth
- isStatic = wether the object moves or not
- velocity_y
- velocity_x
- acceleration_y
- acceleration_x
- mass = how much gravity effects the collider
- material = how much force the collider gives off

do_collisions(Collider *colliders[], int size) - pass an array of colliders and it's size, runs all collidiables against eachother

Collision - true or false statement on if the collider has collided with something

Collisions - applies force to the colliding objects

Velocity_update - updates the velocity of the called collider

setPostions(collider.x,collidery) - is required to change positions after all physics calls.
