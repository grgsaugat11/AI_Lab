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

#Queries
a. likes cake but not pizza
likes(X,cake),\+likes(X,pizza).

b. does not like sushi
likes(X,_),\+likes(X,sushi).

c. how many people like pizza
findall(X,likes(X,pizza),List),length(List,Count).

d. uniquefood list
setof(Food, X^likes(X,Food),UniqueFood).

e. pairs of people who like same food
setof((Person1,Person2,Food),
|    (likes(Person1,Food),likes(Person2,Food),Person1\=Person2),
|    Pairs).
