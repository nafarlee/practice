(ns cbt.core
  (require [cbt.1-1])
  (require [cbt.1-2])
  (require [cbt.1-3])
  (require [cbt.1-4 :refer [mapset]])
  (:gen-class))

(defn -main
  [& args]
  (println
   (mapset inc
           [1 1 2 2])))
