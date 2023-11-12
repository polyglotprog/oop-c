![Object-Oriented Programming in C](/oop-in-c.png)

# Object-Oriented Programming in C
Implementations of Object-Oriented Programming in C. Based on concepts from the
book, [Object-Oriented Programming With ANSI-C], and especially this blogpost:

https://feepingcreature.github.io/oop.html

See [src/demo.c](/src/demo.c).

To run:

```console
$ cd src
$ gcc Object.c Vehicle.c Boat.c Car.c Plane.c demo.c
$ ./a.out
```

Output:
```
Creating Object.
Creating Boat.
Creating Car.
Creating Plane.

*Statically Dispatch on Object*
Object Address: 0x556128120270
Object String:  Object@0x556128120270
Object Hash:    93875772457584

*Dynamically Dispatch on Vehicle*
I am a Boat! I sail in the water.
I am a Car! I drive along the road.
I am a Plane! I fly in the air.

*Car*
Car  Address:    0x5561281202b0
Car  String:     Car[capacity=5, topSpeed=100, numberOfWheels=4]
Car  Hash:       93875772457648
Car  Capacity:   5
Car  Top Speed:  100
Car  # Wheels:   4
Car  Move:
  I am a Car! I drive along the road.

*Clone Car*
Creating Car.

*Car2 (Clone of Car)*
Car2 Address:    0x556128120370
Car2 String:     Car[capacity=5, topSpeed=100, numberOfWheels=4]
Car2 Hash:       93875772457840
Car2 Capacity:   5
Car2 Top Speed:  100
Car2 # Wheels:   4
Car Move:
  I am a Car! I drive along the road.

*Free Allocated Memory*
Destroying Object.
Destroying Boat.
Destroying Car.
Destroying Car.
Destroying Plane.
```

<!-- Links -->
[Object-Oriented Programming With ANSI-C]: https://www.cs.rit.edu/~ats/books/ooc.pdf
