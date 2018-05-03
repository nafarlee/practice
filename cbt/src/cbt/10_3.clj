(ns cbt.10-3)

(def max-health 40)

(def player-one (ref {:health 15
                      :inventory {:healing-potion 0}}))

(def player-two (ref {:health 40
                      :inventory {:healing-potion 1}}))

(defn give-healing-potion
  []
  (dosync
    (alter player-two update-in [:inventory :healing-potion] dec)
    (alter player-one update-in [:inventory :healing-potion] inc)
    (alter player-one update-in [:inventory :healing-potion] dec)
    (alter player-one assoc-in [:health] 40)))
