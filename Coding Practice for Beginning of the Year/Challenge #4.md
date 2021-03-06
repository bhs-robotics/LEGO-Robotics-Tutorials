# Challenge #4
## Advanced IF and WHILE Statements

For the fourth challenge, guess what? We are building on the 3rd Challenge! Shocker!

This challenge is going to be a little bit harder. You are going to build a program where the following happens:

 - The UP button on the EV3 Brick causes your "runTime" to be larger.
 - The DOWN button on the EV3 Brick causes your "runTime" to be smaller.
 - The ENTER button on the EV3 Brick will cause your robot to drive forward for the set "runTime" and then backup for the same "runTime." After the ENTER button is clicked and your robot finished driving, the program needs to end.

Good luck and happy coding!

## How to do (Outside the task main())

### 1. Setup your motors like before

### 2. Add the VOIDs for moving the robot forward

### 3. Add the following global variables, meaning in between the VOIDs and the task main()

- forwardSpeed: Constant Int = 100
- runTime: Int = 1

## How to do (Inside the task main())

### 1. Add the following variables

This will control the WHILE statement, allowing us to force the program to end at any given moment.

- programNeedsToRun: Bool = true

### 2. Add a WHILE statement with the parameter "runTime"

### 3. Add a branching IF statement for the following button cases

 - The UP Button
 - The DOWN Button
 - The ENTER Button
 
### 4. Inside the UP case, make the "runTime" variable increase by one
 
The syntax to make a variable increase by one is below. In the example, I am making a variable for what happens on my birthday every year.
 
```
age += 1;
```
This will make the variable "age" add one. Not hard at all!

IMPORTANT: Do not forgot to add the WHILE statement to prevent fallthrough.
 
### 5. In the DOWN case, make the "runTime" variable decrease by one
 
Remember, we can not always minus one. For example, if the variable is currently 1, we don't want to minus one because we don't want our robot to move for zero seconds. Therefore, you must add an IF statement to make sure this won't, or can't, happen. There are many ways to do this, so be creative!

IMPORTANT: Do not forgot to add the WHILE statement to prevent fallthrough.

For reference, these are the operators for when you are comparing two things, like in an IF statement.

- (==) means EQUAL TO

```
if (myAge == yourAge) { }
```

- (!=) means NOT EQUAL TO

```
if (myAge != yourAge) { }
```

- (>) means GREATER THAN

```
if (myAge > yourAge) { }
```

- (<) means LESS THAN

```
if (myAge < yourAge) { }
```

- (>=) means GREATER THAN OR EQUAL TO

```
if (myAge >= yourAge) { }
```

- (<=) means LESS THAN OR EQUAL TO

```
if (myAge <= yourAge) { }
```

### 5. In the ENTER case, make the robot drive forwards for the given time, then backwards for the given time
 
IMPORTANT: Do not forgot to add the WHILE statement to prevent fallthrough. Add this line before the commands to make the robot drive to make it where the robot will move once you have let go of the button.

### 6. After the lines of code for robot motion, stop the program by setting the "programNeedsToRun" variable to false

### 7. Enjoy your OUTSTANDING robot!
