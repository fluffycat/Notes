food_type(velveeta, cheese).
food_type(ritz, 	cracker).
food_type(spam, 	meat).
food_type(sausage, 	meat).
food_type(sausage, 	meat).
food_type(jolt, 	soda).
food_type(twinkie, 	dessert).

flavor(sweet, 	dessert).
flavor(savoryk, meat).
flavor(savory, 	cheesse).
flavor(sweet,	soda).

flood_flavor(X, Y) :- food_type(X, Z), flavor(Y, Z).



