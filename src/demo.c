#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "dispatch.h"
#include "Boat.h"
#include "Car.h"
#include "Cloneable.h"
#include "Object.h"
#include "Plane.h"
#include "Vehicle.h"

int main() {
  Object *object = Object_new();
  Boat *boat = Boat_new(4, 30);
  Car *car = Car_new(5, 120, 4);
  Plane *plane = Plane_new(2, 200);

  /*
   * Statically dispatch methods on object.
   */
  puts("\n*Statically Dispatch on Object*");
  printf("Object Address: %p\n",  object);
  printf("Object String:  %s\n",  Object_toString(object));
  printf("Object Hash:    %lu\n", Object_hashCode(object));

  /*
   * Dynamically dispatch on different vehicle types.
   */
  Vehicle *vehicles[3] = {
    (Vehicle *)boat,
    (Vehicle *)car,
    (Vehicle *)plane,
  };

  puts("\n*Dynamically Dispatch on Vehicle*");
  for (int i = 0; i < 3; i++) {
    Vehicle *vehicle = vehicles[i];
    vehicle->vtable->move(vehicle);
  }

  /*
   * We could use static dispatch here but let's do dynamic dispatch so we can
   * compare the syntax with what follows.
   */
  puts("\n*Car*");
  printf("Car  Address:    %p\n",  car);
  printf("Car  String:     %s\n",  car->vtable->toString(car));
  printf("Car  Hash:       %lu\n", car->vtable->hashCode(car));
  printf("Car  Capacity:   %d\n",  car->vtable->getCapacity(car));
  printf("Car  Top Speed:  %d\n",  car->vtable->getTopSpeed(car));
  printf("Car  # Wheels:   %d\n",  car->vtable->getNumberOfWheels(car));
  printf("Car  Move:\n    ");
  car->vtable->move(car);

  /*
   * Create car2 by cloning car. First convert car to a Cloneable interface
   * pointer. The commented out lines show how to do the pointer conversions
   * manually. Instead, we use macros from dispatch.h to simplify this.
   * Technically, converting to an interface pointer is unnecessary because we
   * could just use `car->vtable->clone(car)` or `Car_clone`. However, this
   * illustrates how to call an interface when you don't know the actual type
   * until runtime.
   */
  puts("\n*Clone Car*");
  // Cloneable *cloneable = (Cloneable *)(&car->vtableCloneable);
  // Car *car2 = (Car *)cloneable->vtable
  //     ->clone((void *)cloneable - cloneable->vtable->offset);
  Cloneable *cloneable = toInterface(Cloneable, car);
  Car *car2 = (Car *)dispatch(cloneable, clone); // much simpler

  /*
   * Call the same Car methods on car2. This time, use macros from dispatch.h
   * to simplify the syntax. Every outputted result is the same because car2 is
   * a clone of car1 - except for its address.
   */
  puts("\n*Car2 (Clone of Car)*");
  printf("Car2 Address:    %p\n",  car2);
  printf("Car2 String:     %s\n",  dispatch(car2, toString));
  printf("Car2 Hash:       %lu\n", dispatch(car2, hashCode));
  printf("Car2 Capacity:   %d\n",  dispatch(car2, getCapacity));
  printf("Car2 Top Speed:  %d\n",  dispatch(car2, getTopSpeed));
  printf("Car2 # Wheels:   %d\n",  dispatch(car2, getNumberOfWheels));
  printf("Car Move:\n    ");
  dispatch(car2, move);

  /*
   * This is C so we need to free allocated memory.
   */
  puts("\n*Free Allocated Memory*");
  Object_delete(object);
  Boat_delete(boat);
  Car_delete(car);
  Car_delete(car2);
  Plane_delete(plane);

  return 0;
}
