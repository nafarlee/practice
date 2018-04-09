(ns cbt.core
  (require [cbt.1-1])
  (require [cbt.1-2 :refer [main]])
  (:gen-class))

(defn -main
  [& args]
  (println (main 10)))
