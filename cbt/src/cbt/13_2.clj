(ns cbt.13-2)

(defmulti full-moon-behavior
  (fn [were-creature]
    (:were-type were-creature)))

(defprotocol WereCreature
  (full-moon-behavior [x]))

(defrecord WereSimmons [name]
  WereCreature
  (full-moon-behavior [x]
    (str name " will dissapear without a trace in 2014")))

(full-moon-behavior (->WereSimmons "Guy"))
