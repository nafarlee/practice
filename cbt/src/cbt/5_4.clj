(ns cbt.5-4)

(-> {:name "Nicholas" :stats {:intelligence 1}}
    (update-in [:stats :intelligence] dec))
