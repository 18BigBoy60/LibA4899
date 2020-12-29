StepperDriver
=====================

Stepper Driver is an Arduino library for the A4988 stepper motor driver media.

Library features:
<ul>
    <li>Two modes of operation: linear movement and rotation control</li>
    <li>Control of the rotation angle of the shaft of the stepper motor</li>
    <li>Support for all possible step splits</li>
    <li>Control of linear movement in relative and absolute coordinate systems</li>
    <li>Setting the current motor position</li>
    <li>Control acceleration of the motor</li>
</ul>

----------------------

### Creating a class object:

    LibA4988 name (step, ms1, ms2, ms3, dir);

#### Parameters:

    step - pin connected to the contact STEP
    ms1 - pin connected to the contact MS1
    ms2 - pin connected to the contact MS2
    ms3 - pin connected to the contact MS3
    dir - pin connected to the contact DIR

----------------------

#### Function:

    setDegree(int degree);

#### Parameter:

    degree - angle of rotation

#### Description:

This function takes as input the angle at which the motor shaft should turn. The angle is set approximately as the driver step does not always allow you to set it exactly. To minimize the error, you can change the pitch splitting. How to change the step, read on.

----------------------

#### Function:

    stepSplit(int s = 1);

#### Parameter:

    s - crushing ratio of step (1/s)

#### Description:

The step splitting factor can be equal to 1, 2, 4, 8, 16. This function sets the driver how many times to split the step. Initially, the crushing is 1 - the step is 1.8 degrees. If we change the coefficient, then 1.8 will be divided by the specified acceptable number.

----------------------

#### Function:

    direction(int n = 1);

#### Parameter:

    n - can be equal to 1 or -1

#### Description:

This function sets the direction of rotation of the shaft. <b>1</b> - clockwise. <b>-1</b> - counterclockwise

----------------------

#### Function:

    goTo(int x_n);

#### Parameter:

    x_n - the value of x that we want to get into

#### Description:

This function allows you to move relative to your current position. X = 1.8 degrees, i.e. one step.

----------------------

#### Function:

    setZeroPosition();

#### Description:

This function makes your current position a reference point. All values about the move are reset to zero.

----------------------

#### Function:

    xNow();

#### Description:

This function returns your current position.

----------------------

#### Function:

    steper();

#### Description:

This function allows you to take one step

----------------------

#### Function:

    setAcceleration(int a);

#### Parameter:

    a - acceleration

#### Description:

This function allows you to change the acceleration. Initially, it is 1. The maximum speed is 1 step in 500 milliseconds. Minimum speed 1 step per 2000 milliseconds.

----------------------

#### Function:

    setSpeed(int speed);

#### Parameter:

    speed - from 500 to 2000

#### Description:

This function allows you to change the rotation speed. Initially it is equal to 2000

----------------------