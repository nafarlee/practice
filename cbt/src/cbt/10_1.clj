(ns cbt.10-1)

(defn main []
  (def a (atom 0))
  (swap! a inc)
  (swap! a * 2)
  (swap! a * 3)
  (swap! a * 4)
  @a)
