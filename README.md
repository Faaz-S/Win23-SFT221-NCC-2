# Win23-SFT221-NCC-2

### Robin: Everyone should try to use git.

Project for Software testing for Group 2

The overall algorithm of the code for truck agency will

• Follow the route for each of the trucks.• At every square on the route for each truck it will calculate the Euclidean distance to thedestination.

• It will select the minimum Euclidean distance for each of the trucks and then calculate theshortest path from each of those positions to the destination.

• In the event one of the trucks cannot find a path to the destination, that truck will not be usedfor the delivery and one of the other trucks will be used.

• Finally, it will select the truck which has the shortest path from the nearest point on its route tothe destination and attempt to add the package to that truck.

• If that truck cannot hold the package, it will try to put it in the truck that is next closest to thedestination.• If no truck can take the package, it will be placed in storage at the depot until the trucks returnempty and it will be shipped out the next day. It will print the message “Ships tomorrow”.

Our algorithm will run for one day. This means we accept items until all trucks are full or items stoparriving. Once this happens, the trucks will be dispatched but that is not the responsibility of theprogram.

All the program does is:

• Decide which truck the package will be placed in.

• Print out where the truck will deliver the package.

• If the truck needs to divert to deliver the package, you will print the path to divert
