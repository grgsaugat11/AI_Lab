likes(john,pizza).
likes(mary,ice_cream).
likes(tom,sushi).
likes(jane,pizza).
likes(john,sushi).
likes(mary,cake).
likes(tom,pizza).
likes(jane,cake).

likes_food(Person):- likes(Person,_).
same_food(Person1,Person2):- likes(Person1,Food),likes(Person2,Food),Person1\=Person2.

