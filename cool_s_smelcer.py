import turtle
t = turtle.Turtle()
t.shape("turtle")
t.pencolor("red4")

t.pensize(5)
t.penup()
t.goto(75, 100)
t.pendown()
t.right(90)
t.forward(75)

t.penup()
t.goto(0, 100)
t.pendown()
t.forward(75)

t.penup()
t.goto(-75, 100)
t.pendown()
t.forward(75)

t.penup()
t.goto(-75, -100)
t.pendown()
t.right(180)
t.forward(75)

t.penup()
t.goto(0, -100)
t.pendown()
t.forward(75)
t.goto(-75, 25)

t.penup()
t.goto(75, -100)
t.pendown()
t.forward(70)
t.goto(0, 25)

t.penup()
t.goto(-75, 100)
t.pendown()
t.goto(0, 200)
t.goto(75, 100)

t.penup()
t.goto(75, -100)
t.pendown()
t.goto(0, -200)
t.goto(-75, -100)

t.penup()
t.goto(-75, -25)
t.pendown()
t.goto(-37, 0)

t.penup()
t.goto(75, 25)
t.pendown()
t.goto(37, 0)

t.hideturtle()
