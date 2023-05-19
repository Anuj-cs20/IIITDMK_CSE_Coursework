import pytholog as pl

kb = pl.KnowledgeBase("logic")


kb(["child_loves(X) :- child(X), loves(X, santa).",
    "loves(X, santa) :- child(X).",
    "loves(X, Y) :- loves(X, santa), reindeer(Y).",
    "reindeer(rudolph).",
    "has_red_nose(rudolph).",
    "weird(X) :- has_red_nose(X) ; clown(X).",
    "not(clown(X)) :- reindeer(X).",
    "not_loves_scrooge(X) :- scrooge(Y), weird(X), loves(Y, X).",
    "scrooge(scrooge)."])

print(kb.query(pl.Expr("not(child(scrooge))")))
print("So here No means scrooge is not a child")
