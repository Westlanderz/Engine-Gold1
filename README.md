# Engine-Gold1

This is an ECS made for the gold 1 achievement for Optimisation. Mainly written by Noah Knegt, 19066066, and parts fixed by Dennis Bonke.
The application opens a windows that will exit if you press the esc key. Then due to the OpenGL part not fully working(yet) I added console logs to see the update of systems working.
The system makes 10 entities by default and if you edit the MAX_ENTITIES variable in the Types.hpp file you can change that amount.
Each log for the update of the systems will be printed in the console. The format for the physics system working with gravity is the entity id and then the position in x, y and z. Only the y changes with the gravity.
For the renderer system its only the entity id.

I wish to fix the rendering system later but that is only a QoL thing and the console logs show the system working already.
