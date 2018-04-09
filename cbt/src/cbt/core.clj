(ns cbt.core
  (require [cbt.1-1])
  (require [cbt.1-2])
  (require [cbt.1-3 :refer [dec-maker]])
  (:gen-class))

(defn -main
  [& args]
  (->> 10
       ((dec-maker 9))
       println))
